#ifndef OUEURJ
#define OUEURJ
#include "mobile.hpp"
#include <cstdlib>
#include <iostream>

class oueurj: public mobile{
private:
	int nbDiams;
	int niveauCourant;
	int nbTeleport;
public:
  virtual void move(char [LONGUEUR][LARGEUR],int a, int b, vector<geurchar> & );
	void keyboard_control(char & ,char [LONGUEUR][LARGEUR]);
	void afficheNbDiams();
	void afficheNbTeleport();
	oueurj(int,int);
	virtual ~oueurj();
};

#endif
