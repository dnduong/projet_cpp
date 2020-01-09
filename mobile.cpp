#include "mobile.hpp"

mobile::mobile(int x,int y):element(x,y){}
mobile::~mobile(){};

void mobile::move_without_condition(int a,int b){
	this->y = b;
	this->x = a;
}

void mobile::random_case(vector<vector<char>> &T, int *xNext, int *yNext){
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  default_random_engine generator (seed);
  uniform_int_distribution<int> distribution_y(1,T.size()-2);
  uniform_int_distribution<int> distribution_x(1,T[0].size()-2);
  bool mv = false;
  int newX, newY;
  while(!mv){
    newX = distribution_x(generator);
    newY = distribution_y(generator);
    mv = (T[newY][newX] == 32) && (newX != this->x) && (newY != this->y);
  }
  *xNext = newX;
  *yNext = newY;
}
