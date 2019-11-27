#include "mobile.hpp"

mobile::mobile(int x, int y):element(x,y){}

mobile::~mobile(){}

void mobile::move_without_condition(char T[LONGUEUR][LARGEUR],int a,int b, char c){
	T[this->y][this->x] = '\0';
	this->y = b;
	this->x = a;
	T[this->y][this->x] = c;
}

void mobile::gauche(char T[LONGUEUR][LARGEUR]){
	this->move(T,x-1,y);
}

void mobile::droite(char T[LONGUEUR][LARGEUR]){
	this->move(T,x+1,y);
}

void mobile::haut(char T[LONGUEUR][LARGEUR]){
	this->move(T,x,y-1);
}

void mobile::bas(char T[LONGUEUR][LARGEUR]){
	this->move(T,x,y+1);
}

void mobile::nord_ouest(char T[LONGUEUR][LARGEUR]){
	this->move(T,x-1,y-1);
}
void mobile::nord_est(char T[LONGUEUR][LARGEUR]){
	this->move(T,x+1,y-1);
}
void mobile::sud_ouest(char T[LONGUEUR][LARGEUR]){
	this->move(T,x-1,y+1);
}
void mobile::sud_est(char T[LONGUEUR][LARGEUR]){
	this->move(T,x+1,y+1);
}
