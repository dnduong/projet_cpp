#ifndef STREUMON
#define STREUMON
#include "mobile.hpp"
#include <cstdlib>
#include <iostream>

class streumon: public mobile{
private:
	//oueurj j;
public:
	void poursuite(char [LONGUEUR][LARGEUR], int); //la méthode permettant aux streumons de poursuivre le oueurj
	streumon(int,int);
	virtual char graphic();
	virtual ~streumon();
};

#endif
