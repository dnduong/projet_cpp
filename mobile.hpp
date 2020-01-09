#ifndef MOBILE
#define MOBILE
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <random>
#include "element.hpp"
using namespace std;
class mobile: public element{
protected:
	void move_without_condition(int,int);
public:
	mobile(int,int);
	void random_case(vector<vector<char>> &,int *,int *);
	virtual ~mobile();
	virtual char graphic() = 0;
};

#endif
