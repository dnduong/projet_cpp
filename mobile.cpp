#include "mobile.hpp"

mobile::mobile(int x, int y):element(x,y){}

mobile::~mobile(){}

void mobile::move(char T[LONGUEUR][LARGEUR],int a,int b){
	if(T[a][b]=='\0'){
		T[this->x][this->y] = '\0';
		this->x = a;
		this->y = b;
		T[this->x][this->y] = 'J';
	}
}

void mobile::gauche(char T[LONGUEUR][LARGEUR]){
	this->move(T,x,y-1);
}

void mobile::droite(char T[LONGUEUR][LARGEUR]){
	this->move(T,x,y+1);
}

void mobile::haut(char T[LONGUEUR][LARGEUR]){
	this->move(T,x-1,y);
}

void mobile::bas(char T[LONGUEUR][LARGEUR]){
	this->move(T,x+1,y);
}

void mobile::nord_ouest(char T[LONGUEUR][LARGEUR]){
	this->move(T,x-1,y-1);
}
void mobile::nord_est(char T[LONGUEUR][LARGEUR]){
	this->move(T,x-1,y+1);
}
void mobile::sud_ouest(char T[LONGUEUR][LARGEUR]){
	this->move(T,x+1,y-1);
}
void mobile::sud_est(char T[LONGUEUR][LARGEUR]){
	this->move(T,x+1,y+1);
}
