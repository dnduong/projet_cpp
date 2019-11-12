#ifndef MOBILE
#define MOBILE
#include "element.hpp"
#include <cstdlib>
#include <iostream>

class mobile: public element{
public:
	void gauche(char [LONGUEUR][LARGEUR]);
	void droite(char [LONGUEUR][LARGEUR]);
	void haut(char [LONGUEUR][LARGEUR]);
	void bas(char [LONGUEUR][LARGEUR]);
	mobile(int,int);
	virtual ~mobile();
};

#endif