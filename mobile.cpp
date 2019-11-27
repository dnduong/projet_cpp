#include "mobile.hpp"

mobile::mobile(int x, int y):element(x,y){}

mobile::~mobile(){}

void mobile::move_without_condition(int a,int b){
	this->y = b;
	this->x = a;
}

bool mobile::gauche(vector<vector<char>> &T,vector<element> & R, vector<element> & D, vector<element> & G, vector<element> & P){
	return this->move(T,R,D,G,P,x-1,y);
}

bool mobile::droite(vector<vector<char>> &T,vector<element> & R, vector<element> & D, vector<element> & G, vector<element> & P){
	return this->move(T,R,D,G,P,x+1,y);
}

bool mobile::haut(vector<vector<char>> &T,vector<element> & R, vector<element> & D, vector<element> & G, vector<element> & P){
	return this->move(T,R,D,G,P,x,y-1);
}

bool mobile::bas(vector<vector<char>> &T,vector<element> & R, vector<element> & D, vector<element> & G, vector<element> & P){
	return this->move(T,R,D,G,P,x,y+1);
}

bool mobile::nord_ouest(vector<vector<char>> &T,vector<element> & R, vector<element> & D, vector<element> & G, vector<element> & P){
	return this->move(T,R,D,G,P,x-1,y-1);
}
bool mobile::nord_est(vector<vector<char>> &T,vector<element> & R, vector<element> & D, vector<element> & G, vector<element> & P){
	return this->move(T,R,D,G,P,x+1,y-1);
}
bool mobile::sud_ouest(vector<vector<char>> &T,vector<element> & R, vector<element> & D, vector<element> & G, vector<element> & P){
	return this->move(T,R,D,G,P,x-1,y+1);
}
bool mobile::sud_est(vector<vector<char>> &T,vector<element> & R, vector<element> & D, vector<element> & G, vector<element> & P){
	return this->move(T,R,D,G,P,x+1,y+1);
}
