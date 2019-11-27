#ifndef GEURCHAR
#define GEURCHAR
#include "element.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

class geurchar: public element{
public:
	void ou_aller(char [LONGUEUR][LARGEUR]);
	geurchar(int,int);
	virtual ~geurchar();
};

#endif
