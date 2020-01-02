#include "mobile.hpp"

mobile::mobile(int x,int y):element(x,y){}
mobile::~mobile(){};

void mobile::move_without_condition(int a,int b){
	this->y = b;
	this->x = a;
}