#include "oueurj.hpp"
using namespace std;

oueurj::oueurj(int x, int y):mobile(x,y),nbDiams(0),nbTeles(0),gagne(false){}

oueurj::~oueurj(){}

bool oueurj::estGagner(){
  return this->gagne;
}

bool oueurj::move(vector<vector<char>> &T,vector<element *> & R, vector<element *> & D, vector<element *> & G, vector<element *> & P,int a,int b){
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
    this->gagne = true;
    return true;
  }
  
  return false;
  /*

  if (T[b][a]=='S'){
    //this->nbVies--;
    this->move_without_condition(T,a,b,'S');
    cout<<"Oups ! Un streumon a eu votre peau..."<<endl;
  }
  if (this->nbVies==0){
    cout<<"plus de Vies, vous êtes mort(DCD)..."<<endl;
  }

  */
}
bool oueurj::teleport(vector<vector<char>> &T,vector<element *> & R, vector<element *> & D, vector<element *> & G, vector<element *> & P){
  if(this->nbTeles <= 0){
    return false;
  }
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  default_random_engine generator (seed);
  uniform_int_distribution<int> distribution_y(1,T.size()-2);
  uniform_int_distribution<int> distribution_x(1,T[0].size()-2);
  bool mv = false;
  int xPrev = this->x;
  int yPrev = this->y;
  while (!mv){
    mv = this->move(T,R,D,G,P,distribution_x(generator),distribution_y(generator)) && (xPrev != this->x) && (yPrev != this->y);
  }
  this->nbTeles--;
  return true;
}

char oueurj::graphic(){
  return '@';
}

bool oueurj::keyboard_control(char & c,vector<vector<char>> &T,vector<element *> & R, vector<element *> & D, vector<element *> & G, vector<element *> & P){
	switch(c){
		case 'q' :
			return this->gauche(T,R,D,G,P);
			break;
		case 'd' :
			return this->droite(T,R,D,G,P);
			break;
		case 'z':
			return this->haut(T,R,D,G,P);
			break;
		case 's':
			return this->bas(T,R,D,G,P);
			break;
		case 'a':
			return this->nord_ouest(T,R,D,G,P);
			break;
		case 'e':
			return this->nord_est(T,R,D,G,P);
			break;
		case 'w':
			return this->sud_ouest(T,R,D,G,P);
			break;
		case 'c':
			return this->sud_est(T,R,D,G,P);
			break;
    case 'g':
      return this->teleport(T,R,D,G,P);
		default:
      return false;
			break;
	}
}

int oueurj::getNbDiams(){
  return nbDiams;
}

int oueurj::getNbTeles(){
  return nbTeles;
}
