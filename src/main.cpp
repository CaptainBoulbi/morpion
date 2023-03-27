#include <iostream>

void afficherMap(char map[]){
	std::cout << "\n#########" << std::endl;
	for (int y = 0; y<3; y++){
		for (int x = 0; x<3; x++){
			std::cout << "#" << map[x+y*3] << "#";
		}
		std::cout << std::endl << "#########" << std::endl;
	}
	std::cout << std::endl;
}

void manche(char map[], int colone, int ligne, char joueur){
	map[(colone-1)+(ligne-1)*3] = joueur;
	colone = 0;
	ligne = 0;
	afficherMap(map);
}

int verifCaseVide(char map[], int colone, int ligne){
	return map[(colone-1)+(ligne-1)*3] == ' ';
}

char joueurSuivant(char joueur){
	if (joueur == 'X'){
		joueur = 'O';
	}else{
		joueur = 'X';
	}
	return joueur;
}

bool mapRempli(char map[]){
	int x = 0;
	while (map[x]!=' ' and x<9){
		x++;
	}
	return (9-x) == 0;
}

char egal(char a, char b, char c){
	if (a==b and b==c){
		return a;
	}
	return ' ';
}

bool victoire(char c){
	std::cout << "\nvictoire des " << c << std::endl;
	return true;
}

bool fin(char map[]){
	char res = ' ';
	for (int x=0; x<3; x++){
		if ((res = egal(map[x*3], map[x*3+1], map[x*3+2])) != ' '){ return victoire(res); }
	}

	for (int x=0; x<3; x++){
		if ((res = egal(map[x], map[x+3], map[x+6])) != ' '){ return victoire(res); }
	}

	if ((res = egal(map[0], map[4], map[8])) != ' '){ return victoire(res); }

	if ((res = egal(map[2], map[4], map[6])) != ' '){ return victoire(res); }

	if (mapRempli(map)){
		std::cout << "\négalité" << std::endl;
		return true;
	}

	return false;
}

int main(){
	char map[] = "         ";
	char joueur = 'O';
	int colone = 0;
	int ligne = 0;

	while (!fin(map)){
		joueur = joueurSuivant(joueur);
		std::cout << "tour joueur " << joueur << "\n" << std::endl;

		do{
			std::cout << "entrez colone : ";
			std::cin >> colone;
		}while(colone > 3 or colone < 1);

		do{
			std::cout << "entrez ligne : ";
			std::cin >> ligne;
		}while(ligne > 3 or ligne < 1);

		if (verifCaseVide(map, colone, ligne)){
			manche(map, colone, ligne, joueur);
		}else{
			joueur = joueurSuivant(joueur);
			std::cout << "\ncet case a deja une valeur\n" << std::endl;
		}

	}

	return 0;
}
