#include "geurchar.hpp"

geurchar::geurchar(int x, int y):element(x,y){}

char geurchar::graphic(){
	return '*';
}

geurchar::~geurchar(){}