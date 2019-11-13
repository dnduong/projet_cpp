#include "element.hpp"
#include "diams.hpp"
#include "teupor.hpp"
#include "reumu.hpp"
#include "geurchar.hpp"
#include "mobile.hpp"
#include "commun.hpp"
#include <vector>
#include <string>
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
	return 0;
}