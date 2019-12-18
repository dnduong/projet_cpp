#ifndef OUEURJ
#define OUEURJ
#include "mobile.hpp"
#include "teupor.hpp"
#include <chrono>
#include <random>


class oueurj: public mobile{
private:
	int nbDiams, nbTeles;
	bool gagne;
public:
  	virtual bool move(vector<vector<char>> &,vector<element *> &, vector<element *> &, vector<element *> &, vector<element *> &,int,int);
	bool keyboard_control(char & ,vector<vector<char>> &,vector<element *> &, vector<element *> &, vector<element *> &, vector<element *> &);
	int getNbDiams();
	int getNbTeles();
	oueurj(int,int);
	bool estGagner();
	bool teleport(vector<vector<char>> &,vector<element *> &, vector<element *> &, vector<element *> &, vector<element *> &);
	virtual char graphic();
	virtual ~oueurj();
};

#endif
