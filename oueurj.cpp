#include "oueurj.hpp"
using namespace std;

oueurj::oueurj(int x, int y):mobile(x,y),nbDiams(0){}

oueurj::~oueurj(){}

bool oueurj::move(vector<vector<char>> &T,vector<element> & R, vector<element> & D, vector<element> & G, vector<element> & P,int a,int b){
  if(T[b][a]=='\0'){
    this->move_without_condition(a,b);
    return true;
	}

  if (T[b][a]=='$'){
    this->nbDiams++;
    element::remove_V(D,a,b);
    unsigned int p = this->nbDiams++;
    if(p<P.size()){
      static_cast<teupor *>(&(P[p]))->ouvrir();
    }
    this->move_without_condition(a,b);
    return true;
  }
  
  if (T[b][a]=='-' || T[b][a] == 'X'){
    cout<<"passage interdit !"<<endl;
  }
  return false;
  /*if (T[this->y][this->x]=='*'){
    for (int i=0; i<G.size(); i++){
      if (G.at(i).getX()==this->x && G.at(i).get_Y()==this->y){
        G.at(i).ou_aller(T);
      }
  }
    this->nbTeleport++;
  }

  if (T[b][a]=='S'){
    //this->nbVies--;
    this->move_without_condition(T,a,b,'S');
    cout<<"Oups ! Un streumon a eu votre peau..."<<endl;
  }
  if (this->nbVies==0){
    cout<<"plus de Vies, vous êtes mort(DCD)..."<<endl;
  }

  if (T[b][a]=='+'){
    //passage au prochain plateau
  }*/
}

bool oueurj::keyboard_control(char & c,vector<vector<char>> &T,vector<element> & R, vector<element> & D, vector<element> & G, vector<element> & P){
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

void oueurj::afficheNbDiams(){
  cout<<"Nb Diams mangés :"<<nbDiams<<endl;
}
