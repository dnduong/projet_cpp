#ifndef GEURCHAR
#define GEURCHAR
#include "element.hpp"
#include <cstdlib>
#include <iostream>

class geurchar: public element{
public:
	void ouAller(int,int);
	geurchar(int,int);
	virtual ~geurchar();
};

#endif
