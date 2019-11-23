#ifndef ELEMENT
#define ELEMENT
#include <cstdlib>
#include <iostream>
#define LONGUEUR 10
#define LARGEUR 50


class element
{
protected:
	int x,y;
public:
	int getX();
	int getY();
	element(int,int);
	virtual ~element();
};

#endif
