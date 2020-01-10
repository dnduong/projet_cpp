#ifndef STREUMON
#define STREUMON
#include "oueurj.hpp"
#include "reumu.hpp"
#include "diams.hpp"
#include "geurchar.hpp"
#include "mobile.hpp"
#include <cstdlib>
#include <iostream>

class streumon: public mobile{
public:
	bool move(vector<vector<char>> &,vector<element *>&,vector<element *> &,vector<element *> &,vector<element *> &,oueurj &,int,int);
	void randomMove(vector<vector<char>> &,vector<element *> &,vector<element *> &,vector<element *> &,vector<element *> &,oueurj &);
	streumon(int,int);
	static int empty_case(vector<vector<char>> &);
 	void reproduction(vector<vector<char>> &,vector<element *> &);
 	void creer_artefact(int ,int ,int ,vector<element *> &,vector<element *> &,vector<element *> &);
	virtual char graphic();
	virtual ~streumon();
};

#endif
