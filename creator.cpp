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
#include <cctype>
using namespace std;

int longueur;
int largeur;

bool my_isdigit(string & c){
	for(unsigned int i = 0; i < c.size(); i++){
		if(!isdigit(c[i]))
			return false;
	}
	return true;
}

void init(vector<vector<char>> & T, char ch){
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
		if(my_isdigit(c)){
			int a = stoi(c);
			cout<<"Y = ";
			cin>>c;
			if(my_isdigit(c)){
				int b = stoi(c);
				if(0<=a && 0<=b && a<largeur && b <longueur){
					if(T[b][a] == 'X' && ch == '-'){
					T[b][a]= ch;
					}
					if(T[b][a] == '\0' && ch != '-'){
						T[b][a]= ch;
					}
					draw(T);
				}else{
					cout<<"Cordonnées invalide"<<endl;
				}
			}
		}	
	}
}

void codage(vector<element> &V, fstream & file){
	for (auto v: V){
		file<<'x';
		file<<v.getX();
		file<<'y';
		file<<v.getY();
		file<<',';
	}
}

void creationFichier(vector<element> & R, vector<element> & D, vector<element> & G, vector<element> & P){
	string fn;
	cout<<"Entrer le nom du fichier"<<endl;
	cin>>fn;
	fstream file;
	file.open(fn,ios::out);
	if(!file){
		cout<<"Création échouée"<<endl;
		return;
	}
	file<<'S';
	file<<'x';
	file<<longueur;
	file<<'y';
	file<<largeur;
	file<<',';
	file<<'D';
	codage(D,file);
	file<<'R';
	codage(R,file);
	file<<'G';
	codage(G,file);
	file<<'T';
	codage(P,file);
	file.close();
}

void tableToVector(vector<vector<char>> &T, vector<element> & R, vector<element> & D, vector<element> & G, vector<element> & P){
	for(unsigned int i = 0; i< T.size(); i++){
		for(unsigned int j = 0; j< T.at(i).size(); j++){
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

void init_reumu(vector<vector<char>> & T){
	for (int i = 0; i < longueur; i++){
		T[i][largeur-1]='X';
		T[i][0]='X';
	}
	for (int i = 1; i < largeur-1; i++){
		T[longueur-1][i]='X';
		T[0][i]='X';
	}
	draw(T);
}

int enter_digit(string & c){
	cin>>c;
	while(!my_isdigit(c)){
		cin>>c;
	}
	return stoi(c);
}

void init_plateau_creator(vector<vector<char>> & T){
	string c;
	cout<<"Entrer la taille du tableau"<<endl;
	cout<<"Longueur : ";
	longueur = enter_digit(c);
	cout<<longueur<<endl;
	cout<<"Largeur : ";
	largeur = enter_digit(c);
	cout<<largeur<<endl;
	init_plateau(T,longueur,largeur);
}

int main(){
	vector<vector<char>> T;
	vector<element> R;
	vector<element> D;
	vector<element> G;
	vector<element> P;
	init_plateau_creator(T);
	init_reumu(T);
	init(T,'-');
	init(T,'$');
	init(T,'X');
	init(T,'*');
	tableToVector(T,R,D,G,P);
	creationFichier(R,D,G,P);
	return 0;
}	