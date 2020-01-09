#include "streumon.hpp"

streumon::streumon(int x, int y):mobile(x,y){}
char streumon::graphic(){
	return '#';
}
streumon::~streumon(){}

int streumon::empty_case(vector<vector<char>> & T){
	int ct = 0;
	for(unsigned int i = 0; i< T.size(); i++){
		for (unsigned int j = 0; j< T[i].size(); j++){
			if(T[i][j] == 32){
				ct++;
			}
		}
	}
	return ct;
}

bool streumon::move(vector<vector<char>> &T,vector<element *> &S,oueurj &J,int a,int b){
	if(T[b][a]==32){
    	this->move_without_condition(a,b);
    	return true;
	}
	if(T[b][a]=='@'){
		J.revive(T);
		this->move_without_condition(a,b);
		return true;
	}
	if(T[b][a]=='#' && this->x!=a && this->y!=b){
		unsigned int ec = empty_case(T);
		if(ec > 0 && S.size() < ec/5){
		  	int xNext,yNext;
  			random_case(T,&xNext,&yNext);
  			S.push_back(new streumon(xNext,yNext));
		}	
	}
	return false;
}

void streumon::randomMove(vector<vector<char>> &T,vector<element *> &S,oueurj &J){
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  	default_random_engine generator (seed);
  	uniform_int_distribution<int> distribution(-1,1);
  	int xNext = distribution(generator);
  	int yNext = distribution(generator);
  	move(T,S,J,this->x+xNext,this->y+yNext);
}