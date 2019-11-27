#include "element.hpp"
#include "diams.hpp"
#include "teupor.hpp"
#include "reumu.hpp"
#include "geurchar.hpp"
#include "mobile.hpp"
#include "commun.hpp"
#include "oueurj.hpp"
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(){
	char T[LONGUEUR][LARGEUR];
	vector<reumu> R;
	vector<diams> D;
	vector<geurchar> G;
	vector<teupor> P;
	init_plateau(T);
	importFichier(T,R,D,G,P);
	vectorToTable(T,R,D,G,P);
	oueurj J(5,5);
	init_joueur(J,T);
	draw(T);
	while(1){
		char c;
		cin>>c;
		J.keyboard_control(c,T);
		draw(T);
	}
	return 0;
}
