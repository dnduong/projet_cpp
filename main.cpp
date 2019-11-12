#include "element.hpp"
#include "diams.hpp"
#include "teupor.hpp"
#include "reumu.hpp"
#include "geurchar.hpp"
#include "mobile.hpp"
#include <vector>

using namespace std;

void init_plateau(char T[LONGUEUR][LARGEUR]){
	for (int i = 0; i< LONGUEUR; i++){
		for (int j = 0; j< LARGEUR; j++){
			T[i][j]=(char)0;
		}
	}
}

void init_reumu(vector<reumu> R,char T[LONGUEUR][LARGEUR]){
	for(int i = 0; i<LONGUEUR; i++){
		R.push_back(reumu(i,LARGEUR-1));
		R.push_back(reumu(i,0));
	}
	for(int i = 1; i<LARGEUR-1; i++){
		R.push_back(reumu(LONGUEUR-1,i));
		R.push_back(reumu(0,i));
	}
	for(int i = 0; (unsigned)i< R.size();i++){
		int x = R.at(i).getX();
		int y = R.at(i).getY();
		if (T[x][y] == char(0)) { T[x][y] = 'X';}
	}
}

void draw(char T[LONGUEUR][LARGEUR]){
	for (int i = 0; i< LONGUEUR; i++){
		for (int j = 0; j< LARGEUR; j++){
			cout<<T[i][j];
		}
		cout<<'\n';
	}
}

void update_oueurj(mobile *J,char T[LONGUEUR][LARGEUR]){
	T[J->getX()][J->getY()] = 'J';
}

void move(mobile *J, char *c,char T[LONGUEUR][LARGEUR]){
	if(*c=='q'){
		J->gauche(T);
		cout<<'g'<<endl;
	}else if(*c=='d'){
		J->droite(T);
		cout<<'d'<<endl;
	}else if(*c=='z'){
		J->haut(T);
		cout<<'h'<<endl;
	}else if(*c=='s'){
		J->bas(T);
		cout<<'b'<<endl;
	}
}

int main(){
	char T[LONGUEUR][LARGEUR];
	init_plateau(T);
	vector<reumu> R;
	mobile J(5,5);
	init_reumu(R,T);
	update_oueurj(&J,T);
	draw(T);
	while(1){
		char c;
		cin>>c;
		move(&J,&c,T);
		update_oueurj(&J,T);
		draw(T);
	}
	return 0;
}
