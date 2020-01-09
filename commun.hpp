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
			T[i].push_back(32);
		}
	}
} 

void draw(vector<vector<char>> & T){
	for(unsigned int i = 0; i< T.size(); i++){
		for (unsigned int j = 0; j< T[i].size(); j++){
			cout<<T[i][j];
		}
		cout<<'\n';
	}
}

int empty_case(vector<vector<char>> & T){
	int ct = 0;
	for(unsigned int i = 0; i< T.size(); i++){
		for (unsigned int j = 0; j< T[i].size(); j++){
			if(T[i][j] == 32){
				ct++;
			}
		}
	}
	return ct;
}

void clear(vector<vector<char>> &T, vector<element*> & R, vector<element*> & D, vector<element*> & G, vector<element*> & P,vector<element*> & S){
	T.clear();
	R.clear();
	D.clear();
	G.clear();
	P.clear();
	S.clear();
}

