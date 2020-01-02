#ifndef OUEURJ
#define OUEURJ
#include "mobile.hpp"
#include "teupor.hpp"
#include <chrono>
#include <random>


class oueurj: public mobile{
private:
	int nbDiams, nbTeles, nbVies, nivTotal, nivCourant;
	bool fini,gagne;
public:
  	bool move(vector<vector<char>> &,vector<element *> &, vector<element *> &, vector<element *> &, vector<element *> &,vector<element *> &,int,int);
	bool revive(vector<vector<char>> &);
	bool randomMove(vector<vector<char>> &);
	bool keyboard_control(char & ,vector<vector<char>> &,vector<element *> &, vector<element *> &, vector<element *> &, vector<element *> &,vector<element *> &);
	int getNbDiams();
	int getNbTeles();
	int getNbVies();
	int getNivTotal();
	void reset(vector<vector<char>> &);
	int getNivCourant();
	void setNivTotal(int);
	oueurj(int,int);
	bool estFini();
	bool estGagne();
	bool estPerdu();
	void random_case(vector<vector<char>> &,int *,int *);
	bool teleport(vector<vector<char>> &);
	virtual char graphic();
	virtual ~oueurj();
};

#endif
