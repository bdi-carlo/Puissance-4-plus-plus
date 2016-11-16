#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 6
#define M 7

//Initialise à vide la grille du Puissance 4
void init_matrice(int matrice[N][M]){
	int i,j;

	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			matrice[i][j] = 0;
		}
	}
}

//Affiche la grille du Puissance 4 du jeu en cours
void afficher_matrice(int matrice[N][M]){
	int i,j;

	printf("\n");
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			if(matrice[i][j] == 0)printf(" . ");
			if(matrice[i][j] == 1)printf(" x ");
			if(matrice[i][j] == 2)printf(" o ");
		}
		printf("\n");
	}
	printf("\n 1  2  3  4  5  6  7\n");
	printf("\n");
}

//Place le pion du joueur correspondant à la colonne qu'il veut
int placer_pions(int matrice[N][M], int colonne, int num_joueur){
	int i;
	int ligne = N-1;

	colonne--;
	
	for(i = 1; i <= N; i++){
		if(matrice[N-i][colonne] == 1 || matrice[N-i][colonne] == 2)ligne--;
	}

	if(num_joueur == 1)
		matrice[ligne][colonne] = 1;
	else if(num_joueur == 2)
		matrice[ligne][colonne] = 2;
}

//Parcours la grille du Puissance 4 pour savoir si un joueur a gagné ou non
int gagne(int grille[N][M]){
	int player1 = 0;
	int player2 = 0;
	int i, j;

	/*Test pour le joueur 1*/

	//Test en ligne
	for(i = 0; i < N; i++){
		player1 = 0;
		player2 = 0;
		for(j = 0; j < M; j++){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				if(player2 == 4)
					return 2;
			}
			else{
				player1 = 0;
				player2 = 0;
			}
		}
	}

	//Test colonne
	for(j = 0; j < M; j++){
		player1 = 0;
		player2 = 0;
		for(i = 0; i < N; i++){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				if(player1 == 4)
					return 1;
			}
			if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				if(player2 == 4)
					return 2;
			}
			else{
				player1 = 0;
				player2 = 0;
			}
		}
	}

	//Test diagonale droite
		player1 = 0;
		player2 = 0;
		i = 0;
		j = 3;
		while(i <= 3 && j >= 0){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				if(player2 == 4)
					return 2;
			}
			else{
				player1 = 0;
				player2 = 0;
			}
			i++;
			j--;	
		}

		player1 = 0;
		player2 = 0;
		i = 0;
		j = 4;
		while(i <= 4 && j >= 0){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				if(player2 == 4)
					return 2;
			}
			else{
				player1 = 0;
				player2 = 0;
			}
			i++;
			j--;	
		}

		player1 = 0;
		player2 = 0;
		i = 0;
		j = 5;
		while(i <= 5 && j >= 0){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				if(player2 == 4)
					return 2;
			}
			else{
				player1 = 0;
				player2 = 0;
			}
			i++;
			j--;	
		}

		player1 = 0;
		player2 = 0;
		i = 0;
		j = 6;
		while(i <= 5 && j >= 1){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				if(player2 == 4)
					return 2;
			}
			else{
				player1 = 0;
				player2 = 0;
			}
			i++;
			j--;	
		}

		player1 = 0;
		player2 = 0;
		i = 1;
		j = 6;
		while(i <= 5 && j >= 2){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				if(player2 == 4)
					return 2;
			}
			else{
				player1 = 0;
				player2 = 0;
			}
			i++;
			j--;	
		}

		player1 = 0;
		player2 = 0;
		i = 2;
		j = 6;
		while(i <= 5 && j >= 3){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				if(player2 == 4)
					return 2;
			}
			else{
				player1 = 0;
				player2 = 0;
			}
			i++;
			j--;	
		}
	
	
	//Test diagonale gauche
		player1 = 0;
		player2 = 0;
		i = 0;
		j = 3;
		while(i <= 3 && j <= 6){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				if(player2 == 4)
					return 2;
			}
			else{
				player1 = 0;
				player2 = 0;
			}
			i++;
			j++;	
		}

		player1 = 0;
		player2 = 0;
		i = 0;
		j = 2;
		while(i <= 4 && j <= 6){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				if(player2 == 4)
					return 2;
			}
			else{
				player1 = 0;
				player2 = 0;
			}
			i++;
			j++;	
		}

		player1 = 0;
		player2 = 0;
		i = 0;
		j = 1;
		while(i <= 5 && j <= 6){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				if(player2 == 4)
					return 2;
			}
			else{
				player1 = 0;
				player2 = 0;
			}
			i++;
			j++;	
		}

		player1 = 0;
		player2 = 0;
		i = 0;
		j = 0;
		while(i <= 5 && j <= 5){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				if(player2 == 4)
					return 2;
			}
			else{
				player1 = 0;
				player2 = 0;
			}
			i++;
			j++;	
		}

		player1 = 0;
		player2 = 0;
		i = 1;
		j = 0;
		while(i <= 5 && j <= 4){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				if(player2 == 4)
					return 2;
			}
			else{
				player1 = 0;
				player2 = 0;
			}
			i++;
			j++;	
		}

		player1 = 0;
		player2 = 0;
		i = 2;
		j = 0;
		while(i <= 5 && j <= 3){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				if(player2 == 4)
					return 2;
			}
			else{
				player1 = 0;
				player2 = 0;
			}
			i++;
			j++;	
		}

	return 0;
}
