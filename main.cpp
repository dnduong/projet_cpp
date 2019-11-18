#include "element.hpp"
#include "diams.hpp"
#include "teupor.hpp"
#include "reumu.hpp"
#include "geurchar.hpp"
#include "mobile.hpp"
#include <vector>
#include "commun.hpp"
#include <string>
#include <fstream>
using namespace std;

void importFichier(char T[LONGUEUR][LARGEUR], vector<reumu> & R, vector<diams> & D, vector<geurchar> & G, vector<teupor> & P){
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

void init_joueur(mobile & J,char T[LONGUEUR][LARGEUR]){
	T[J.getX()][J.getY()] = 'J';
}

void vectorToTable(char T[LONGUEUR][LARGEUR], vector<reumu> & R, vector<diams> & D, vector<geurchar> & G, vector<teupor> & P){
	for(int i = 0; (unsigned)i< D.size();i++){
		T[D.at(i).getY()][D.at(i).getX()]='$';
	}
	for(int i = 0; (unsigned)i< R.size();i++){
		T[R.at(i).getY()][R.at(i).getX()]='X';
	}
	for(int i = 0; (unsigned)i< G.size();i++){
		T[G.at(i).getY()][G.at(i).getX()]='*';
	}	
	for(int i = 0; (unsigned)i< P.size();i++){
		T[P.at(i).getY()][P.at(i).getX()]='-';
	}
}

void move(mobile & J, char & c,char T[LONGUEUR][LARGEUR]){
	switch(c){
		case 'q' :
			J.gauche(T);
			break;
		case 'd' :
			J.droite(T);
			break;
		case 'z':
			J.haut(T);
			break;
		case 's':
			J.bas(T);
			break;
		case 'a':
			J.nord_ouest(T);
			break;
		case 'e':
			J.nord_est(T);
			break;
		case 'w':
			J.sud_ouest(T);
			break;
		case 'c':
			J.sud_est(T);
			break;
		default:
			break;
	}
	
}

int main(){
	char T[LONGUEUR][LARGEUR];
	vector<reumu> R;
	vector<diams> D;
	vector<geurchar> G;
	vector<teupor> P;
	init_plateau(T);
	importFichier(T,R,D,G,P);
	vectorToTable(T,R,D,G,P);
	mobile J(5,5);
	init_joueur(J,T);
	draw(T);
	while(1){
		char c;
		cin>>c;
		move(J,c,T);
		draw(T);
	}
	return 0;
}
