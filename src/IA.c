#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/classique.h"
#define N 6
#define M 7

int IA (int grille[N][M], int tour) {
	int best_col[7], valeur[N][M];
	int lgn = 0, col, player1, player2;
	int max = 0;
	int i, j;

	//Au premier tour l'IA joue aleatoirement
	if(tour == 1)
		return rand()%(8-1) +1;

	//Pour les autres tours
	else{
		//Test en ligne en partant de la gauche
		for(i = 0; i < N; i++){
			player1 = 0;
			player2 = 0;
			for(j = 0; j < M; j++){
				if(grille[i][j] == 1){
					player1++;
					player2 = 0;
					valeur[i][j] = 0;
				}
				else if(grille[i][j] == 2){
					player2++;
					player1 = 0;
					valeur[i][j] = 0;
				}
				else if(grille[i][j] == 0){
					if(player1 >= player2)
						valeur[i][j] = player1 + 1;
					else if(player2 > player1)
						valeur[i][j] = player2 + 1;
					
					player1 = 0;
					player2 = 0;
				}
			}
		}
		//Test en ligne en partant de la droite
		for(i = 0; i < N; i++){
			for(j = M - 1; j > 0; j--){
				if(grille[i][j] == 1){
					player1++;
					player2 = 0;
				}
				else if(grille[i][j] == 2){
					player2++;
					player1 = 0;
				}
				else if(grille[i][j] == 0){
					if(valeur[i][j] < player1+1 || valeur[i][j] < player2+1){
						if(player1 >= player2)
							valeur[i][j] = player1 + 1;
						else if(player2 > player1)
							valeur[i][j] = player2 + 1;
					}
					player1 = 0;
					player2 = 0;
				}
			}
		}
		
		for(i = 0; i < N; i++){
			printf("\n");
			for(j = 0; j < M; j++){
				printf(" %i ",valeur[i][j]);
			}
		}

		for(i = 0; i < N; i++){
			for(j = 0; j < M; j++){
				if(valeur[i][j] > max){
					max = valeur[i][j];
					col = j;
				}
			}
		}
		return col + 1;
	}
}

