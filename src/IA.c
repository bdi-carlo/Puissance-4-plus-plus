#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/new_fonctions.h"

#define ligne 6
#define colonne 7
#define L 20



void initialiser_grille(int grille_IA[ligne][colonne]) {
	int i, j ;
	for(i = 0 ; i < ligne ; i++) {
		for(j = 0 ; j < colonne ; j++) {
				grille[i][j] = 0 ;
				printf(".", grille_IA[i][j]) ;
		}
		printf("\n") ;
	}
}

void afficher_grille_IA(int grille[ligne][colonne], int grille_IA[ligne][colonne]) {

	
	int i, j ;
	

	for(i = 0 ; i < ligne ; i++) {
		for(j = 0 ; j < colonne ; j++) {
			if(grille[i][j] == 1) {
				printf("X", grille_IA[i][j]) ;
			}
			else if(grille[i][j] == 2) {
				printf("O", grille_IA[i][j]) ;
			}
			else if(grille[i][j] == 0) {
				printf(".", grille_IA[i][j]) ;
			}
		}
	}
}

int IA (int grille_IA[ligne][colonne])) {
	int best_col[colonne] ;
	int meilleur_coup = 0 ;
	int nb = 1 ;
	int lgn = 0, col ;
	
	for(col = 0 ; col < 7 ; col ++ ) {
		if(grille_IA[0][col] = 0) {
			lgn = choix_ligne(grille_IA, col) ;
			lgn-- ;
				if(grille_IA[lgn-1][col] == 1 {
					while(grille_IA[lgn][col] == 1) {
					if(nb == 4) 
						return col ;
					lgn-- ;
					nb++ ;
					
					}
				}
				else if(grille_IA[lgn-1][col] == 2 {
					while(grille_IA[lgn][col] == 2) {
					if(nb == 4) 
						return col ;
					lgn-- ;
					nb++ ;
					}
				}
		}
		nb = 0 ;
	}
}
				
	
	
