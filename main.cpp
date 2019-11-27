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

void importFichier(vector<element> & R, vector<element> & D, vector<element> & G, vector<element> & P){
	string fn;
	cout<<"Entrer le nom du fichier"<<endl;
	cin>>fn;
	fstream file;
	file.open(fn,ios::in);
	if(!file){
		cout<<"Création échouée"<<endl;
		return;
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
				D.push_back(diams(stoi(x),stoi(y)));
				x = "";
				y = "";
			}else if(type == 2){
				G.push_back(geurchar(stoi(x),stoi(y)));
				x = "";
				y = "";
			}else if(type == 3){
				R.push_back(reumu(stoi(x),stoi(y)));
				x = "";
				y = "";
			}else if(type == 4){
				P.push_back(teupor(stoi(x),stoi(y)));
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
}

void iterVector(vector<vector<char>> &T,vector<element> & V,char c){
	for (auto v : V){
		T[v.getY()][v.getX()]=c;
	}
}

void iterVectorP(vector<vector<char>> &T,vector<element> &P){
	for(unsigned int i = 0; i< P.size(); i++){
		teupor * p = static_cast<teupor *>(&(P[i]));
		if(p->estOuvert()){
			T[p->getY()][p->getX()]='+';
		}else{
			T[p->getY()][p->getX()]='-';
		}
	}
}

void update(vector<vector<char>> &T, vector<element> & R, vector<element> & D, vector<element> & G, vector<element> & P, oueurj &J){
	T[J.getY()][J.getX()] = 'J';
	iterVector(T,R,'X');
	iterVector(T,D,'$');
	iterVector(T,G,'*');
	iterVectorP(T,P);
}

int main(){
	char c;
	vector<vector<char>> T;
	vector<element> R;
	vector<element> D;
	vector<element> G;
	vector<element> P;
	oueurj J(5,5);
	importFichier(R,D,G,P);
	init_plateau(T,longueur,largeur);
	update(T,R,D,G,P,J);
	draw(T);
	while(1){
		cin>>c;
		if(J.keyboard_control(c,T,R,D,G,P)){
			clear(T);
			update(T,R,D,G,P,J);
		}
		draw(T);
	}
	return 0;
}
