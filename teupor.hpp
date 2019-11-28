#ifndef TEUPOR
#define TEUPOR
#include "element.hpp"
#include <cstdlib>
#include <iostream>

class teupor:public element{
private:
	bool ouvert;
public:
	teupor(int,int);
	virtual char graphic();
	virtual ~teupor();
	void ouvrir();
};

#endif