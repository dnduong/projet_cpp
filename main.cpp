#include "diams.hpp"
#include "teupor.hpp"
#include "reumu.hpp"
#include "geurchar.hpp"
#include "commun.hpp"
#include "oueurj.hpp"
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int longueur;
int largeur;

bool importFichier(vector<element*> & R, vector<element*> & D, vector<element*> & G, vector<element*> & P){
	string fn;
	cout<<"Entrer le nom du fichier"<<endl;
	cin>>fn;
	fstream file;
	file.open(fn,ios::in);
	if(!file){
		cout<<"Création échouée"<<endl;
		return false;
	}
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
		}else if (c == 'S'){
			type = 5;
		}else if (c == ','){
			if(type == 1){
				D.push_back(new diams(stoi(x),stoi(y)));
				x = "";
				y = "";
			}else if(type == 2){
				G.push_back(new geurchar(stoi(x),stoi(y)));
				x = "";
				y = "";
			}else if(type == 3){
				R.push_back(new reumu(stoi(x),stoi(y)));
				x = "";
				y = "";
			}else if(type == 4){
				P.push_back(new teupor(stoi(x),stoi(y)));
				x = "";
				y = "";
			}else{
				longueur = stoi(x);
				largeur = stoi(y);
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

void update(vector<vector<char>> &T, vector<element*> & R, vector<element*> & D, vector<element*> & G, vector<element*> & P, oueurj &J){
	T[J.getY()][J.getX()] = J.graphic();
	iterVector(T,R);
	iterVector(T,D);
	iterVector(T,G);
	iterVector(T,P);
}

void clear(vector<vector<char>> &T){
	clear();
	for(unsigned int i = 0; i< T.size(); i++){
		for (unsigned int j = 0; j< T[i].size(); j++){
			T[i][j]='\0';
		}
	}
}

void draw(vector<vector<char>> & T,oueurj &J){
	for(unsigned int i = 0; i< T.size(); i++){
		for (unsigned int j = 0; j< T[i].size(); j++){
			mvprintw(i,j,"%c",T[i][j]);
		}
	}

	mvprintw(0,largeur+5,"Diams : %d",J.getNbDiams());
	mvprintw(1,largeur+5,"Téléportations : %d",J.getNbTeles());
}


void clear(vector<vector<char>> &T, vector<element*> & R, vector<element*> & D, vector<element*> & G, vector<element*> & P, oueurj &J){
	T.clear();
	R.clear();
	D.clear();
	G.clear();
	P.clear();
}
int main(){
	char c;
	vector<vector<char>> T;
	vector<element*> R;
	vector<element*> D;
	vector<element*> G;
	vector<element*> P;
	do{
		oueurj J(5,5);
		if(importFichier(R,D,G,P)){
			init_plateau(T,longueur,largeur);
			initscr();
			cbreak();
			noecho();
			update(T,R,D,G,P,J);
			draw(T,J);
			while(!J.estGagner()){
				c = getch();
				if(J.keyboard_control(c,T,R,D,G,P)){
					clear(T);
					update(T,R,D,G,P,J);
					draw(T,J);
				}
			}
			clear();
			endwin();
			clear(T,R,D,G,P,J);
		}		
	}while(1);
	return 0;
}
