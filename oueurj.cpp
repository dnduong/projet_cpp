#include "oueurj.hpp"
using namespace std;

oueurj::oueurj(int x, int y):mobile(x,y){}

oueurj::~oueurj(){}

void oueurj::move(char T[LONGUEUR][LARGEUR],int a,int b){
  if(T[b][a]=='\0'){
    this->move_without_condition(T,a,b,'J');
	}

  if (T[b][a]=='$'){
    this->nbDiams++;
    this->move_without_condition(T,a,b,'J');
  }
  /*if (T[b][a]=='*'){
    //nouvelle position : l'utilisateur choisit ou pas ??
    this->nbTeleport++;
  }*/
  if (T[b][a]=='S'){
    //this->nbVies--;
    this->move_without_condition(T,a,b,'S');
    cout<<"Oups ! Un streumon a eu votre peau..."<<endl;
  }
  /*if (this->nbVies==0){
    cout<<"plus de Vies, vous êtes mort(DCD)..."<<endl;
  }*/
  if (T[b][a]=='-' || T[b][a] == 'X'){
    cout<<"passage interdit !"<<endl;
  }
  /*if (T[b][a]=='+'){
    //passage au prochain plateau
  }*/
}

void oueurj::keyboard_control(char & c,char T[LONGUEUR][LARGEUR]){
	switch(c){
		case 'q' :
			this->gauche(T);
			break;
		case 'd' :
			this->droite(T);
			break;
		case 'z':
			this->haut(T);
			break;
		case 's':
			this->bas(T);
			break;
		case 'a':
			this->nord_ouest(T);
			break;
		case 'e':
			this->nord_est(T);
			break;
		case 'w':
			this->sud_ouest(T);
			break;
		case 'c':
			this->sud_est(T);
			break;
		default:
			break;
	}
}

void oueurj::afficheNbDiams(){
  cout<<"Nb Diams mangés :"<<nbDiams<<endl;
}

void oueurj::afficheNbTeleport(){
  cout<<"Nombre de téléportations : "<<nbTeleport<<endl;
}
