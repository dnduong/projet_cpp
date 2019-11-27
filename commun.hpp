#include <cstdlib>
#include <iostream>
#include <vector>
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

void clear(vector<vector<char>> &T){
	for(unsigned int i = 0; i< T.size(); i++){
		for (unsigned int j = 0; j< T[i].size(); j++){
			T[i][j]='\0';
		}
	}
}

void draw(vector<vector<char>> & T){
	for (auto v : T){
		for (auto w : v){
			cout<<w;
		}
		cout<<'\n';
	}
}



