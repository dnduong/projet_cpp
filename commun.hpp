#include <cstdlib>
#include <iostream>
using namespace std;
void init_plateau(char T[LONGUEUR][LARGEUR]){
	for (int i = 0; i< LONGUEUR; i++){
		for (int j = 0; j< LARGEUR; j++){
			T[i][j]=(char)0;
		}
	}
}

void draw(char T[LONGUEUR][LARGEUR]){
	for (int i = 0; i< LONGUEUR; i++){
		for (int j = 0; j< LARGEUR; j++){
			cout<<T[i][j];
		}
		cout<<'\n';
	}
}