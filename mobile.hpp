#ifndef MOBILE
#define MOBILE
#include "element.hpp"
#include <cstdlib>
#include <iostream>

class mobile: public element{
private:
	void move(char [LONGUEUR][LARGEUR],int,int);
public:
	int getLONGUEUR();
	int getLARGEUR();
	void gauche(char [LONGUEUR][LARGEUR]);
	void droite(char [LONGUEUR][LARGEUR]);
	void haut(char [LONGUEUR][LARGEUR]);
	void bas(char [LONGUEUR][LARGEUR]);
	void nord_ouest(char [LONGUEUR][LARGEUR]);
	void nord_est(char [LONGUEUR][LARGEUR]);
	void sud_ouest(char [LONGUEUR][LARGEUR]);
	void sud_est(char [LONGUEUR][LARGEUR]);
	mobile(int,int);
	virtual ~mobile();
};

#endif