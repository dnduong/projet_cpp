#include "teupor.hpp"

teupor::teupor(int x,int y):element(x,y),ouvert(false){}

teupor::~teupor(){}
bool teupor::estOuvert(){
	return this->ouvert;
}

void teupor::ouvrir(){
	this->ouvert = true;
}