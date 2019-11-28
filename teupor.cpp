#include "teupor.hpp"

teupor::teupor(int x,int y):element(x,y),ouvert(false){}

teupor::~teupor(){}

char teupor::graphic(){
	if(this->ouvert){
		return '+';
	}else{
		return '-';
	}
}

void teupor::ouvrir(){
	this->ouvert = true;
}