#ifndef REUMU
#define REUMU
#include "element.hpp"
#include <cstdlib>
#include <iostream>

class reumu: public element{
public:
	reumu(int,int);
	virtual char graphic();
	virtual ~reumu();
};

#endif