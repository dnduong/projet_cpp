#include "oueurj.hpp"
using namespace std;

oueurj::oueurj(int x, int y):mobile(x,y){}

oueurj::~oueurj(){}

void oueurj::move(char T[LONGUEUR][LARGEUR]){
  if (T[this->x][this->y]=='$'){
    this->nbDiams++;
    T[this->x][this->y]='J';
  }
  if (T[this->x][this->y]=='*'){
    //nouvelle position : l'utilisateur choisit ou pas ??
    this->nbTeleport++;
  }
  if (T[this->x][this->y]=='S'){
    this->nbVies--;
    cout<<"Oups ! Un streumon a eu votre peau..."<<endl;
  }
  if (this->nbVies==0){
    cout<<"plus de Vies, vous êtes mort(DCD)..."<<endl;
  }
  if (T[this->x][this->y]=='-'){
    cout<<"teupor fermée, passage interdit !"<<endl;
  }
  if (T[this->x][this->y]=='+'){
    //passage au prochain plateau
  }
}

void oueurj::afficheNbDiams(){
  cout<<"Nb Diams mangés :"<<nbDiams<<endl;
}

void oueurj::afficheNbTeleport(){
  cout<<"Nombre de téléportations : "<<nbTeleport<<endl;
}
