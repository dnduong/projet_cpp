#include "element.hpp"

element::element(int x,int y):x(x), y(y){}

element::~element(){}

void element::remove_V(vector<element> &V, int &a,int &b){
	for(auto it = V.begin(); it != V.end();){
		if((*it).getY()==b && (*it).getX()==a){
			it = V.erase(it);
		}else{
			++it;
		}
	}
}

int element::getX(){
	return this->x;
}

int element::getY(){
	return this->y;
}
