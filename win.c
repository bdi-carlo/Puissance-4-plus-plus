#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 6
#define M 7

int gagne(int grille[N][M]){
	int player1 = 0;
	int player2 = 0;
	int i, j, ligne, colonne;

	/*Test pour le joueur 1*/

	//Test en ligne
	for(i = 0; i < N; i++){
		player1 = 0;
		player2 = 0;
		for(j = 0; j < M; j++){
			if(grille[i][j] == 0)player1 = 0;
			else if(grille[i][j] == 2){
				player2++;
				if(player2 == 4)
					return 2;
			}
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
		player2 = 0;
		for(i = 0; i < N; i++){
			if(grille[i][j] == 0)player1 = 0;
			else if(grille[i][j] == 2){
				player2++;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 1){
				player1++;
				if(player1 == 4)
					return 1;
			}
		}
	}

	//Test diagonale droite
		player1 = 0;
		player2 = 0;
		i = 0;
		j = 3;
		while(i <= 3 && j >= 0){
			if(grille[i][j] == 0)player1 = 0;
			else if(grille[i][j] == 2){
				player2++;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 1){
				player1++;
				if(player1 == 4)
					return 1;
			}
			i++;
			j--;	
		}

		player1 = 0;
		player2 = 0;
		i = 0;
		j = 4;
		while(i <= 4 && j >= 0){
			if(grille[i][j] == 0)player1 = 0;
			else if(grille[i][j] == 2){
				player2++;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 1){
				player1++;
				if(player1 == 4)
					return 1;
			}
			i++;
			j--;	
		}

		player1 = 0;
		player2 = 0;
		i = 0;
		j = 5;
		while(i <= 5 && j >= 0){
			if(grille[i][j] == 0)player1 = 0;
			else if(grille[i][j] == 2){
				player2++;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 1){
				player1++;
				if(player1 == 4)
					return 1;
			}
			i++;
			j--;	
		}

		player1 = 0;
		player2 = 0;
		i = 0;
		j = 6;
		while(i <= 5 && j >= 1){
			if(grille[i][j] == 0)player1 = 0;
			else if(grille[i][j] == 2){
				player2++;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 1){
				player1++;
				if(player1 == 4)
					return 1;
			}
			i++;
			j--;	
		}

		player1 = 0;
		player2 = 0;
		i = 1;
		j = 6;
		while(i <= 5 && j >= 2){
			if(grille[i][j] == 0)player1 = 0;
			else if(grille[i][j] == 2){
				player2++;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 1){
				player1++;
				if(player1 == 4)
					return 1;
			}
			i++;
			j--;	
		}

		player1 = 0;
		player2 = 0;
		i = 2;
		j = 6;
		while(i <= 5 && j >= 3){
			if(grille[i][j] == 0)player1 = 0;
			else if(grille[i][j] == 2){
				player2++;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 1){
				player1++;
				if(player1 == 4)
					return 1;
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
			if(grille[i][j] == 0)player1 = 0;
			else if(grille[i][j] == 2){
				player2++;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 1){
				player1++;
				if(player1 == 4)
					return 1;
			}
			i++;
			j++;	
		}

		player1 = 0;
		player2 = 0;
		i = 0;
		j = 2;
		while(i <= 4 && j <= 6){
			if(grille[i][j] == 0)player1 = 0;
			else if(grille[i][j] == 2){
				player2++;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 1){
				player1++;
				if(player1 == 4)
					return 1;
			}
			i++;
			j++;	
		}

		player1 = 0;
		player2 = 0;
		i = 0;
		j = 1;
		while(i <= 5 && j <= 6){
			if(grille[i][j] == 0)player1 = 0;
			else if(grille[i][j] == 2){
				player2++;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 1){
				player1++;
				if(player1 == 4)
					return 1;
			}
			i++;
			j++;	
		}

		player1 = 0;
		player2 = 0;
		i = 0;
		j = 0;
		while(i <= 5 && j <= 5){
			if(grille[i][j] == 0)player1 = 0;
			else if(grille[i][j] == 2){
				player2++;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 1){
				player1++;
				if(player1 == 4)
					return 1;
			}
			i++;
			j++;	
		}

		player1 = 0;
		player2 = 0;
		i = 1;
		j = 0;
		while(i <= 5 && j <= 4){
			if(grille[i][j] == 0)player1 = 0;
			else if(grille[i][j] == 2){
				player2++;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 1){
				player1++;
				if(player1 == 4)
					return 1;
			}
			i++;
			j++;	
		}

		player1 = 0;
		player2 = 0;
		i = 2;
		j = 0;
		while(i <= 5 && j <= 3){
			if(grille[i][j] == 0)player1 = 0;
			else if(grille[i][j] == 2){
				player2++;
				if(player2 == 4)
					return 2;
			}
			else if(grille[i][j] == 1){
				player1++;
				if(player1 == 4)
					return 1;
			}
			i++;
			j++;	
		}

	return 0;
}
