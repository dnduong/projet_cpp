#ifndef STREUMON
#define STREUMON
#include "oueurj.hpp"
#include "mobile.hpp"
#include <cstdlib>
#include <iostream>

class streumon: public mobile{
public:
	bool move(vector<vector<char>> &,vector<element *>&,oueurj &,int,int);
	void randomMove(vector<vector<char>> &,vector<element *> &,oueurj &);
	streumon(int,int);
	static int empty_case(vector<vector<char>> &);
	virtual char graphic();
	virtual ~streumon();
};

#endif
