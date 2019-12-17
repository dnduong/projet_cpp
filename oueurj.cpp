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
