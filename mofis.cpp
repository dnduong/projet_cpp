//oueurj.hpp
virtual void move(char [LONGUEUR][LARGEUR],int a, int b, vector<geurchar> & );


//oueurj.cpp
void oueurj::move(char T[LONGUEUR][LARGEUR],int a,int b, vector<geurchar> & G){
  if(T[b][a]=='\0'){
    this->move_without_condition(T,a,b,'J');
	}

  if (T[this->y][this->x]=='$'){
    this->nbDiams++;
    this->move_without_condition(T,a,b,'J');
  }

  if (T[this->y][this->x]=='*'){
    for (int i=0; i<G.size(); i++){
      if (G.at(i).getX()==this->x && G.at(i).get_Y()==this->y){
        G.at(i).ou_aller(T);
      }
  }
    this->nbTeleport++;
  }

  if (T[this->y][this->x]=='S'){
    //this->nbVies--;
    this->move_without_condition(T,a,b,'S');
    cout<<"Oups ! Un streumon a eu votre peau..."<<endl;
  }

//geurchar.cpp
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

//geurchar.hpp
#ifndef GEURCHAR
#define GEURCHAR
#include "element.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

class geurchar: public element{
public:
	void ou_aller(char [LONGUEUR][LARGEUR]);
	geurchar(int,int);
	virtual ~geurchar();
};

#endif
