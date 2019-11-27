#include <cstdlib>
#include <ctime>
#include <iostream>
#define LONGUEUR 10
#define LARGEUR 50

using namespace std;


int main (){
  srand((unsigned)time(0));
  int a {rand()%LARGEUR};
  int b {rand()%LONGUEUR};
  while (!(a<LARGEUR && b<LONGUEUR)){
    a = rand()%LARGEUR;
    b = rand()%LONGUEUR;
  }
  cout<<a<<endl;
  return 0;
}
