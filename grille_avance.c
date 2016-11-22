#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define couleur(param) printf("\033[%sm",param)
#define N 6
#define M 7

//Affiche la grille du Puissance 4 du jeu en cours
void afficher_matrice_avance(t_piece matrice[N][M]){
	int i,j;

	printf("\n|					|\n");
	for(i = 0; i < N; i++){
		printf("|	  ");
		for(j = 0; j < M; j++){
			if(matrice[i][j] == 0)printf(" . ");

			//Joueur 1 
			
			if(matrice[i][j].valeur_pion1 == 1 && matrice[i][j].type1 == creuse){
				if(matrice[i][j].valeur_pion2 == 2 && matrice[i][j].type2 == pleine){
				couleur("41;34");
				printf(" Ø ");
				couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 3 && matrice[i][j].type2 == pleine){
				couleur("41;35");
				printf(" Ø ");
				couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 4 && matrice[i][j].type2 == pleine){
				couleur("41;32");
				printf(" Ø ");
				couleur("0");
				}
			
			}
			if(matrice[i][j].valeur_pion1 == 1 && matrice[i][j].type1 == pleine){
				if(matrice[i][j].valeur_pion2 == 2 && matrice[i][j].type2 == creuse){
				couleur("44;31");
				printf(" Ø ");
				couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 3 && matrice[i][j].type2 == creuse){
				couleur("45;31");
				printf(" Ø ");
				couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 4 && matrice[i][j].type2 == creuse){
				couleur("43;31");
				printf(" Ø ");
				couleur("0");
				}
			
			}
			if(matrice[i][j].valeur_pion1 == 1 && matrice[i][j].type1 == bloquante && matrice[i][j].valeur_pion2 == 0){
				couleur("31");
				printf(" @ ");
				couleur("0");
			}
	
			if(matrice[i][j].valeur_pion1 == 1 && matrice[i][j].type1 == creuse && matrice[i][j].valeur_pion2 == 0){
				couleur("31");
				printf(" O ");
				couleur("0");
			}

			if(matrice[i][j].valeur_pion1 == 1 && matrice[i][j].type1 == pleine && matrice[i][j].valeur_pion2 == 0){
				couleur("31");
				printf(" • ");
				couleur("0");
			}



			//Joueur 2
			if(matrice[i][j].valeur_pion1 == 2 && matrice[i][j].type1 == creuse){
				if(matrice[i][j].valeur_pion2 == 1 && matrice[i][j].type2 == pleine){
				couleur("44;31");
				printf(" Ø ");
				couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 3 && matrice[i][j].type2 == pleine){
				couleur("44;35");
				printf(" Ø ");
				couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 4 && matrice[i][j].type2 == pleine){
				couleur("44;32");
				printf(" Ø ");
				couleur("0");
				}
			
			}
			if(matrice[i][j].valeur_pion1 == 2 && matrice[i][j].type1 == pleine){
				if(matrice[i][j].valeur_pion2 == 1 && matrice[i][j].type2 == creuse){
				couleur("41;34");
				printf(" Ø ");
				couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 3 && matrice[i][j].type2 == creuse){
				couleur("45;34");
				printf(" Ø ");
				couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 4 && matrice[i][j].type2 == creuse){
				couleur("43;34");
				printf(" Ø ");
				couleur("0");
				}
			
			}
			if(matrice[i][j].valeur_pion1 == 2 && matrice[i][j].type1 == bloquante && matrice[i][j].valeur_pion2 == 0){
				couleur("34");
				printf(" @ ");
				couleur("0");
			}
	
			if(matrice[i][j].valeur_pion1 == 2 && matrice[i][j].type1 == creuse && matrice[i][j].valeur_pion2 == 0){
				couleur("34");
				printf(" O ");
				couleur("0");
			}

			if(matrice[i][j].valeur_pion1 == 2 && matrice[i][j].type1 == pleine && matrice[i][j].valeur_pion2 == 0){
				couleur("34");
				printf(" • ");
				couleur("0");
			}
			//Joueur 3
			if(matrice[i][j].valeur_pion1 == 3 && matrice[i][j].type1 == creuse){
				if(matrice[i][j].valeur_pion2 == 1 && matrice[i][j].type2 == pleine){
				couleur("45;31");
				printf(" Ø ");
				couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 2 && matrice[i][j].type2 == pleine){
				couleur("45;34");
				printf(" Ø ");
				couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 4 && matrice[i][j].type2 == pleine){
				couleur("45;32");
				printf(" Ø ");
				couleur("0");
				}
			
			}
			if(matrice[i][j].valeur_pion1 == 3 && matrice[i][j].type1 == pleine){
				if(matrice[i][j].valeur_pion2 == 1 && matrice[i][j].type2 == creuse){
				couleur("41;35");
				printf(" Ø ");
				couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 2 && matrice[i][j].type2 == creuse){
				couleur("44;35");
				printf(" Ø ");
				couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 4 && matrice[i][j].type2 == creuse){
				couleur("43;35");
				printf(" Ø ");
				couleur("0");
				}
			
			}
			if(matrice[i][j].valeur_pion1 == 3 && matrice[i][j].type1 == bloquante && matrice[i][j].valeur_pion2 == 0){
				couleur("35");
				printf(" @ ");
				couleur("0");
			}
	
			if(matrice[i][j].valeur_pion1 == 3 && matrice[i][j].type1 == creuse && matrice[i][j].valeur_pion2 == 0){
				couleur("35");
				printf(" O ");
				couleur("0");
			}

			if(matrice[i][j].valeur_pion1 == 3 && matrice[i][j].type1 == pleine && matrice[i][j].valeur_pion2 == 0){
				couleur("35");
				printf(" • ");
				couleur("0");
			}
			//Joueur 4
			if(matrice[i][j].valeur_pion1 == 4 && matrice[i][j].type1 == creuse){
				if(matrice[i][j].valeur_pion2 == 1 && matrice[i][j].type2 == pleine){
				couleur("43;31");
				printf(" Ø ");
				couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 3 && matrice[i][j].type2 == pleine){
				couleur("43;35");
				printf(" Ø ");
				couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 2 && matrice[i][j].type2 == pleine){
				couleur("43;34");
				printf(" Ø ");
				couleur("0");
				}
			
			}
			if(matrice[i][j].valeur_pion1 == 4 && matrice[i][j].type1 == pleine){
				if(matrice[i][j].valeur_pion2 == 1 && matrice[i][j].type2 == creuse){
				couleur("41;32");
				printf(" Ø ");
				couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 3 && matrice[i][j].type2 == creuse){
				couleur("45;32");
				printf(" Ø ");
				couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 2 && matrice[i][j].type2 == creuse){
				couleur("44;32");
				printf(" Ø ");
				couleur("0");
				}
			
			}
			if(matrice[i][j].valeur_pion1 == 4 && matrice[i][j].type1 == bloquante && matrice[i][j].valeur_pion2 == 0){
				couleur("32");
				printf(" @ ");
				couleur("0");
			}
	
			if(matrice[i][j].valeur_pion1 == 4 && matrice[i][j].type1 == creuse && matrice[i][j].valeur_pion2 == 0){
				couleur("32");
				printf(" O ");
				couleur("0");
			}

			if(matrice[i][j].valeur_pion1 == 4 && matrice[i][j].type1 == pleine && matrice[i][j].valeur_pion2 == 0){
				couleur("32");
				printf(" • ");
				couleur("0");
			}
		}
		printf("  	|\n");
	}
	printf("|					|");
	printf("\n|	   1  2  3  4  5  6  7  	|");
	printf("\n ---------------------------------------");
	printf("\n");
}

