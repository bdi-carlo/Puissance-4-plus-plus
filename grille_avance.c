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
			//Cas où il n'y a pas de pion
			if(matrice[i][j].valeur_pion1 == 0 && matrice[i][j].valeur_pion2 == 0)printf(" . ");

/******************************************************* JOUEUR 1 **********************************************************/

			//Quand le joueur 1 joue une piece creuse et qu'un autre joueur joue une piece pleine par dessus
			/*else if(matrice[i][j].valeur_pion1 == 1 && matrice[i][j].type1 == creuse){ 
				if(matrice[i][j].valeur_pion2 == 2 && matrice[i][j].type2 == pleine){
				couleur("41;34");
				printf(" 0 ");
				couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 3 && matrice[i][j].type2 == pleine){
				couleur("41;35");
				printf(" 0 ");
				couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 4 && matrice[i][j].type2 == pleine){
				couleur("41;32");
				printf(" 0 ");
				couleur("0");
				}
			
			}

			//Quand le joueur 1 joue une piece pleine et qu'un autre joueur joue une piece creuse par dessus
			else if(matrice[i][j].valeur_pion1 == 1 && matrice[i][j].type1 == pleine){
				if(matrice[i][j].valeur_pion2 == 2 && matrice[i][j].type2 == creuse){
				couleur("44;31");
				printf(" 0 ");
				couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 3 && matrice[i][j].type2 == creuse){
				couleur("45;31");
				printf(" 0 ");
				couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 4 && matrice[i][j].type2 == creuse){
				couleur("43;31");
				printf(" 0 ");
				couleur("0");
				}
			
			}*/

			//Quand le joueur 1 joue une piece bloquante ou qu'aucun autre joueur ne joue de piece par desssus
			else if(matrice[i][j].valeur_pion1 == 1 && matrice[i][j].valeur_pion2 == 0){
				//Bloquante
				if(matrice[i][j].type1 == bloquante){
					couleur("31");
					printf(" ⨂ ");
					couleur("0");
				}
				//Creuse
				else if(matrice[i][j].type1 == creuse){
					couleur("31");
					printf(" 〇 ");
					couleur("0");
				}
				//Pleine
				else if(matrice[i][j].type1 == pleine){
					couleur("31");
					printf(" ⯄ ");
					couleur("0");
				}
			}

/******************************************************* JOUEUR 2 **********************************************************/

		}
		printf("  	|\n");
	}


	printf("|					|");
	printf("\n|	   1  2  3  4  5  6  7  	|");
	printf("\n ---------------------------------------");
	printf("\n");
}

//Retourne la bonne ligne
int choix_ligne_avance(t_piece matrice[N][M], int colonne){
	int i;
	int ligne = N-1;

	//Car l'utilisateur choisi une colonne entre 1 et 7 or la matrice est entre 0 et 6
	colonne--;
	
	//Boucle permettant de chercher la premiere la ligne sans pion
	for(i = 1; i <= N; i++){
		if(matrice[N-i][colonne].valeur_pion1 != 0)ligne--;
	}
	return ligne;
}

//Place le pion a une ligne donnee et une colonne donnee
void placer_pions_avance(t_piece matrice[N][M], int colonne, int ligne, int num_joueur, int type){
	int i;

	colonne--;

	if(num_joueur == 1){
		if(type == 1){
			matrice[ligne][colonne].valeur_pion1 = 1;
			matrice[ligne][colonne].type1 = creuse;
		}
		if(type == 2){
			matrice[ligne][colonne].valeur_pion1 = 1;
			matrice[ligne][colonne].type1 = pleine;
		}
		if(type == 3){
			matrice[ligne][colonne].valeur_pion1 = 1;
			matrice[ligne][colonne].type1 = bloquante;
		}
	}
}
