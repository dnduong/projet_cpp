#ifndef OUEURJ
#define OUEURJ
#include "mobile.hpp"
#include "teupor.hpp"

class oueurj: public mobile{
private:
	int nbDiams;
public:
  	virtual bool move(vector<vector<char>> &,vector<element> &, vector<element> &, vector<element> &, vector<element> &,int,int);
	bool keyboard_control(char & ,vector<vector<char>> &,vector<element> &, vector<element> &, vector<element> &, vector<element> &);
	void afficheNbDiams();
	oueurj(int,int);
	virtual ~oueurj();
};

#endif
