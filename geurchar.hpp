#ifndef GEURCHAR
#define GEURCHAR
#include "element.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

class geurchar:public element{
public:
	virtual char graphic();
	geurchar(int,int);
	virtual ~geurchar();
};

#endif
