#include "teupor.hpp"

teupor::teupor(int x,int y):element(x,y),ouvert(false){}

teupor::~teupor(){}

void teupor::ouvrir(){
	this->ouvert = true;
}