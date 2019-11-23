#ifndef OUEURJ
#define OUEURJ
#include "mobile.hpp"
#include <cstdlib>
#include <iostream>

class oueurj: public mobile{
private:
	int nbDiams;
	int nbVies;
	int niveauCourant;
	int nbTeleport;
public:
	void move(char [LONGUEUR][LARGEUR]);
	void afficheNbDiams();
	void afficheNbTeleport();
	oueurj(int,int);
	virtual ~oueurj();
};

#endif
