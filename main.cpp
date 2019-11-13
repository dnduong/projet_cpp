#include "element.hpp"
#include "diams.hpp"
#include "teupor.hpp"
#include "reumu.hpp"
#include "geurchar.hpp"
#include "mobile.hpp"
#include <vector>
#include "commun.hpp"
using namespace std;

void init(vector<reumu> & R,char T[LONGUEUR][LARGEUR],mobile & J){

	T[J.getX()][J.getY()] = 'J';
	for(int i = 0; i<LONGUEUR; i++){
		R.push_back(reumu(i,LARGEUR-1));
		R.push_back(reumu(i,0));
	}
	for(int i = 1; i<LARGEUR-1; i++){
		R.push_back(reumu(LONGUEUR-1,i));
		R.push_back(reumu(0,i));
	}
	for(int i = 0; (unsigned)i< R.size();i++){
		int x = R.at(i).getX();
		int y = R.at(i).getY();
		if (T[x][y] == char(0)) { T[x][y] = 'X';}
	}
}

void move(mobile & J, char & c,char T[LONGUEUR][LARGEUR]){
	switch(c){
		case 'q' :
			J.gauche(T);
			break;
		case 'd' :
			J.droite(T);
			break;
		case 'z':
			J.haut(T);
			break;
		case 's':
			J.bas(T);
			break;
		case 'a':
			J.nord_ouest(T);
			break;
		case 'e':
			J.nord_est(T);
			break;
		case 'w':
			J.sud_ouest(T);
			break;
		case 'c':
			J.sud_est(T);
			break;
		default:
			break;
	}
	
}

int main(){
	char T[LONGUEUR][LARGEUR];
	init_plateau(T);
	vector<reumu> R;
	mobile J(5,5);
	init(R,T,J);
	draw(T);
	while(1){
		char c;
		cin>>c;
		move(J,c,T);
		draw(T);
	}
	return 0;
}
