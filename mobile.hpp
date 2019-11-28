#ifndef MOBILE
#define MOBILE
#include <cstdlib>
#include <iostream>
#include "element.hpp"
using namespace std;
class mobile: public element{
protected:
	bool gauche(vector<vector<char>> &,vector<element *> &, vector<element *> &, vector<element *> &, vector<element *> &);
	bool droite(vector<vector<char>> &,vector<element *> &, vector<element *> &, vector<element *> &, vector<element *> &);
	bool haut(vector<vector<char>> &,vector<element *> &, vector<element *> &, vector<element *> &, vector<element *> &);
	bool bas(vector<vector<char>> &,vector<element *> &, vector<element *> &, vector<element *> &, vector<element *> &);
	bool nord_ouest(vector<vector<char>> &,vector<element *> &, vector<element *> &, vector<element *> &, vector<element *> &);
	bool nord_est(vector<vector<char>> &,vector<element *> &, vector<element *> &, vector<element *> &, vector<element *> &);
	bool sud_ouest(vector<vector<char>> &,vector<element *> &, vector<element *> &, vector<element *> &, vector<element *> &);
	bool sud_est(vector<vector<char>> &,vector<element *> &, vector<element *> &, vector<element *> &, vector<element *> &);
	void move_without_condition(int,int);
public:
	mobile(int,int);
	virtual ~mobile();
	virtual bool move(vector<vector<char>> &,vector<element *> &, vector<element *> &, vector<element *> &, vector<element *> &,int,int) = 0;
	virtual char graphic() = 0;
};

#endif
