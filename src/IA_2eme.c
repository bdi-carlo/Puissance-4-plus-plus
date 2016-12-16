#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/classique.h"
#define N 6
#define M 7
#define L 50

int IA (int grille[N][M], int tour) {
	int tab_max[L], valeur[N][M];
	int col, player1, player2;
	int valeur_max = 2;
	int i, j, k ;

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
			player1 = 0;
			player2 = 0;
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
					if(valeur[i][j] < player1 + 1 || valeur[i][j] < player2 + 1){
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
		
		//Test colonne
		for(j = 0; j < M; j++){
			player1 = 0;
			player2 = 0;
			for(i = N-1; i > 0; i--){
				if(grille[i][j] == 1){
					player1++;
					player2 = 0;
				}
				else if(grille[i][j] == 2){
					player2++;
					player1 = 0;
				}
				else if(grille[i][j] == 0){
						if(valeur[i][j] < player1 + 1 || valeur[i][j] < player2 + 1){
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
		
		//Test diagonale droite
		for(k = 5; k >= 3; k--){
			player1 = 0;
			player2 = 0;
			j = 0;

			i = k;
			while(i >= 0 && j <= k-1){
				if(grille[i][j] == 1){
					player1++;
					player2 = 0;
				}
				else if(grille[i][j] == 2){
					player2++;
					player1 = 0;
				}
				else if(grille[i][j] == 0){
					if(valeur[i][j] < player1 + 1 || valeur[i][j] < player2 + 1){
						if(player1 >= player2)
							valeur[i][j] = player1 + 1;
						else if(player2 > player1)
							valeur[i][j] = player2 + 1;
					}
					player1 = 0;
					player2 = 0;
				}
				i--;
				j++;	
			}
		}
			

		for(k = 1; k <= 3; k++){
			player1 = 0;
			player2 = 0;
			i = 5;

			j = k;
			while(i >= k-1 && j <= 6){
				if(grille[i][j] == 1){
					player1++;
					player2 = 0;
				}
				else if(grille[i][j] == 2){
					player2++;
					player1 = 0;
				}
				else if(grille[i][j] == 0){
					if(valeur[i][j] < player1 + 1 || valeur[i][j] < player2 + 1){
						if(player1 >= player2)
							valeur[i][j] = player1 + 1;
						else if(player2 > player1)
							valeur[i][j] = player2 + 1;
					}
					player1 = 0;
					player2 = 0;
				}
				i--;
				j++;	
			}	
		}	
		
		//Test diagonale gauche
		for(k = 3; k <= 5; k++){
			player1 = 0;
			player2 = 0;
			j = 6;

			i = k;
			while(i >= 0 && j >= 6-k){
				if(grille[i][j] == 1){
					player1++;
					player2 = 0;
				}
				else if(grille[i][j] == 2){
					player2++;
					player1 = 0;
				}
				else if(grille[i][j] == 0){
					if(valeur[i][j] < player1 + 1 || valeur[i][j] < player2 + 1){
						if(player1 >= player2)
							valeur[i][j] = player1 + 1;
						else if(player2 > player1)
							valeur[i][j] = player2 + 1;
					}
					player1 = 0;
					player2 = 0;
				}
				i--;
				j--;	
			}
		}

		for(k = 5; k >=3; k--){
			player1 = 0;
			player2 = 0;
			i = 5;

			j = k;
			while(i <= 5-k && j <= 5){
				if(grille[i][j] == 1){
					player1++;
					player2 = 0;
				}
				else if(grille[i][j] == 2){
					player2++;
					player1 = 0 ;
				}
				else if(grille[i][j] == 0){
					if(valeur[i][j] < player1 + 1 || valeur[i][j] < player2 + 1){
						if(player1 >= player2)
							valeur[i][j] = player1 + 1;
						else if(player2 > player1)
							valeur[i][j] = player2 + 1;
					}
					player1 = 0;
					player2 = 0;
				}
				i--;
				j--;	
			}
		}
		for(i = 0; i < N; i++){
			printf("\n");
			for(j = 0; j < M; j++){
				printf("%i ",valeur[i][j]);
			}
			
		}

		for(i = 0, k = 0; i < N; i++){
			for(j = 0; j < M; j++){
				if(valeur[i][j] >= valeur_max){
					if(valeur_max > tab_max[k]){
						tab_max[k] = valeur_max ;
						valeur_max = valeur[i][j];
					}
					else if(tab_max[k] == valeur_max){
						k++ ;
						tab_max[k] = valeur_max ;
					}
				}
				
			}
				
		}
		col = tab_max[rand()%(k+1)] + 1;
		return col + 1;
	}
}

