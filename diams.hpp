#ifndef DIAMS
#define DIAMS
#include "element.hpp"
#include <cstdlib>
#include <iostream>

class diams: public element{
public:
	diams(int,int);
	virtual ~diams();
};

#endif