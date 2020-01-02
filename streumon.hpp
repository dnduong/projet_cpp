#ifndef STREUMON
#define STREUMON
#include "oueurj.hpp"
#include "mobile.hpp"
#include <cstdlib>
#include <iostream>

class streumon: public mobile{
public:
	bool move(vector<vector<char>> &,oueurj &,int,int);
	void randomMove(vector<vector<char>> &,oueurj &);
	streumon(int,int);
	virtual char graphic();
	virtual ~streumon();
};

#endif
