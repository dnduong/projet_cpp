#ifndef STREUMON
#define STREUMON
#include "mobile.hpp"
#include <cstdlib>
#include <iostream>

class streumon: public mobile{
public:
	streumon(int,int);
	virtual char graphic();
	virtual ~streumon();
};

#endif