//Place le pion du joueur correspondant à la colonne qu'il veut
void placer_pions_avance(int grille[N][M], int colonne, int num_joueur){
	int i;
	int ligne = N-1;

	colonne--;
	
	for(i = 1; i <= N; i++){
		if(grille[N-i][colonne] == 1 || grille[N-i][colonne] == 2 || grille[N-i][colonne] == 3 || grille[N-i][colonne] == 4)ligne--;
	}

	if(num_joueur == 1)
		grille[ligne][colonne] = 1;
	else if(num_joueur == 2)
		grille[ligne][colonne] = 2;
	else if(num_joueur == 3)
		grille[ligne][colonne] = 3;
	else if(num_joueur == 4)
		grille[ligne][colonne] = 4;
}

//Parcours la grille du Puissance 4 pour savoir si un joueur a gagné ou non
int gagne_avance(int grille[N][M]){
	int player1 = 0;
	int player2 = 0;
	int player3 = 0;
	int player4 = 0;
	int i, j;

	/*Test*/

	//Test en ligne
	for(i = 0; i < N; i++){
		player1 = 0;
		player2 = 0;
		player3 = 0;
		player4 = 0;
		for(j = 0; j < M; j++){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				player3 = 0;
				player4 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				player3 = 0;
				player4 = 0;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 3){
				player3++;
				player1 = 0;
				player2 = 0;
				player4 = 0;
				if(player3 == 4)
					return 3;
			}
			else if(grille[i][j] == 4){
				player4++;
				player1 = 0;
				player2 = 0;
				player3 = 0;
				if(player4 == 4)
					return 4;
			}
			
			else {
				player1 = 0;
				player2 = 0;
				player3 = 0;
				player4 = 0;
			}
		}
	}

	//Test colonne
	for(j = 0; j < M; j++){
		player1 = 0;
		player2 = 0;
		player3 = 0;
		player4 = 0;
		for(i = 0; i < N; i++){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				player3 = 0;
				player4 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				player3 = 0;
				player4 = 0;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 3){
				player3++;
				player1 = 0;
				player2 = 0;
				player4 = 0;
				if(player3 == 4)
					return 3;
			}
			else if(grille[i][j] == 4){
				player4++;
				player1 = 0;
				player2 = 0;
				player3 = 0;
				if(player4 == 4)
					return 4;
			}
			else{
				player1 = 0;
				player2 = 0;
				player3 = 0;
				player4 = 0;
			}
		}
	}

	//Test diagonale droite
		player1 = 0;
		player2 = 0;
		player3 = 0;
		player4 = 0;
		i = 0;
		j = 3;
		while(i <= 3 && j >= 0){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				player3 = 0;
				player4 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				player3 = 0;
				player4 = 0;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 3){
				player3++;
				player1 = 0;
				player2 = 0;
				player4 = 0;
				if(player3 == 4)
					return 3;
			}
			else if(grille[i][j] == 4){
				player4++;
				player1 = 0;
				player2 = 0;
				player3 = 0;
				if(player4 == 4)
					return 4;
			}
			else{
				player1 = 0;
				player2 = 0;
				player3 = 0;
				player4 = 0;
			}
			i++;
			j--;	
		}

		player1 = 0;
		player2 = 0;
		player3 = 0;
		player4 = 0;
		i = 0;
		j = 4;
		while(i <= 4 && j >= 0){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				player3 = 0;
				player4 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				player3 = 0;
				player4 = 0;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 3){
				player3++;
				player1 = 0;
				player2 = 0;
				player4 = 0;
				if(player3 == 4)
					return 3;
			}
			else if(grille[i][j] == 4){
				player4++;
				player1 = 0;
				player2 = 0;
				player3 = 0;
				if(player4 == 4)
					return 4;
			}
			else{
				player1 = 0;
				player2 = 0;
				player3 = 0;
				player4 = 0;
			}
			i++;
			j--;	
		}

		player1 = 0;
		player2 = 0;
		player3 = 0;
		player4 = 0;
		i = 0;
		j = 5;
		while(i <= 5 && j >= 0){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				player3 = 0;
				player4 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				player3 = 0;
				player4 = 0;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 3){
				player3++;
				player1 = 0;
				player2 = 0;
				player4 = 0;
				if(player3 == 4)
					return 3;
			}
			else if(grille[i][j] == 4){
				player4++;
				player1 = 0;
				player2 = 0;
				player3 = 0;
				if(player4 == 4)
					return 4;
			}
			else{
				player1 = 0;
				player2 = 0;
				player3 = 0;
				player4 = 0;
			}
			i++;
			j--;	
		}

		player1 = 0;
		player2 = 0;
		player3 = 0;
		player4 = 0;
		i = 0;
		j = 6;
		while(i <= 5 && j >= 1){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				player3 = 0;
				player4 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				player3 = 0;
				player4 = 0;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 3){
				player3++;
				player1 = 0;
				player2 = 0;
				player4 = 0;
				if(player3 == 4)
					return 3;
			}
			else if(grille[i][j] == 4){
				player4++;
				player1 = 0;
				player2 = 0;
				player3 = 0;
				if(player4 == 4)
					return 4;
			}
			else{
				player1 = 0;
				player2 = 0;
				player3 = 0;
				player4 = 0;
			}
			i++;
			j--;	
		}

		player1 = 0;
		player2 = 0;
		player3 = 0;
		player4 = 0;
		i = 1;
		j = 6;
		while(i <= 5 && j >= 2){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				player3 = 0;
				player4 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				player3 = 0;
				player4 = 0;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 3){
				player3++;
				player1 = 0;
				player2 = 0;
				player4 = 0;
				if(player3 == 4)
					return 3;
			}
			else if(grille[i][j] == 4){
				player4++;
				player1 = 0;
				player2 = 0;
				player3 = 0;
				if(player4 == 4)
					return 4;
			}
			else{
				player1 = 0;
				player2 = 0;
				player3 = 0;
				player4 = 0;
			}
			i++;
			j--;	
		}

		player1 = 0;
		player2 = 0;
		player3 = 0;
		player4 = 0;
		i = 2;
		j = 6;
		while(i <= 5 && j >= 3){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				player3 = 0;
				player4 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				player3 = 0;
				player4 = 0;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 3){
				player3++;
				player1 = 0;
				player2 = 0;
				player4 = 0;
				if(player3 == 4)
					return 3;
			}
			else if(grille[i][j] == 4){
				player4++;
				player1 = 0;
				player2 = 0;
				player3 = 0;
				if(player4 == 4)
					return 4;
			}
			else{
				player1 = 0;
				player2 = 0;
				player3 = 0;
				player4 = 0;
			}
			i++;
			j--;	
		}
	
	
	//Test diagonale gauche
		player1 = 0;
		player2 = 0;
		player3 = 0;
		player4 = 0;
		i = 0;
		j = 3;
		while(i <= 3 && j <= 6){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				player3 = 0;
				player4 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				player3 = 0;
				player4 = 0;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 3){
				player3++;
				player1 = 0;
				player2 = 0;
				player4 = 0;
				if(player3 == 4)
					return 3;
			}
			else if(grille[i][j] == 4){
				player4++;
				player1 = 0;
				player2 = 0;
				player3 = 0;
				if(player4 == 4)
					return 4;
			}
			else{
				player1 = 0;
				player2 = 0;
				player3 = 0;
				player4 = 0;
			}
			i++;
			j++;	
		}

		player1 = 0;
		player2 = 0;
		player3 = 0;
		player4 = 0;
		i = 0;
		j = 2;
		while(i <= 4 && j <= 6){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				player3 = 0;
				player4 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				player3 = 0;
				player4 = 0;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 3){
				player3++;
				player1 = 0;
				player2 = 0;
				player4 = 0;
				if(player3 == 4)
					return 3;
			}
			else if(grille[i][j] == 4){
				player4++;
				player1 = 0;
				player2 = 0;
				player3 = 0;
				if(player4 == 4)
					return 4;
			}
			else{
				player1 = 0;
				player2 = 0;
				player3 = 0;
				player4 = 0;
			}
			i++;
			j++;	
		}

		player1 = 0;
		player2 = 0;
		player3 = 0;
		player4 = 0;
		i = 0;
		j = 1;
		while(i <= 5 && j <= 6){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				player3 = 0;
				player4 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				player3 = 0;
				player4 = 0;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 3){
				player3++;
				player1 = 0;
				player2 = 0;
				player4 = 0;
				if(player3 == 4)
					return 3;
			}
			else if(grille[i][j] == 4){
				player4++;
				player1 = 0;
				player2 = 0;
				player3 = 0;
				if(player4 == 4)
					return 4;
			}
			else{
				player1 = 0;
				player2 = 0;
				player3 = 0;
				player4 = 0;
			}
			i++;
			j++;	
		}

		player1 = 0;
		player2 = 0;
		player3 = 0;
		player4 = 0;
		i = 0;
		j = 0;
		while(i <= 5 && j <= 5){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				player3 = 0;
				player4 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				player3 = 0;
				player4 = 0;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 3){
				player3++;
				player1 = 0;
				player2 = 0;
				player4 = 0;
				if(player3 == 4)
					return 3;
			}
			else if(grille[i][j] == 4){
				player4++;
				player1 = 0;
				player2 = 0;
				player3 = 0;
				if(player4 == 4)
					return 4;
			}
			else{
				player1 = 0;
				player2 = 0;
				player3 = 0;
				player4 = 0;
			}
			i++;
			j++;	
		}

		player1 = 0;
		player2 = 0;
		player3 = 0;
		player4 = 0;
		i = 1;
		j = 0;
		while(i <= 5 && j <= 4){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				player3 = 0;
				player4 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				player3 = 0;
				player4 = 0;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 3){
				player3++;
				player1 = 0;
				player2 = 0;
				player4 = 0;
				if(player3 == 4)
					return 3;
			}
			else if(grille[i][j] == 4){
				player4++;
				player1 = 0;
				player2 = 0;
				player3 = 0;
				if(player4 == 4)
					return 4;
			}
			else{
				player1 = 0;
				player2 = 0;
				player3 = 0;
				player4 = 0;
			}
			i++;
			j++;	
		}

		player1 = 0;
		player2 = 0;
		player3 = 0;
		player4 = 0;
		i = 2;
		j = 0;
		while(i <= 5 && j <= 3){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				player3 = 0;
				player4 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				player3 = 0;
				player4 = 0;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 3){
				player3++;
				player1 = 0;
				player2 = 0;
				player4 = 0;
				if(player3 == 4)
					return 3;
			}
			else if(grille[i][j] == 4){
				player4++;
				player1 = 0;
				player2 = 0;
				player3 = 0;
				if(player4 == 4)
					return 4;
			}
			else{
				player1 = 0;
				player2 = 0;
				player3 = 0;
				player4 = 0;
			}
			i++;
			j++;	
		}

	return 0;
}
