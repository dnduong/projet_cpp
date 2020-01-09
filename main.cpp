#include "diams.hpp"
#include "teupor.hpp"
#include "reumu.hpp"
#include "geurchar.hpp"
#include "commun.hpp"
#include "oueurj.hpp"
#include "streumon.hpp"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<int> longueur;
vector<int> largeur;
void init_vector(vector<vector<element*>> & V,int t){
	for(int i = 0; i<t; i++){
		V.push_back(vector<element*>());
	}
}

bool importFichier(vector<vector<element*>> & R, vector<vector<element*>> & D, vector<vector<element*>> & G, vector<vector<element*>> & P,vector<vector<element*>> &S, oueurj &J){
	string fn;
	cout<<"Entrer le nom du fichier"<<endl;
	cin>>fn;
	fstream file;
	file.open(fn,ios::in);
	if(!file){
		cout<<"Création échouée"<<endl;
		return false;
	}
	int nivC = 0;
	char c;
	int type;
	bool in_x;
	string x,y;
	while(file.get(c)){
		if (c == 'D'){
			type = 1;
		}else if (c == 'G'){
			type = 2;
		}else if (c == 'R'){
			type = 3;
		}else if (c == 'T'){
			type = 4;
		}else if (c == 'M'){
			type = 5;
		}else if (c == 'S'){
			nivC++;
			type = 6;
		}else if (c == 'L'){
			type = 7;
		}else if (c == ','){
			if(type == 1){
				D.at(nivC-1).push_back(new diams(stoi(x),stoi(y)));
				x = "";
				y = "";
			}else if(type == 2){
				G.at(nivC-1).push_back(new geurchar(stoi(x),stoi(y)));
				x = "";
				y = "";
			}else if(type == 3){
				R.at(nivC-1).push_back(new reumu(stoi(x),stoi(y)));
				x = "";
				y = "";
			}else if(type == 4){
				P.at(nivC-1).push_back(new teupor(stoi(x),stoi(y)));
				x = "";
				y = "";
			}else if(type == 5){
				S.at(nivC-1).push_back(new streumon(stoi(x),stoi(y)));
				x = "";
				y = "";
			}else if(type ==6){
				longueur.push_back(stoi(x));
				largeur.push_back(stoi(y));
				x="";
				y="";
			}else{
				int nivTotal = stoi(x);
				J.setNivTotal(nivTotal);
				init_vector(R,nivTotal);
				init_vector(D,nivTotal);
				init_vector(G,nivTotal);
				init_vector(P,nivTotal);
				init_vector(S,nivTotal);
				x="";
				y="";
			}
		}else if (c == 'x'){
			in_x = true;
		}else if (c == 'y'){
			in_x = false;
		}else{
			if(in_x){
				x+=c;
			}else{
				y+=c;
			}
		}
	}
	file.close();
	return true;
}

void iterVector(vector<vector<char>> &T,vector<element*> & V){
	for (auto v : V){
		T[v->getY()][v->getX()]= v->graphic();
	}
}

void clear(vector<vector<char>> &T){
	clear();
	for(unsigned int i = 0; i< T.size(); i++){
		for (unsigned int j = 0; j< T[i].size(); j++){
			T[i][j]=32;
		}
	}
}

void update(vector<vector<char>> &T, vector<element*> & R, vector<element*> & D, vector<element*> & G, vector<element*> & P, vector<element*> &S,oueurj &J){
	clear(T);
	T[J.getY()][J.getX()] = J.graphic();
	iterVector(T,R);
	iterVector(T,D);
	iterVector(T,G);
	iterVector(T,P);
	iterVector(T,S);
}


void moveS(vector<vector<char>> &T, vector<element*> & R, vector<element*> & D, vector<element*> & G, vector<element*> & P, vector<element*> &S,oueurj &J){
	for (auto s : S){
		dynamic_cast<streumon *>(s)->randomMove(T,S,J);
		update(T,R,D,G,P,S,J);
	}
}

void draw(vector<vector<char>> & T,oueurj &J,vector<element*> & S){
	for(unsigned int i = 0; i< T.size(); i++){
		for (unsigned int j = 0; j< T[i].size(); j++){
			mvprintw(i,j,"%c",T[i][j]);
		}
	}
	int nivC = J.getNivCourant() - 1;
	mvprintw(0,largeur.at(nivC)+10,"Diams : %d",J.getNbDiams());
	mvprintw(1,largeur.at(nivC)+10,"Téléports : %d",J.getNbTeles());
	mvprintw(2,largeur.at(nivC)+10,"Niveau : %d/%d",nivC+1,J.getNivTotal());
	mvprintw(3,largeur.at(nivC)+10,"Vie : %d",J.getNbVies());
	mvprintw(4,largeur.at(nivC)+10,"Streumons : %d",S.size());
	
}

int main(){
	char c;
	vector<vector<char>> T;
	vector<vector<element*>> R;
	vector<vector<element*>> D;
	vector<vector<element*>> G;
	vector<vector<element*>> P;
	vector<vector<element*>> S;
	oueurj J(0,0);
	int nivC;
	if(importFichier(R,D,G,P,S,J)){
		while(!(J.estGagne() || J.estPerdu())){
				nivC = J.getNivCourant() - 1;
				init_plateau(T,longueur.at(nivC),largeur.at(nivC));
				update(T,R.at(nivC),D.at(nivC),G.at(nivC),P.at(nivC),S.at(nivC),J);
				J.reset(T);
				initscr();
				cbreak();
				noecho();
				update(T,R.at(nivC),D.at(nivC),G.at(nivC),P.at(nivC),S.at(nivC),J);
				draw(T,J,S.at(nivC));
				while(!J.estFini() && !J.estPerdu()){
					c = getch();
					if(J.keyboard_control(c,T,R.at(nivC),D.at(nivC),G.at(nivC),P.at(nivC),S.at(nivC))){
						update(T,R.at(nivC),D.at(nivC),G.at(nivC),P.at(nivC),S.at(nivC),J);
						moveS(T,R.at(nivC),D.at(nivC),G.at(nivC),P.at(nivC),S.at(nivC),J);
						draw(T,J,S.at(nivC));
					}
				}
				clear();
				endwin();
				T.clear();
		}	
	}		
	return 0;
}
