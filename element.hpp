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
	virtual char graphic()=0;
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	static void remove_V(vector<element *> &, int &,int &);
	element(int,int);
	virtual ~element();
};

#endif
