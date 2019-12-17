#include <cstdlib>
#include <iostream>
#include <vector>
#include <ncurses.h>
using namespace std;

void init_plateau(vector<vector<char>> &T, int LONGUEUR, int LARGEUR){
	for (int i = 0; i< LONGUEUR; i++){
		T.push_back(vector<char> ());
	}
	for(unsigned int i = 0; i< T.size(); i++){
		for (int j = 0; j< LARGEUR; j++){
			T[i].push_back('\0');
		}
	}
} 


