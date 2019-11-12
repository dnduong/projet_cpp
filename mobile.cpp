#include "mobile.hpp"

mobile::mobile(int x, int y):element(x,y){}

mobile::~mobile(){}

void mobile::gauche(char T[LONGUEUR][LARGEUR]){
	T[x][y] = '\0';
	this->y--;
}

void mobile::droite(char T[LONGUEUR][LARGEUR]){
	T[x][y] = '\0';
	this->y++;
}

void mobile::haut(char T[LONGUEUR][LARGEUR]){
	T[x][y] = '\0';
	this->x--;
}

void mobile::bas(char T[LONGUEUR][LARGEUR]){
	T[x][y] = '\0';
	this->x++;
}