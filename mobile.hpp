#ifndef MOBILE
#define MOBILE
#include "element.hpp"
#include <cstdlib>
#include <iostream>

class mobile: public element{
protected:
	void gauche(char [LONGUEUR][LARGEUR]);
	void droite(char [LONGUEUR][LARGEUR]);
	void haut(char [LONGUEUR][LARGEUR]);
	void bas(char [LONGUEUR][LARGEUR]);
	void nord_ouest(char [LONGUEUR][LARGEUR]);
	void nord_est(char [LONGUEUR][LARGEUR]);
	void sud_ouest(char [LONGUEUR][LARGEUR]);
	void sud_est(char [LONGUEUR][LARGEUR]);
	virtual void move(char [LONGUEUR][LARGEUR],int,int) = 0;
	void move_without_condition(char [LONGUEUR][LARGEUR],int,int,char);
public:
	mobile(int,int);
	virtual ~mobile();
};

#endif
