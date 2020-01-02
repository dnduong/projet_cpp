#include "oueurj.hpp"
using namespace std;

oueurj::oueurj(int x, int y):mobile(x,y),nbDiams(0),nbTeles(0),nbVies(3),nivTotal(0),nivCourant(1),fini(false),gagne(false){}

oueurj::~oueurj(){}

void oueurj::setNivTotal(int n){
  this->nivTotal=n;
}

bool oueurj::estPerdu(){
  return this->nbVies <= 0;
}
bool oueurj::estFini(){
  return this->fini;
}

bool oueurj::estGagne(){
  return this->gagne;
}

void oueurj::random_case(vector<vector<char>> &T, int *xNext, int *yNext){
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  default_random_engine generator (seed);
  uniform_int_distribution<int> distribution_y(1,T.size()-2);
  uniform_int_distribution<int> distribution_x(1,T[0].size()-2);
  bool mv = false;
  int newX, newY;
  while(!mv){
    newX = distribution_x(generator);
    newY = distribution_y(generator);
    mv = (T[newY][newX] == '\0') && (newX != this->x) && (newY != this->y);
  }
  *xNext = newX;
  *yNext = newY;
}

bool oueurj::randomMove(vector<vector<char>> &T){
  int xNext,yNext;
  random_case(T,&xNext,&yNext);
  move_without_condition(xNext,yNext);
  return true;
}

bool oueurj::move(vector<vector<char>> &T,vector<element *> & R, vector<element *> & D, vector<element *> & G, vector<element *> & P,vector<element*> & S,int a,int b){
  if(T[b][a]=='\0'){
    this->move_without_condition(a,b);
    return true;
	}

  if (T[b][a]=='$'){
    element::remove_V(D,a,b);
    //ouvrir la porte
    unsigned int p = this->nbDiams;
    if(p<P.size()){
      dynamic_cast<teupor *>(P[p])->ouvrir();
    }
    //
    this->nbDiams++;
    this->move_without_condition(a,b);
    return true;
  }

  if (T[b][a]=='*'){
    element::remove_V(G,a,b);
    this->nbTeles++;
    this->move_without_condition(a,b);
    return true;
  }

  if (T[b][a]=='+'){
    if(nivCourant<nivTotal){
      this->nivCourant++; 
    }else{
      this->gagne = true;
    }
    this->fini = true; 
    return true;
  }
  
  if (T[b][a]=='#'){
    return this->revive(T);
  }

  return false;
}

bool oueurj::revive(vector<vector<char>> &T){
  this->nbVies--;
  return this->randomMove(T);
}

bool oueurj::teleport(vector<vector<char>> &T){
  if(this->nbTeles <= 0){
    return false;
  }else{
    this->nbTeles--;
    return this->randomMove(T);  
  }
}

char oueurj::graphic(){
  return '@';
}

bool oueurj::keyboard_control(char & c,vector<vector<char>> &T,vector<element *> & R, vector<element *> & D, vector<element *> & G, vector<element *> & P,vector<element*> & S){
	switch(c){
		case 'q' :
			return this->move(T,R,D,G,P,S,x-1,y);
			break;
		case 'd' :
			return this->move(T,R,D,G,P,S,x+1,y);
			break;
		case 'z':
			return this->move(T,R,D,G,P,S,x,y-1);
			break;
		case 's':
			return this->move(T,R,D,G,P,S,x,y+1);
			break;
		case 'a':
			return this->move(T,R,D,G,P,S,x-1,y-1);
			break;
		case 'e':
			return this->move(T,R,D,G,P,S,x+1,y-1);
			break;
		case 'w':
			return this->move(T,R,D,G,P,S,x-1,y+1);
			break;
		case 'c':
			return this->move(T,R,D,G,P,S,x+1,y+1);
			break;
    case 'g':
      return this->teleport(T);
		default:
      return false;
			break;
	}
  return true;
}

int oueurj::getNbDiams(){
  return nbDiams;
}

int oueurj::getNbTeles(){
  return nbTeles;
}

int oueurj::getNbVies(){
  return nbVies;
}

int oueurj::getNivCourant(){
  return nivCourant;
}

int oueurj::getNivTotal(){
  return nivTotal;
}

void oueurj::reset(vector<vector<char>> &T){
  this->fini = false;
  this->nbDiams = 0;
  this->randomMove(T);
}

