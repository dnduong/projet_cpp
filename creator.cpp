#include "element.hpp"
#include "diams.hpp"
#include "teupor.hpp"
#include "reumu.hpp"
#include "geurchar.hpp"
#include "mobile.hpp"
#include "commun.hpp"
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void init_reumu(char T[LONGUEUR][LARGEUR]){
	for (int i = 0; i < LONGUEUR; i++){
		T[i][LARGEUR-1]='X';
		T[i][0]='X';
	}
	for (int i = 1; i < LARGEUR-1; i++){
		T[LONGUEUR-1][i]='X';
		T[0][i]='X';
	}
	draw(T);
}

void init(char T[LONGUEUR][LARGEUR], char ch){
	string d;
	string c;
	switch(ch){
		case '$' : 
			d = "diams";
			break;
		case 'X' :
			d = "murs";
			break;
		case '*' :
			d = "geurchar";
			break;
		case '-' : 
			d = "teupor";
			break;
		default :
			break;
	}
	while (c != "done"){
		cout<<"Ajouter des " +d+"!! (Si fini, taper done)"<<endl;
		cout<<"X = ";
		cin>>c;
		if(c != "done"){
			int a = stoi(c);
			cout<<"Y = ";
			cin>>c;
			int b = stoi(c);
			if(T[b][a] == 'X' && ch == '-'){
				T[b][a]= ch;
			}
			if(T[b][a] == '\0' && ch != '-'){
				T[b][a]= ch;
			}
			draw(T);
		}	
	}
}

void tableToVector(char T[LONGUEUR][LARGEUR], vector<reumu> & R, vector<diams> & D, vector<geurchar> & G, vector<teupor> & P){
	for(int i = 0; i<LONGUEUR; i++){
		for(int j = 0; j<LARGEUR; j++){
			if(T[i][j] == 'X'){
				R.push_back(reumu(j,i));
			}else if(T[i][j] == '$'){
				D.push_back(diams(j,i));
			}else if(T[i][j] == '*'){
				G.push_back(geurchar(j,i));
			}else if(T[i][j] == '-'){
				P.push_back(teupor(j,i));
			}
		}
	}
}

void creationFichier(vector<reumu> & R, vector<diams> & D, vector<geurchar> & G, vector<teupor> & P){
	string fn;
	cout<<"Entrer le nom du fichier"<<endl;
	cin>>fn;
	fstream file;
	file.open(fn,ios::out);
	if(!file){
		cout<<"Création échouée"<<endl;
		return;
	}
	file<<'D';
	for(int i = 0; (unsigned)i< D.size();i++){
		file<<'x';
		file<<D.at(i).getX();
		file<<'y';
		file<<D.at(i).getY();
		file<<',';

	}
	file<<'R';
	for(int i = 0; (unsigned)i< R.size();i++){
		file<<'x';
		file<<R.at(i).getX();
		file<<'y';
		file<<R.at(i).getY();
		file<<',';
	}
	file<<'G';
	for(int i = 0; (unsigned)i< G.size();i++){
		file<<'x';
		file<<G.at(i).getX();
		file<<'y';
		file<<G.at(i).getY();
		file<<',';
	}	
	file<<'T';
	for(int i = 0; (unsigned)i< P.size();i++){
		file<<'x';
		file<<P.at(i).getX();
		file<<'y';
		file<<P.at(i).getY();
		file<<',';
	}
	file.close();
}

int main(){
	char T[LONGUEUR][LARGEUR];
	vector<reumu> R;
	vector<diams> D;
	vector<geurchar> G;
	vector<teupor> P;
	init_plateau(T);
	init_reumu(T);
	init(T,'-');
	init(T,'$');
	init(T,'X');
	init(T,'*');
	tableToVector(T,R,D,G,P);
	creationFichier(R,D,G,P);
	return 0;
}