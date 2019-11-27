#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
void importFichier(vector<reumu> & R, vector<diams> & D, vector<geurchar> & G, vector<teupor> & P){
	string fn;
	cout<<"Entrer le nom du fichier"<<endl;
	cin>>fn;
	fstream file;
	file.open(fn,ios::in);
	if(!file){
		cout<<"Création échouée"<<endl;
		return;
	}
	char c;
	int type;
	bool in_x;
	string x,y;
	while(file.get(c)){
		if (c == 'D'){
			type = 1;
		}else if (c == 'G'){
			type = 2;
		}else if (c == 'R'){
			type = 3;
		}else if (c == 'T'){
			type = 4;
		}else if (c == ','){
			if(type == 1){
				D.push_back(diams(stoi(x),stoi(y)));
				x = "";
				y = "";
			}else if(type == 2){
				G.push_back(geurchar(stoi(x),stoi(y)));
				x = "";
				y = "";
			}else if(type == 3){
				R.push_back(reumu(stoi(x),stoi(y)));
				x = "";
				y = "";
			}else if(type == 4){
				P.push_back(teupor(stoi(x),stoi(y)));
				x = "";
				y = "";
			}
		}else if (c == 'x'){
			in_x = true;
		}else if (c == 'y'){
			in_x = false;
		}else{
			if(in_x){
				x+=c;
			}else{
				y+=c;
			}
		}
	}
	file.close();
}


void init_joueur(mobile & J,vector<vector<char>> T){
	int x = J.getX();
	int y = J.getY();
	auto it = T.at(x).begin();
	if(0<x<T.size() && 0<y<T.at(x).size()){
		T.at(x).at(y) = 'J';
	}
}

void vectorToTable(char T[LONGUEUR][LARGEUR], vector<element> & R, vector<element> & D, vector<element> & G, vector<element> & P){
	for(int i = 0; (unsigned)i< D.size();i++){
		T[D.at(i).getY()][D.at(i).getX()]='$';
	}
	for(int i = 0; (unsigned)i< R.size();i++){
		T[R.at(i).getY()][R.at(i).getX()]='X';
	}
	for(int i = 0; (unsigned)i< G.size();i++){
		T[G.at(i).getY()][G.at(i).getX()]='*';
	}
	for(int i = 0; (unsigned)i< P.size();i++){
		T[P.at(i).getY()][P.at(i).getX()]='-';
	}
}
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
void init_reumu(char T[LONGUEUR][LARGEUR]){
	for (int i = 0; i < LONGUEUR; i++){
		T[i][LARGEUR-1]='X';
		T[i][0]='X';
	}
	for (int i = 1; i < LARGEUR-1; i++){
		T[LONGUEUR-1][i]='X';
		T[0][i]='X';
	}
	draw(T);
}

void init(char T[LONGUEUR][LARGEUR], char ch){
	string d;
	string c;
	switch(ch){
		case '$' : 
			d = "diams";
			break;
		case 'X' :
			d = "murs";
			break;
		case '*' :
			d = "geurchar";
			break;
		case '-' : 
			d = "teupor";
			break;
		default :
			break;
	}
	while (c != "done"){
		cout<<"Ajouter des " +d+"!! (Si fini, taper done)"<<endl;
		cout<<"X = ";
		cin>>c;
		if(isdigit(c)){
			int a = stoi(c);
			cout<<"Y = ";
			cin>>c;
			if(isdigit(c)){
				int b = stoi(c);
				if(T[b][a] == 'X' && ch == '-'){
					T[b][a]= ch;
				}
				if(T[b][a] == '\0' && ch != '-'){
					T[b][a]= ch;
				}
				draw(T);
			}
		}	
	}
}

void tableToVector(char T[LONGUEUR][LARGEUR], vector<reumu> & R, vector<diams> & D, vector<geurchar> & G, vector<teupor> & P){
	for(int i = 0; i<LONGUEUR; i++){
		for(int j = 0; j<LARGEUR; j++){
			if(T[i][j] == 'X'){
				R.push_back(reumu(j,i));
			}else if(T[i][j] == '$'){
				D.push_back(diams(j,i));
			}else if(T[i][j] == '*'){
				G.push_back(geurchar(j,i));
			}else if(T[i][j] == '-'){
				P.push_back(teupor(j,i));
			}
		}
	}
}

void creationFichier(vector<reumu> & R, vector<diams> & D, vector<geurchar> & G, vector<teupor> & P){
	string fn;
	cout<<"Entrer le nom du fichier"<<endl;
	cin>>fn;
	fstream file;
	file.open(fn,ios::out);
	if(!file){
		cout<<"Création échouée"<<endl;
		return;
	}
	file<<'D';
	for(int i = 0; (unsigned)i< D.size();i++){
		file<<'x';
		file<<D.at(i).getX();
		file<<'y';
		file<<D.at(i).getY();
		file<<',';

	}
	file<<'R';
	for(int i = 0; (unsigned)i< R.size();i++){
		file<<'x';
		file<<R.at(i).getX();
		file<<'y';
		file<<R.at(i).getY();
		file<<',';
	}
	file<<'G';
	for(int i = 0; (unsigned)i< G.size();i++){
		file<<'x';
		file<<G.at(i).getX();
		file<<'y';
		file<<G.at(i).getY();
		file<<',';
	}	
	file<<'T';
	for(int i = 0; (unsigned)i< P.size();i++){
		file<<'x';
		file<<P.at(i).getX();
		file<<'y';
		file<<P.at(i).getY();
		file<<',';
	}
	file.close();
}