#include "element.hpp"
#include "diams.hpp"
#include "teupor.hpp"
#include "reumu.hpp"
#include "geurchar.hpp"
#include "mobile.hpp"
#include "commun.hpp"
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
	init_reumu(T);
	init(T,'-');
	init(T,'$');
	init(T,'X');
	init(T,'*');
	tableToVector(T,R,D,G,P);
	creationFichier(R,D,G,P);
	return 0;
}