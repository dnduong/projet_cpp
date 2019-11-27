#ifndef ELEMENT
#define ELEMENT
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
class element
{
protected:
	int x,y;
public:
	int getX();
	int getY();
	static void remove_V(vector<element> &, int &,int &);
	element(int,int);
	virtual ~element();
};

#endif
