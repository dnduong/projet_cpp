#include "geurchar.hpp"

geurchar::geurchar(int x, int y):element(x,y){
  srand(time(0));
  x = rand()%LARGEUR;
  y = rand()%LONGUEUR;
}

geurchar::~geurchar(){}

void geurchar::ou_aller(char T[LONGUEUR][LARGEUR]){
  while (!(this->x<LARGEUR && this->y<LONGUEUR && T[this->y][this->x]!='X' && T[this->y][this->x]!='S')){
    this->x = rand()%LARGEUR;
    this->y = rand()%LONGUEUR;
  }
  cout<<"nouvelle position : "<<x<<","<<y<<endl;
}
