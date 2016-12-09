#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/classique.h"
#define N 6
#define M 7

int IA (int grille[N][M]) {
	int best_col[7] ;
	int nb = 1 ;
	int nb2 = 1 ;
	int lgn = 0, col ;
	int max = 0 ;
	int i, j ;
	
	for(col = 0 ; col < 7 ; col++) {
		lgn = choix_ligne(grille, col) ;

		// Test ligne vers la gauche
		for(j = col  ; j > col - 3 ; j--) {
			nb = 1 ;
			nb2 = 1 ;
			
			if(grille[lgn][j] == 0)
				break ;
			else if(grille[lgn][j] == 1){
				nb++;
				printf(" %i ",nb) ;
				nb2 = 1 ;
			}
			else if(grille[lgn][j] == 2){
				nb2++;
				nb = 1 ;
			}
			if(nb == 4 || nb2 == 4)
				return col ;
		}

		if(nb > nb2) 
			max = nb ;
		else
			max = nb2 ;

		// Test ligne vers la droite
		for(j = col + 1 ; j < col + 3 ; j++) {
			nb = 1 ;
			nb2 = 1 ;
			if(grille[lgn][j] == 0)
				break ;
			else if(grille[lgn][j] == 1){
				nb++;
				nb2 = 1 ;
			}
			else if(grille[lgn][j] == 2){
				nb2++;
				nb = 1 ;
			}
		}

		if(nb > max) 
			max = nb ;
		if(nb2 > max)
			max = nb2 ;
		
		
		//Test colonne vers le bas
		for(j = lgn - 1 ; j > lgn - 3; j--){
			nb = 1 ;
			nb2 = 1 ;
			if(grille[j][col] == 0)
				break ;
			else if(grille[j][col] == 1){
					nb++;
					nb2 = 1 ;
			}
			else if(grille[j][col] == 2){
				nb2++;
				nb = 1 ;
			}
		}

		if(nb > max) 
			max = nb ;
		if(nb2 > max)
			max = nb2 ;

		//Test diagonale desc.gauche
		for(j = col - 1, i = lgn-1; j > col - 3, i > lgn -3 ; j--,i--){
			nb = 1;
			nb2 = 1;
			if(grille[i][j] == 0)
				break ;
			else if(grille[i][j] == 1){
				nb++;
				nb2 = 1 ;
			}
			else if(grille[i][j] == 2){
				nb2++;
				nb = 1 ;
			}
		}
		
		if(nb > max) 
			max = nb ;
		if(nb2 > max)
			max = nb2 ;

		//Test diagonale mont.gauche
		for(j = col - 1, i = lgn + 1; j > col - 3, i < lgn + 3 ; j--,i++){
			nb = 1;
			nb2 = 1;
			if(grille[i][j] == 0)
				break ;
			else if(grille[i][j] == 1){
				nb++;
				nb2 = 1 ;
			}
			else if(grille[i][j] == 2){
				nb2++;
				nb = 1 ;
			}
		}

		if(nb > max) 
			max = nb ;
		if(nb2 > max)
			max = nb2 ;

		//Test diagonale haut.droite
		for(j = col + 1, i = lgn + 1; j < col + 3, i < lgn + 3 ; j++,i++){
			nb = 1;
			nb2 = 1;
			if(grille[i][j] == 0)
				break ;
			else if(grille[i][j] == 1){
				nb++;
				nb2 = 1 ;
			}
			else if(grille[i][j] == 2){
				nb2++;
				nb = 1 ;
			}
		}

		if(nb > max) 
			max = nb ;
		if(nb2 > max)
			max = nb2 ;

		//Test diagonale desc.droite
		for(j = col + 1, i = lgn - 1; j < col + 3, i > lgn - 3 ; j++,i--){
			nb = 1;
			nb2 = 1;
			if(grille[i][j] == 0)
				break ;
			else if(grille[i][j] == 1){
				nb++;
				nb2 = 1 ;
			}
			else if(grille[i][j] == 2){
				nb2++;
				nb = 1 ;
			}
		}
		if(nb > max) 
			max = nb ;
		if(nb2 > max)
			max = nb2 ;

		best_col[col] = max ;

	}
	/*for(i = 0 ; i < 7 ; i++) {
			if(best_col[i] == max)
				return i ;
	}*/
}
