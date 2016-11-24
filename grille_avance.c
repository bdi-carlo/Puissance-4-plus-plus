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

<<<<<<< HEAD
//Verifie si la grille est pleine ou non
int grille_pleine(t_piece matrice[N][M]){
	int i,j;

	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			//Si il n'y a aucun pion la grille n'est pas remplie
			if(matrice[i][j].valeur_pion1 == 0)
				return 0;

			//Si il n'y a pas deux pions sur la meme case alors qu'il n'y a pas de piece bloquante alors la grille n'est pas remplie
			else if(matrice[i][j].valeur_pion2 == 0 && matrice[i][j].type1 != bloquante)
				return 0;
		}
	}
	return 1;
}

=======
>>>>>>> f629ae424dccd42bbe86405465e0d2b50138b592
//Affiche la grille du Puissance 4 du jeu en cours
void afficher_matrice_avance(t_piece matrice[N][M]){
	int i,j;

	printf("\n|					|\n");
	for(i = 0; i < N; i++){
		printf("|	  ");
		for(j = 0; j < M; j++){
			if(matrice[i][j].valeur_pion1 == 0 && matrice[i][j].valeur_pion2 == 0)printf(" . ");
<<<<<<< HEAD

/******************************************************* JOUEUR 1 **********************************************************/

			//Quand le joueur 1 joue une piece bloquante ou qu'aucun autre joueur ne joue de piece par desssus
			else if(matrice[i][j].valeur_pion1 == 1 && matrice[i][j].valeur_pion2 == 0){
				//Bloquante
				if(matrice[i][j].type1 == bloquante){
					couleur("31");
					printf(" @ ");
					couleur("0");
				}
				//Creuse
				else if(matrice[i][j].type1 == creuse){
					couleur("31");
					printf(" 〇");
					couleur("0");
				}
				//Pleine
				else if(matrice[i][j].type1 == pleine){
					couleur("31");
					printf(" ⯄ ");
					couleur("0");
				}
			}

			//Quand le joueur 1 a joue une piece pleine et qu'un autre joueur joue une piece creuse par dessus
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
			
			}

			//Quand le joueur 1 a joue une piece creuse et qu'un autre joueur joue une piece pleine par dessus
			else if(matrice[i][j].valeur_pion1 == 1 && matrice[i][j].type1 == creuse){ 
				if(matrice[i][j].valeur_pion2 == 2 && matrice[i][j].type2 == pleine){
				couleur("41;34");
				printf(" 0 ");
				couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 3 && matrice[i][j].type2 == pleine){
				couleur("41;35");
				printf(" 0 ");
=======
			if(matrice[i][j].valeur_pion1 == 1 && matrice[i][j].type1 == creuse && matrice[i][j].valeur_pion2 == 0){
				couleur("31");
				printf(" O ");
>>>>>>> f629ae424dccd42bbe86405465e0d2b50138b592
				couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 4 && matrice[i][j].type2 == pleine){
				couleur("41;32");
				printf(" 0 ");
				couleur("0");
				}
			
			}

/******************************************************* JOUEUR 2 **********************************************************/

			//Quand le joueur 2 joue une piece bloquante ou qu'aucun autre joueur ne joue de piece par desssus
			else if(matrice[i][j].valeur_pion1 == 2 && matrice[i][j].valeur_pion2 == 0){
				//Bloquante
				if(matrice[i][j].type1 == bloquante){
					couleur("34");
					printf(" @ ");
					couleur("0");
				}
				//Creuse
				else if(matrice[i][j].type1 == creuse){
					couleur("34");
					printf(" 〇");
					couleur("0");
				}
				//Pleine
				else if(matrice[i][j].type1 == pleine){
					couleur("34");
					printf(" ⯄ ");
					couleur("0");
				}
			}

			//Quand le joueur 2 a joue une piece creuse et qu'un autre joueur joue une piece pleine par dessus
			else if(matrice[i][j].valeur_pion1 == 2 && matrice[i][j].type1 == creuse){
			
				if(matrice[i][j].valeur_pion2 == 1 && matrice[i][j].type2 == pleine){
					couleur("44;31");
					printf(" 0 ");
					couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 3 && matrice[i][j].type2 == pleine){
					couleur("44;35");
					printf(" 0 ");
					couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 4 && matrice[i][j].type2 == pleine){
					couleur("44;32");
					printf(" 0 ");
					couleur("0");
				}
			
			}
			//Quand le joueur 2 a joue une piece pleine et qu'un autre joueur joue une piece creuse par dessus
			else if(matrice[i][j].valeur_pion1 == 2 && matrice[i][j].type1 == pleine){
			
				if(matrice[i][j].valeur_pion2 == 1 && matrice[i][j].type2 == creuse){
					couleur("41;34");
					printf(" 0 ");
					couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 3 && matrice[i][j].type2 == creuse){
					couleur("45;34");
					printf(" 0 ");
					couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 4 && matrice[i][j].type2 == creuse){
					couleur("43;34");
					printf(" 0 ");
					couleur("0");
				}
			
			}


/******************************************************* JOUEUR 3 **********************************************************/

			//Quand le joueur 3 joue une piece bloquante ou qu'aucun autre joueur ne joue de piece par desssus
			else if(matrice[i][j].valeur_pion1 == 3 && matrice[i][j].valeur_pion2 == 0){
				//Bloquante
				if(matrice[i][j].type1 == bloquante){
					couleur("35");
					printf(" @ ");
					couleur("0");
				}
				//Creuse
				else if(matrice[i][j].type1 == creuse){
					couleur("35");
					printf(" 〇");
					couleur("0");
				}
				//Pleine
				else if(matrice[i][j].type1 == pleine){
					couleur("35");
					printf(" ⯄ ");
					couleur("0");
				}
			}

			//Quand le joueur 3 a joue une piece creuse et qu'un autre joueur joue une piece pleine par dessus
			else if(matrice[i][j].valeur_pion1 == 3 && matrice[i][j].type1 == creuse){
			
				if(matrice[i][j].valeur_pion2 == 1 && matrice[i][j].type2 == pleine){
					couleur("45;31");
					printf(" 0 ");
					couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 2 && matrice[i][j].type2 == pleine){
					couleur("45;34");
					printf(" 0 ");
					couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 4 && matrice[i][j].type2 == pleine){
					couleur("45;32");
					printf(" 0 ");
					couleur("0");
				}
			
			}
			//Quand le joueur 3 a joue une piece pleine et qu'un autre joueur joue une piece creuse par dessus
			else if(matrice[i][j].valeur_pion1 == 3 && matrice[i][j].type1 == pleine){
			
				if(matrice[i][j].valeur_pion2 == 1 && matrice[i][j].type2 == creuse){
					couleur("41;35");
					printf(" 0 ");
					couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 2 && matrice[i][j].type2 == creuse){
					couleur("44;35");
					printf(" 0 ");
					couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 4 && matrice[i][j].type2 == creuse){
					couleur("43;35");
					printf(" 0 ");
					couleur("0");
				}
			
			}
/******************************************************* JOUEUR 4 **********************************************************/

			//Quand le joueur 4 joue une piece bloquante ou qu'aucun autre joueur ne joue de piece par desssus
			else if(matrice[i][j].valeur_pion1 == 4 && matrice[i][j].valeur_pion2 == 0){
				//Bloquante
				if(matrice[i][j].type1 == bloquante){
					couleur("32");
					printf(" @ ");
					couleur("0");
				}
				//Creuse
				else if(matrice[i][j].type1 == creuse){
					couleur("32");
					printf(" 〇");
					couleur("0");
				}
				//Pleine
				else if(matrice[i][j].type1 == pleine){
					couleur("32");
					printf(" ⯄ ");
					couleur("0");
				}
			}

			//Quand le joueur 4 a joue une piece creuse et qu'un autre joueur joue une piece pleine par dessus
			else if(matrice[i][j].valeur_pion1 == 4 && matrice[i][j].type1 == creuse){
			
				if(matrice[i][j].valeur_pion2 == 1 && matrice[i][j].type2 == pleine){
					couleur("43;31");
					printf(" 0 ");
					couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 2 && matrice[i][j].type2 == pleine){
					couleur("43;35");
					printf(" 0 ");
					couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 3 && matrice[i][j].type2 == pleine){
					couleur("43;34");
					printf(" 0 ");
					couleur("0");
				}
			
			}
			//Quand le joueur 4 a joue une piece pleine et qu'un autre joueur joue une piece creuse par dessus
			else if(matrice[i][j].valeur_pion1 == 4 && matrice[i][j].type1 == pleine){
			
				if(matrice[i][j].valeur_pion2 == 1 && matrice[i][j].type2 == creuse){
					couleur("41;32");
					printf(" 0 ");
					couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 2 && matrice[i][j].type2 == creuse){
					couleur("45;32");
					printf(" 0 ");
					couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 3 && matrice[i][j].type2 == creuse){
					couleur("44;32");
					printf(" 0 ");
					couleur("0");
				}
			
			}
		}
		printf("  	|\n");
	}


	printf("|					|");
	printf("\n|	   1  2  3  4  5  6  7  	|");
	printf("\n ---------------------------------------");
	printf("\n");
}
<<<<<<< HEAD
//Retourne la premiere ligne libre
int choix_ligne_avance(t_piece matrice[N][M], int colonne){
=======

void placer_pions_avance(t_piece grille[N][M], int colonne, int ligne, int num_joueur, int type){
>>>>>>> f629ae424dccd42bbe86405465e0d2b50138b592
	int i;

	//Car l'utilisateur choisi une colonne entre 1 et 7 or la matrice est entre 0 et 6
	colonne--;
<<<<<<< HEAD
	
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

/******************************************************* JOUEUR 1 **********************************************************/

	if(num_joueur == 1){
		if(type == 1){
			//Verifie si en dessous il y a un ou deux pions en dessous et si ils peuvent fusionner
			if(matrice[ligne+1][colonne].valeur_pion1 != 1 && matrice[ligne+1][colonne].type1 == pleine && matrice[ligne+1][colonne].valeur_pion2 == 0){
				matrice[ligne+1][colonne].valeur_pion2 = 1;
				matrice[ligne+1][colonne].type2 = creuse;
			}
			else{
				matrice[ligne][colonne].valeur_pion1 = 1;
				matrice[ligne][colonne].type1 = creuse;
			}
		}
		else if(type == 2){
			//Verifie si en dessous il y a un pion
			if(matrice[ligne+1][colonne].valeur_pion1 != 1 && matrice[ligne+1][colonne].type1 == creuse && matrice[ligne+1][colonne].valeur_pion2 == 0){
				matrice[ligne+1][colonne].valeur_pion2 = 1;
				matrice[ligne+1][colonne].type2 = pleine;
			}

			else{
				matrice[ligne][colonne].valeur_pion1 = 1;
				matrice[ligne][colonne].type1 = pleine;
			}
		}
		else if(type == 3){
			matrice[ligne][colonne].valeur_pion1 = 1;
			matrice[ligne][colonne].type1 = bloquante;
		}
	}

/******************************************************* JOUEUR 2 **********************************************************/

	else if(num_joueur == 2){
		if(type == 1){
			//Verifie si en dessous il y a un pion
			if(matrice[ligne+1][colonne].valeur_pion1 != 2 && matrice[ligne+1][colonne].type1 == pleine && matrice[ligne+1][colonne].valeur_pion2 == 0){
				matrice[ligne+1][colonne].valeur_pion2 = 2;
				matrice[ligne+1][colonne].type2 = creuse;
			}
			else{
				matrice[ligne][colonne].valeur_pion1 = 2;
				matrice[ligne][colonne].type1 = creuse;
			}
		}
		else if(type == 2){
			//Verifie si en dessous il y a un pion
			if(matrice[ligne+1][colonne].valeur_pion1 != 2 && matrice[ligne+1][colonne].type1 == creuse && matrice[ligne+1][colonne].valeur_pion2 == 0){
				matrice[ligne+1][colonne].valeur_pion2 = 2;
				matrice[ligne+1][colonne].type2 = pleine;
			}

			else{
				matrice[ligne][colonne].valeur_pion1 = 2;
				matrice[ligne][colonne].type1 = pleine;
			}
		}
		else if(type == 3){
			matrice[ligne][colonne].valeur_pion1 = 2;
			matrice[ligne][colonne].type1 = bloquante;
		}
	}

/******************************************************* JOUEUR 3 **********************************************************/

	else if(num_joueur == 3){
		if(type == 1){
			//Verifie si en dessous il y a un pion
			if(matrice[ligne+1][colonne].valeur_pion1 != 3 && matrice[ligne+1][colonne].type1 == pleine && matrice[ligne+1][colonne].valeur_pion2 == 0){
				matrice[ligne+1][colonne].valeur_pion2 = 3;
				matrice[ligne+1][colonne].type2 = creuse;
			}
			else{
				matrice[ligne][colonne].valeur_pion1 = 3;
				matrice[ligne][colonne].type1 = creuse;
			}
		}
		else if(type == 2){
			//Verifie si en dessous il y a un pion
			if(matrice[ligne+1][colonne].valeur_pion1 != 3 && matrice[ligne+1][colonne].type1 == creuse && matrice[ligne+1][colonne].valeur_pion2 == 0){
				matrice[ligne+1][colonne].valeur_pion2 = 3;
				matrice[ligne+1][colonne].type2 = pleine;
			}

			else{
				matrice[ligne][colonne].valeur_pion1 = 3;
				matrice[ligne][colonne].type1 = pleine;
			}
		}
		else if(type == 3){
			matrice[ligne][colonne].valeur_pion1 = 3;
			matrice[ligne][colonne].type1 = bloquante;
		}
	}
/******************************************************* JOUEUR 4 **********************************************************/

	else if(num_joueur == 4){
		if(type == 1){
			//Verifie si en dessous il y a un pion
			if(matrice[ligne+1][colonne].valeur_pion1 != 4 && matrice[ligne+1][colonne].type1 == pleine && matrice[ligne+1][colonne].valeur_pion2 == 0){
				matrice[ligne+1][colonne].valeur_pion2 = 4;
				matrice[ligne+1][colonne].type2 = creuse;
			}
			else{
				matrice[ligne][colonne].valeur_pion1 = 4;
				matrice[ligne][colonne].type1 = creuse;
			}
		}
		else if(type == 2){
			//Verifie si en dessous il y a un pion
			if(matrice[ligne+1][colonne].valeur_pion1 != 4 && matrice[ligne+1][colonne].type1 == creuse && matrice[ligne+1][colonne].valeur_pion2 == 0){
				matrice[ligne+1][colonne].valeur_pion2 = 4;
				matrice[ligne+1][colonne].type2 = pleine;
			}

			else{
				matrice[ligne][colonne].valeur_pion1 = 4;
				matrice[ligne][colonne].type1 = pleine;
			}
		}
		else if(type == 3){
			matrice[ligne][colonne].valeur_pion1 = 4;
			matrice[ligne][colonne].type1 = bloquante;
		}
	}
}

//Parcours la grille du Puissance 4 pour savoir si un joueur a gagné ou non
int gagne_avance(t_piece grille[N][M]){
	int player1 = 0;
	int player2 = 0;
	int player3 = 0;
	int player4 = 0; 
	int i, j;

	//Test en ligne
	for(i = 0; i < N; i++){
		player1 = 0;
		player2 = 0;
		player3 = 0;
		player4 = 0;
		for(j = 0; j < M; j++){
			if(grille[i][j].valeur_pion1 == 1 || grille[i][j].valeur_pion2 == 1){
				player1++;
				if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
					player2 = 0;
				if(grille[i][j].valeur_pion1 != 3 && grille[i][j].valeur_pion2 != 3)
					player3 = 0;
				if(grille[i][j].valeur_pion1 != 4 && grille[i][j].valeur_pion2 != 4)
					player4 = 0;
				if(player1 == 4)
					return 1;
			}
			if(grille[i][j].valeur_pion1 == 2 || grille[i][j].valeur_pion2 == 2){
				player2++;
				if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
					player1 = 0;
				if(grille[i][j].valeur_pion1 != 3 && grille[i][j].valeur_pion2 != 3)
					player3 = 0;
				if(grille[i][j].valeur_pion1 != 4 && grille[i][j].valeur_pion2 != 4)
					player4 = 0;
				if(player2 == 4)
					return 2;
			}
			if(grille[i][j].valeur_pion1 == 3 || grille[i][j].valeur_pion2 == 3){
				player3++;
				if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
					player1 = 0;
				if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
					player2 = 0;
				if(grille[i][j].valeur_pion1 != 4 && grille[i][j].valeur_pion2 != 4)
					player4 = 0;
				if(player3 == 4)
					return 3;
			}
			if(grille[i][j].valeur_pion1 == 2 || grille[i][j].valeur_pion2 == 2){
				player2++;
				if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
					player1 = 0;
				if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
					player2 = 0;
				if(grille[i][j].valeur_pion1 != 3 && grille[i][j].valeur_pion2 != 3)
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

	//Test colonne
	for(j = 0; j < M; j++){
		player1 = 0;
		player2 = 0;
		for(i = 0; i < N; i++){
			if(grille[i][j].valeur_pion1 == 1 || grille[i][j].valeur_pion2 == 1){
				player1++;
				if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
					player2 = 0;
				if(grille[i][j].valeur_pion1 != 3 && grille[i][j].valeur_pion2 != 3)
					player3 = 0;
				if(grille[i][j].valeur_pion1 != 4 && grille[i][j].valeur_pion2 != 4)
					player4 = 0;
				if(player1 == 4)
					return 1;
			}
			if(grille[i][j].valeur_pion1 == 2 || grille[i][j].valeur_pion2 == 2){
				player2++;
				if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
					player1 = 0;
				if(grille[i][j].valeur_pion1 != 3 && grille[i][j].valeur_pion2 != 3)
					player3 = 0;
				if(grille[i][j].valeur_pion1 != 4 && grille[i][j].valeur_pion2 != 4)
					player4 = 0;
				if(player2 == 4)
					return 2;
			}
			if(grille[i][j].valeur_pion1 == 3 || grille[i][j].valeur_pion2 == 3){
				player1++;
				if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
					player1 = 0;
				if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
					player2 = 0;
				if(grille[i][j].valeur_pion1 != 4 && grille[i][j].valeur_pion2 != 4)
					player4 = 0;
				if(player3 == 4)
					return 3;
			}
			if(grille[i][j].valeur_pion1 == 4 || grille[i][j].valeur_pion2 == 4){
				player1++;
				if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
					player1 = 0;
				if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
					player2 = 0;
				if(grille[i][j].valeur_pion1 != 3 && grille[i][j].valeur_pion2 != 3)
					player3 = 0;
				if(player4 == 4)
					return 4;
			}
			else{
				player1 = 0;
				player2 = 0;
				player3 = 0;
				player4 = 0;
=======

	

	if(num_joueur == 1){
		int bloquante = 2 ;
		
		if(type == 1){		// pièce creuse
			if(grille[ligne-1][colonne].valeur_pion1 == 1) {		// case du dessous est creuse
				grille[ligne][colonne].valeur_pion1 = 1;
				grille[ligne][colonne].type1 = creuse;
			}
			else if(grille[ligne-1][colonne].valeur_pion1 == 2) {		// case du dessous est pleine
				grille[ligne][colonne].valeur_pion1 = 0;
				grille[ligne][colonne].type1 = vide;
				grille[ligne-1][colonne].valeur_pion2 = 1;
				grille[ligne-1][colonne].type1 = pleine ;
				grille[ligne-1][colonne].type2 = creuse;
				
			}
			else if(grille[ligne-1][colonne].valeur_pion1 == 3) {		// case du dessous est bloquante
				grille[ligne][colonne].valeur_pion1 = 1;
				grille[ligne][colonne].type1 = creuse;
			}
		}
		if(type == 2){		// pièce pleine
			if(grille[ligne-1][colonne].valeur_pion1 == 1) {		// case du dessous est creuse
				grille[ligne][colonne].valeur_pion1 = 0;
				grille[ligne][colonne].type1 = vide;
				grille[ligne-1][colonne].valeur_pion2 = 1;
				grille[ligne-1][colonne].type1 = creuse ;
				grille[ligne-1][colonne].type2 = pleine;
			}
			else if(grille[ligne-1][colonne].valeur_pion1 == 2) {		// case du dessous est pleine
				grille[ligne][colonne].valeur_pion1 = 1;
				grille[ligne][colonne].type1 = pleine;
				
			}
			else if(grille[ligne-1][colonne].valeur_pion1 == 3) {		// case du dessous est bloquante
				grille[ligne][colonne].valeur_pion1 = 1;
				grille[ligne][colonne].type1 = pleine;
>>>>>>> f629ae424dccd42bbe86405465e0d2b50138b592
			}
		}
		if(type == 3){		// pièce bloquante
			while (bloquante != 0) {
				if(grille[ligne-1][colonne].valeur_pion1 == 1) {		// case du dessous est creuse
					grille[ligne][colonne].valeur_pion1 = 1;
					grille[ligne][colonne].type1 = bloquante;
					bloquante -- ;
				}
				else if(grille[ligne-1][colonne].valeur_pion1 == 2) {		// case du dessous est pleine
					grille[ligne][colonne].valeur_pion1 = 1;
					grille[ligne][colonne].type1 = bloquante;
					bloquante -- ;
				
				}
				else if(grille[ligne-1][colonne].valeur_pion1 == 3) {		// case du dessous est bloquante
					grille[ligne][colonne].valeur_pion1 = 1;
					grille[ligne][colonne].type1 = bloquante;
					bloquante -- ;
				}
			}
			if(bloquante == 0) printf("Vous avez utilisé vos 2 pièces bloquantes\n") ;
		}
		
	}
	
	if(num_joueur == 2){
		int bloquante2 = 2 ;

<<<<<<< HEAD
	//Test diagonale droite
		player1 = 0;
		player2 = 0;
		i = 0;
		j = 3;
		while(i <= 3 && j >= 0){
			if(grille[i][j].valeur_pion1 == 1 || grille[i][j].valeur_pion2 == 1){
				player1++;
				if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
					player2 = 0;
				if(player1 == 4)
					return 1;
			}
			if(grille[i][j].valeur_pion1 == 2 || grille[i][j].valeur_pion2 == 2){
				player2++;
				if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
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
			if(grille[i][j].valeur_pion1 == 1 || grille[i][j].valeur_pion2 == 1){
				player1++;
				if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
					player2 = 0;
				if(player1 == 4)
					return 1;
			}
			if(grille[i][j].valeur_pion1 == 2 || grille[i][j].valeur_pion2 == 2){
				player2++;
				if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
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
			if(grille[i][j].valeur_pion1 == 1 || grille[i][j].valeur_pion2 == 1){
				player1++;
				if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
					player2 = 0;
				if(player1 == 4)
					return 1;
			}
			if(grille[i][j].valeur_pion1 == 2 || grille[i][j].valeur_pion2 == 2){
				player2++;
				if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
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
=======
		if(type == 1){		// pièce creuse
			if(grille[ligne-1][colonne].valeur_pion1 == 2) {		// case du dessous est pleine
				grille[ligne][colonne].valeur_pion1 = 0;
				grille[ligne][colonne].type1 = vide;
				grille[ligne-1][colonne].valeur_pion2 = 2;
				grille[ligne-1][colonne].type1 = pleine ;
				grille[ligne-1][colonne].type2 = creuse;
				
			}
			else if(grille[ligne-1][colonne].valeur_pion1 == 3) {		// case du dessous est bloquante
				grille[ligne][colonne].valeur_pion1 = 2;
				grille[ligne][colonne].type1 = creuse;
			}
		}
		if(type == 2){		// pièce pleine
			if(grille[ligne-1][colonne].valeur_pion1 == 1) {		// case du dessous est creuse
				grille[ligne][colonne].valeur_pion1 = 0;
				grille[ligne][colonne].type1 = vide;
				grille[ligne-1][colonne].valeur_pion2 = 2;
				grille[ligne-1][colonne].type1 = creuse ;
				grille[ligne-1][colonne].type2 = pleine;
			}
			else if(grille[ligne-1][colonne].valeur_pion1 == 2) {		// case du dessous est pleine
				grille[ligne][colonne].valeur_pion1 = 2;
				grille[ligne][colonne].type1 = pleine;
				
			}
			else if(grille[ligne-1][colonne].valeur_pion1 == 3) {		// case du dessous est bloquante
				grille[ligne][colonne].valeur_pion1 = 2;
				grille[ligne][colonne].type1 = pleine;
			}
		}
		if(type == 3){		// pièce bloquante
			while (bloquante2 != 0) {
				 if(grille[ligne-1][colonne].valeur_pion1 == 1) {		// case du dessous est creuse
					grille[ligne][colonne].valeur_pion1 = 2;
					grille[ligne][colonne].type1 = bloquante;
					bloquante2 -- ;
				}
				else if(grille[ligne-1][colonne].valeur_pion1 == 2) {		// case du dessous est pleine
					grille[ligne][colonne].valeur_pion1 = 2;
					grille[ligne][colonne].type1 = bloquante;
					bloquante2 -- ;
				
				}
				else if(grille[ligne-1][colonne].valeur_pion1 == 3) {		// case du dessous est bloquante
					grille[ligne][colonne].valeur_pion1 = 2;
					grille[ligne][colonne].type1 = bloquante;
					bloquante2 -- ;
				}
			}
			if(bloquante2 == 0) printf("Vous avez utilisé vos 2 pièces bloquantes\n") ;
>>>>>>> f629ae424dccd42bbe86405465e0d2b50138b592
		}
		
	}

<<<<<<< HEAD
		player1 = 0;
		player2 = 0;
		i = 0;
		j = 6;
		while(i <= 5 && j >= 1){
			if(grille[i][j].valeur_pion1 == 1 || grille[i][j].valeur_pion2 == 1){
				player1++;
				if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
					player2 = 0;
				if(player1 == 4)
					return 1;
			}
			if(grille[i][j].valeur_pion1 == 2 || grille[i][j].valeur_pion2 == 2){
				player2++;
				if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
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
			if(grille[i][j].valeur_pion1 == 1 || grille[i][j].valeur_pion2 == 1){
				player1++;
				if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
					player2 = 0;
				if(player1 == 4)
					return 1;
			}
			if(grille[i][j].valeur_pion1 == 2 || grille[i][j].valeur_pion2 == 2){
				player2++;
				if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
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
			if(grille[i][j].valeur_pion1 == 1 || grille[i][j].valeur_pion2 == 1){
				player1++;
				if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
					player2 = 0;
				if(player1 == 4)
					return 1;
			}
			if(grille[i][j].valeur_pion1 == 2 || grille[i][j].valeur_pion2 == 2){
				player2++;
				if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
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
			if(grille[i][j].valeur_pion1 == 1 || grille[i][j].valeur_pion2 == 1){
				player1++;
				if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
					player2 = 0;
				if(player1 == 4)
					return 1;
			}
			if(grille[i][j].valeur_pion1 == 2 || grille[i][j].valeur_pion2 == 2){
				player2++;
				if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
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
=======
	if(num_joueur == 3){
		int bloquante3 = 2 ;

		if(type == 1){		// pièce creuse
			if(grille[ligne-1][colonne].valeur_pion1 == 1) {		// case du dessous est creuse
				grille[ligne][colonne].valeur_pion1 = 3;
				grille[ligne][colonne].type1 = creuse;
			}
			else if(grille[ligne-1][colonne].valeur_pion1 == 2) {		// case du dessous est pleine
				grille[ligne][colonne].valeur_pion1 = 0;
				grille[ligne][colonne].type1 = vide;
				grille[ligne-1][colonne].valeur_pion2 = 3;
				grille[ligne-1][colonne].type1 = pleine ;
				grille[ligne-1][colonne].type2 = creuse;
				
			}
			else if(grille[ligne-1][colonne].valeur_pion1 == 3) {		// case du dessous est bloquante
				grille[ligne][colonne].valeur_pion1 = 3;
				grille[ligne][colonne].type1 = creuse;
			}
		}
		if(type == 2){		// pièce pleine
			if(grille[ligne-1][colonne].valeur_pion1 == 1) {		// case du dessous est creuse
				grille[ligne][colonne].valeur_pion1 = 0;
				grille[ligne][colonne].type1 = vide;
				grille[ligne-1][colonne].valeur_pion2 = 3;
				grille[ligne-1][colonne].type1 = creuse ;
				grille[ligne-1][colonne].type2 = pleine;
			}
			else if(grille[ligne-1][colonne].valeur_pion1 == 2) {		// case du dessous est pleine
				grille[ligne][colonne].valeur_pion1 = 3;
				grille[ligne][colonne].type1 = pleine;
				
			}
			else if(grille[ligne-1][colonne].valeur_pion1 == 3) {		// case du dessous est bloquante
				grille[ligne][colonne].valeur_pion1 = 3;
				grille[ligne][colonne].type1 = pleine;
			}
		}
		if(type == 3){		// pièce bloquante
			while (bloquante3 != 0) {
				if(grille[ligne-1][colonne].valeur_pion1 == 1) {		// case du dessous est creuse
					grille[ligne][colonne].valeur_pion1 = 3;
					grille[ligne][colonne].type1 = bloquante;
					bloquante3 -- ;
				}
				else if(grille[ligne-1][colonne].valeur_pion1 == 2) {		// case du dessous est pleine
					grille[ligne][colonne].valeur_pion1 = 3;
					grille[ligne][colonne].type1 = bloquante;
					bloquante3 -- ;
				
				}
				else if(grille[ligne-1][colonne].valeur_pion1 == 3) {		// case du dessous est bloquante
					grille[ligne][colonne].valeur_pion1 = 3;
					grille[ligne][colonne].type1 = bloquante;
					bloquante3 -- ;
				}
			}
			if(bloquante3 == 0) printf("Vous avez utilisé vos 2 pièces bloquantes\n") ;
>>>>>>> f629ae424dccd42bbe86405465e0d2b50138b592
		}
		
	}

<<<<<<< HEAD
		player1 = 0;
		player2 = 0;
		i = 0;
		j = 2;
		while(i <= 4 && j <= 6){
			if(grille[i][j].valeur_pion1 == 1 || grille[i][j].valeur_pion2 == 1){
				player1++;
				if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
					player2 = 0;
				if(player1 == 4)
					return 1;
			}
			if(grille[i][j].valeur_pion1 == 2 || grille[i][j].valeur_pion2 == 2){
				player2++;
				if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
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
			if(grille[i][j].valeur_pion1 == 1 || grille[i][j].valeur_pion2 == 1){
				player1++;
				if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
					player2 = 0;
				if(player1 == 4)
					return 1;
			}
			if(grille[i][j].valeur_pion1 == 2 || grille[i][j].valeur_pion2 == 2){
				player2++;
				if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
					player1 = 0;
				if(player2 == 4)
					return 2;
			}
			else{
				player1 = 0;
				player2 = 0;
=======
	if(num_joueur == 4){
		int bloquante4 = 2 ;

		if(type == 1){		// pièce creuse
			if(grille[ligne-1][colonne].valeur_pion1 == 1) {		// case du dessous est creuse
				grille[ligne][colonne].valeur_pion1 = 4;
				grille[ligne][colonne].type1 = creuse;
			}
			else if(grille[ligne-1][colonne].valeur_pion1 == 2) {		// case du dessous est pleine
				grille[ligne][colonne].valeur_pion1 = 0;
				grille[ligne][colonne].type1 = vide;
				grille[ligne-1][colonne].valeur_pion2 = 4;
				grille[ligne-1][colonne].type1 = pleine ;
				grille[ligne-1][colonne].type2 = creuse;
				
			}
			else if(grille[ligne-1][colonne].valeur_pion1 == 3) {		// case du dessous est bloquante
				grille[ligne][colonne].valeur_pion1 = 4;
				grille[ligne][colonne].type1 = creuse;
>>>>>>> f629ae424dccd42bbe86405465e0d2b50138b592
			}
		}
<<<<<<< HEAD

		player1 = 0;
		player2 = 0;
		i = 0;
		j = 0;
		while(i <= 5 && j <= 5){
			if(grille[i][j].valeur_pion1 == 1 || grille[i][j].valeur_pion2 == 1){
				player1++;
				if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
					player2 = 0;
				if(player1 == 4)
					return 1;
			}
			if(grille[i][j].valeur_pion1 == 2 || grille[i][j].valeur_pion2 == 2){
				player2++;
				if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
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
			if(grille[i][j].valeur_pion1 == 1 || grille[i][j].valeur_pion2 == 1){
				player1++;
				if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
					player2 = 0;
				if(player1 == 4)
					return 1;
			}
			if(grille[i][j].valeur_pion1 == 2 || grille[i][j].valeur_pion2 == 2){
				player2++;
				if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
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
=======
		if(type == 2){		// pièce pleine
			if(grille[ligne-1][colonne].valeur_pion1 == 1) {		// case du dessous est creuse
				grille[ligne][colonne].valeur_pion1 = 0;
				grille[ligne][colonne].type1 = vide;
				grille[ligne-1][colonne].valeur_pion2 = 4;
				grille[ligne-1][colonne].type1 = creuse ;
				grille[ligne-1][colonne].type2 = pleine;
			}
			else if(grille[ligne-1][colonne].valeur_pion1 == 2) {		// case du dessous est pleine
				grille[ligne][colonne].valeur_pion1 = 4;
				grille[ligne][colonne].type1 = pleine;
				
			}
			else if(grille[ligne-1][colonne].valeur_pion1 == 3) {		// case du dessous est bloquante
				grille[ligne][colonne].valeur_pion1 = 4;
				grille[ligne][colonne].type1 = pleine;
			}
		}
		if(type == 3){		// pièce bloquante
			while (bloquante3 != 0) {
				if(grille[ligne-1][colonne].valeur_pion1 == 1) {		// case du dessous est creuse
					grille[ligne][colonne].valeur_pion1 = 4;
					grille[ligne][colonne].type1 = bloquante;
					bloquante3 -- ;
				}
				else if(grille[ligne-1][colonne].valeur_pion1 == 2) {		// case du dessous est pleine
					grille[ligne][colonne].valeur_pion1 = 4;
					grille[ligne][colonne].type1 = bloquante;
					bloquante3 -- ;
				
				}
				else if(grille[ligne-1][colonne].valeur_pion1 == 3) {		// case du dessous est bloquante
					grille[ligne][colonne].valeur_pion1 = 4;
					grille[ligne][colonne].type1 = bloquante;
					bloquante3 -- ;
				}
			}
			if(bloquante3 == 0) printf("Vous avez utilisé vos 2 pièces bloquantes\n") ;
>>>>>>> f629ae424dccd42bbe86405465e0d2b50138b592
		}
		
	}

<<<<<<< HEAD
		player1 = 0;
		player2 = 0;
		i = 2;
		j = 0;
		while(i <= 5 && j <= 3){
			if(grille[i][j].valeur_pion1 == 1 || grille[i][j].valeur_pion2 == 1){
				player1++;
				if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
					player2 = 0;
				if(player1 == 4)
					return 1;
			}
			if(grille[i][j].valeur_pion1 == 2 || grille[i][j].valeur_pion2 == 2){
				player2++;
				if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
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
=======
	

}
>>>>>>> f629ae424dccd42bbe86405465e0d2b50138b592
