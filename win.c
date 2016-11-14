#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 6
#define M 7

int gagne(int grille[N][M]){
	int player1 = 0;
	int player2 = 0;
	int i, j;

	/*Test pour le joueur 1*/

	//Test en ligne
	for(i = 0; i < N; i++){
		player1 = 0;
		for(j = 0; j < M; j++){
			if(grille[i][j] == 0)player1 = 0;
			else if(grille[i][j] == 2)player1 = 0;
			else if(grille[i][j] == 1){
				player1++;
				if(player1 == 4)
					return 1;
			}
		}
	}

	//Test colonne
	for(j = 0; j < M; j++){
		player1 = 0;
		for(i = 0; i < N; i++){
			if(grille[i][j] == 0)player1 = 0;
			else if(grille[i][j] == 2)player1 = 0;
			else if(grille[i][j] == 1){
				player1++;
				if(player1 == 4)
					return 1;
			}
		}
	}

	//Test diagonale droite

	
	//Test diagonale gauche
	

	return 0;
}
