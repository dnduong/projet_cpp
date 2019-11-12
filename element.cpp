#include "element.hpp"

element::element(int x,int y):x(x), y(y){}

element::~element(){}

int element::getX(){
	return this->x;
}

int element::getY(){
	return this->y;
}