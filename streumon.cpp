#include "streumon.hpp"

streumon::streumon(int x, int y):mobile(x,y){}
char streumon::graphic(){
	return '#';
}
streumon::~streumon(){}

bool streumon::move(vector<vector<char>> &T,oueurj &J,int a,int b){
	if(T[b][a]=='\0'){
    	this->move_without_condition(a,b);
    	return true;
	}
	if(T[b][a]=='@'){
		J.revive(T);
		this->move_without_condition(a,b);
		return true;
	}
	return false;
}

void streumon::randomMove(vector<vector<char>> &T,oueurj &J){
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  	default_random_engine generator (seed);
  	uniform_int_distribution<int> distribution(-1,1);
  	int xNext = distribution(generator);
  	int yNext = distribution(generator);
  	move(T,J,this->x+xNext,this->y+yNext);
}