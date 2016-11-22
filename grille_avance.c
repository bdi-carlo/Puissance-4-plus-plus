#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "new_fonctions.h"

#define couleur(param) printf("\033[%sm",param)
#define N 6
#define M 7

//Initialise à vide la grille du Puissance 4++
void init_matrice_avance(t_piece matrice[N][M]){
	int i,j;

	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			matrice[i][j].valeur_pion1 = 0;
			matrice[i][j].type1 = vide;
			matrice[i][j].valeur_pion2 = 0;
			matrice[i][j].type2 = vide;
		}
	}
}

//Affiche la grille du Puissance 4 du jeu en cours
void afficher_matrice_avance(t_piece matrice[N][M]){
	int i,j;

	printf("\n|					|\n");
	for(i = 0; i < N; i++){
		printf("|	  ");
		for(j = 0; j < M; j++){
			if(matrice[i][j].valeur_pion1 == 0 && matrice[i][j].valeur_pion2 == 0)printf(" . ");
			if(matrice[i][j].valeur_pion1 == 1 && matrice[i][j].type1 == creuse && matrice[i][j].valeur_pion2 == 0){
				couleur("31");
				printf(" O ");
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

void placer_pions_avance(t_piece grille[N][M], int colonne, int ligne, int num_joueur, int type){
	int i;

	colonne--;

	

	if(num_joueur == 1){
		int bloquante = 2 ;

		if(type == 1){		// pièce creuse
			if(grille[ligne-1][colonne] == 0) {		// case du dessous est vide
				grille[ligne][colonne].valeur_pion1 = 1;
				grille[ligne][colonne].type1 = creuse;
			}
			else if(grille[ligne-1][colonne] == 1) {		// case du dessous est creuse
				grille[ligne][colonne].valeur_pion1 = 1;
				grille[ligne][colonne].type1 = creuse;
			}
			else if(grille[ligne-1][colonne] == 2) {		// case du dessous est pleine
				grille[ligne][colonne].valeur_pion1 = 0;
				grille[ligne][colonne].type1 = vide;
				grille[ligne-1][colonne].valeur_pion2 = 1;
				grille[ligne-1][colonne].type1 = pleine ;
				grille[ligne-1][colonne].type2 = creuse;
				
			}
			else if(grille[ligne-1][colonne] == 3) {		// case du dessous est bloquante
				grille[ligne][colonne].valeur_pion1 = 1;
				grille[ligne][colonne].type1 = creuse;
			}
		}
		if(type == 2){		// pièce pleine
			if(grille[ligne-1][colonne] == 0) {		// case du dessous est vide
				grille[ligne][colonne].valeur_pion1 = 1;
				grille[ligne][colonne].type1 = pleine;
			}
			else if(grille[ligne-1][colonne] == 1) {		// case du dessous est creuse
				grille[ligne][colonne].valeur_pion1 = 0;
				grille[ligne][colonne].type1 = vide;
				grille[ligne-1][colonne].valeur_pion2 = 1;
				grille[ligne-1][colonne].type1 = creuse ;
				grille[ligne-1][colonne].type2 = pleine;
			}
			else if(grille[ligne-1][colonne] == 2) {		// case du dessous est pleine
				grille[ligne][colonne].valeur_pion1 = 1;
				grille[ligne][colonne].type1 = pleine;
				
			}
			else if(grille[ligne-1][colonne] == 3) {		// case du dessous est bloquante
				grille[ligne][colonne].valeur_pion1 = 1;
				grille[ligne][colonne].type1 = pleine;
			}
		}
		if(type == 3){		// pièce bloquante
			while (bloquante != 0) {
				if(grille[ligne-1][colonne] == 0) {		// case du dessous est vide
					grille[ligne][colonne].valeur_pion1 = 1;
					grille[ligne][colonne].type1 = bloquante;
					bloquante -- ;
				}
				else if(grille[ligne-1][colonne] == 1) {		// case du dessous est creuse
					grille[ligne][colonne].valeur_pion1 = 1;
					grille[ligne][colonne].type1 = bloquante;
					bloquante -- ;
				}
				else if(grille[ligne-1][colonne] == 2) {		// case du dessous est pleine
					grille[ligne][colonne].valeur_pion1 = 1;
					grille[ligne][colonne].type1 = bloquante;
					bloquante -- ;
				
				}
				else if(grille[ligne-1][colonne] == 3) {		// case du dessous est bloquante
					grille[ligne][colonne].valeur_pion1 = 1;
					grille[ligne][colonne].type1 = bloquante;
					bloquante -- ;
				}
			}
			if(bloquante == 0) printf("Vous avez utilisé vos 2 pièces bloquantes\n") ;
		}
		
	}


}