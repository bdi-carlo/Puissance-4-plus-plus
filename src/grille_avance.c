#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/new_fonctions.h"

#define couleur(param) printf("\033[%sm",param)
#define N 6
#define M 7

/**
*\file grille_avance.c
*\brief Interface du jeu Puissance 4 ++
*\author Benjamin, Julien, Arthur
*\version 1.0
*\date Novembre 2016
*/


/**
*\fn void init_matrice_avance(t_piece matrice[N][M])
*\brief Initialise à vide la grille du Puissance 4++

*\fn int grille_pleine(t_piece matrice[N][M])
*\brief Verifie si la grille est pleine ou non

*\fn void afficher_matrice_avance(t_piece matrice[N][M])
*\brief Affiche la grille du Puissance 4++ en cours

*\fn int choix_ligne_avance(t_piece matrice[N][M], int colonne)
*\brief Retourne la premiere ligne libre

*\fn void placer_pions_avance(t_piece matrice[N][M], int colonne, int ligne, int num_joueur, int type)
*\brief Place le pion dans la colonne sélectionné et sur la bonne ligne

*\fn int gagne_avance(t_piece grille[N][M])
*\brief Parcours la grille du Puissance 4++ pour savoir si un joueur a gagné ou non
*/



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


void afficher_matrice_avance(t_piece matrice[N][M]){
	int i,j;

	printf("\n|					|\n");
	for(i = 0; i < N; i++){
		printf("|	  ");
		for(j = 0; j < M; j++){
			//Cas où il n'y a pas de pion
			if(matrice[i][j].valeur_pion1 == 0 && matrice[i][j].valeur_pion2 == 0)printf(" . ");

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

			//Quand le joueur 1 a joue une piece pleine et qu'un autre joueur ou lui meme joue une piece creuse par dessus
			else if(matrice[i][j].valeur_pion1 == 1 && matrice[i][j].type1 == pleine){

				//Joueur 2
				if(matrice[i][j].valeur_pion2 == 2 && matrice[i][j].type2 == creuse){
					couleur("44;31");
					printf(" 0 ");
					couleur("0");
				}
				//Joueur 3
				else if(matrice[i][j].valeur_pion2 == 3 && matrice[i][j].type2 == creuse){
					couleur("45;31");
					printf(" 0 ");
					couleur("0");
				}
				//Joueur 4
				else if(matrice[i][j].valeur_pion2 == 4 && matrice[i][j].type2 == creuse){
					couleur("43;31");
					printf(" 0 ");
					couleur("0");
				}
				//Lui meme
 				else if(matrice[i][j].valeur_pion2 == 1 && matrice[i][j].type2 == creuse){
		        	couleur("41;31");
		        	printf(" 0 ");
		        	couleur("0");
				}
			}

			//Quand le joueur 1 a joue une piece creuse et qu'un autre joueur ou lui meme joue une piece pleine par dessus
			else if(matrice[i][j].valeur_pion1 == 1 && matrice[i][j].type1 == creuse){

				//Joueur 2
				if(matrice[i][j].valeur_pion2 == 2 && matrice[i][j].type2 == pleine){
					couleur("41;34");
					printf(" 0 ");
					couleur("0");
				}
				//Joueur 3
				else if(matrice[i][j].valeur_pion2 == 3 && matrice[i][j].type2 == pleine){
					couleur("41;35");
					printf(" 0 ");
					couleur("0");
				}
				//Joueur 4
				else if(matrice[i][j].valeur_pion2 == 4 && matrice[i][j].type2 == pleine){
					couleur("41;32");
					printf(" 0 ");
					couleur("0");
				}
				//Lui meme
 				else if(matrice[i][j].valeur_pion2 == 1 && matrice[i][j].type2 == pleine ){
		        	couleur("41;31");
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

			//Quand le joueur 2 a joue une piece creuse et qu'un autre joueur ou lui meme joue une piece pleine par dessus
			else if(matrice[i][j].valeur_pion1 == 2 && matrice[i][j].type1 == creuse){
			
				//Joueur 1
				if(matrice[i][j].valeur_pion2 == 1 && matrice[i][j].type2 == pleine){
					couleur("44;31");
					printf(" 0 ");
					couleur("0");
				}
				//Joueur 3
				else if(matrice[i][j].valeur_pion2 == 3 && matrice[i][j].type2 == pleine){
					couleur("44;35");
					printf(" 0 ");
					couleur("0");
				}
				//Joueur 4
				else if(matrice[i][j].valeur_pion2 == 4 && matrice[i][j].type2 == pleine){
					couleur("44;32");
					printf(" 0 ");
					couleur("0");
				}
				//Lui meme
 				else if(matrice[i][j].valeur_pion2 == 2 && matrice[i][j].type2 == pleine){
		        	couleur("44;34");
		        	printf(" 0 ");
		        	couleur("0");
				}			
			}

			//Quand le joueur 2 a joue une piece pleine et qu'un autre joueur joue une piece creuse par dessus
			else if(matrice[i][j].valeur_pion1 == 2 && matrice[i][j].type1 == pleine){
			
				//Joueur 1
				if(matrice[i][j].valeur_pion2 == 1 && matrice[i][j].type2 == creuse){
					couleur("41;34");
					printf(" 0 ");
					couleur("0");
				}
				//Joueur 3
				else if(matrice[i][j].valeur_pion2 == 3 && matrice[i][j].type2 == creuse){
					couleur("45;34");
					printf(" 0 ");
					couleur("0");
				}
				//Joueur 4
				else if(matrice[i][j].valeur_pion2 == 4 && matrice[i][j].type2 == creuse){
					couleur("43;34");
					printf(" 0 ");
					couleur("0");
				}
				//Lui meme
 				else if(matrice[i][j].valeur_pion2 == 2 && matrice[i][j].type2 == creuse){
		        	couleur("44;34");
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
				//Lui meme
 				else if(matrice[i][j].valeur_pion2 == 3 && matrice[i][j].type2 == pleine){
		        	couleur("45;35");
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
				//Lui meme
 				else if(matrice[i][j].valeur_pion2 == 2 && matrice[i][j].type2 == creuse){
		        	couleur("45;35");
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
					couleur("42;31");
					printf(" 0 ");
					couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 2 && matrice[i][j].type2 == pleine){
					couleur("42;35");
					printf(" 0 ");
					couleur("0");
				}
				else if(matrice[i][j].valeur_pion2 == 3 && matrice[i][j].type2 == pleine){
					couleur("42;34");
					printf(" 0 ");
					couleur("0");
				}
				//Lui meme
 				else if(matrice[i][j].valeur_pion2 == 3 && matrice[i][j].type2 == pleine){
		        	couleur("42;32");
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
				//Lui meme
 				else if(matrice[i][j].valeur_pion2 == 2 && matrice[i][j].type2 == creuse){
		        	couleur("42;32");
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

void placer_pions_avance(t_piece matrice[N][M], int colonne, int ligne, int num_joueur, int type){
	int i;

	colonne--;

/******************************************************* JOUEUR 1 **********************************************************/

	if(num_joueur == 1){
		if(type == 1){
			//Verifie si en dessous il y a un ou deux pions en dessous et si ils peuvent fusionner
			i = ligne+1;
			if(matrice[i][colonne].type1 == pleine && matrice[i][colonne].valeur_pion2 == 0){
				while(i < N){
					if(matrice[i][colonne].type1 == bloquante || matrice[i][colonne].type1 == creuse || matrice[i][colonne].valeur_pion2 != 0)
						break;
					i++;
				}
				i--;
				if(matrice[i][colonne].type1 == pleine && matrice[i][colonne].valeur_pion2 == 0){
					matrice[i][colonne].valeur_pion2 = 1;
					matrice[i][colonne].type2 = creuse;
				}
			}

			else{
				matrice[ligne][colonne].valeur_pion1 = 1;
				matrice[ligne][colonne].type1 = creuse;
			}
		}
		else if(type == 2){
			//Verifie si en dessous il y a un ou deux pions en dessous et si ils peuvent fusionner
			i = ligne+1;
			if(matrice[i][colonne].type1 == creuse && matrice[i][colonne].valeur_pion2 == 0){
				while(i < N){
					if(matrice[i][colonne].type1 == bloquante || matrice[i][colonne].type1 == pleine || matrice[i][colonne].valeur_pion2 != 0)
						break;
					i++;
				}
				i--;
				if(matrice[i][colonne].type1 == creuse && matrice[i][colonne].valeur_pion2 == 0){
					matrice[i][colonne].valeur_pion2 = 1;
					matrice[i][colonne].type2 = pleine;
				}
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
			//Verifie si en dessous il y a un ou deux pions en dessous et si ils peuvent fusionner
			i = ligne+1;
			if(matrice[i][colonne].type1 == pleine && matrice[i][colonne].valeur_pion2 == 0){
				while(i < N){
					if(matrice[i][colonne].type1 == bloquante || matrice[i][colonne].type1 == creuse || matrice[i][colonne].valeur_pion2 != 0)
						break;
					i++;
				}
				i--;
				if(matrice[i][colonne].type1 == pleine && matrice[i][colonne].valeur_pion2 == 0){
					matrice[i][colonne].valeur_pion2 = 2;
					matrice[i][colonne].type2 = creuse;
				}
			}

			else{
				matrice[ligne][colonne].valeur_pion1 = 2;
				matrice[ligne][colonne].type1 = creuse;
			}
		}
		else if(type == 2){
			//Verifie si en dessous il y a un ou deux pions en dessous et si ils peuvent fusionner
			i = ligne+1;
			if(matrice[i][colonne].type1 == creuse && matrice[i][colonne].valeur_pion2 == 0){
				while(i < N){
					if(matrice[i][colonne].type1 == bloquante || matrice[i][colonne].type1 == pleine || matrice[i][colonne].valeur_pion2 != 0)
						break;
					i++;
				}
				i--;
				if(matrice[i][colonne].type1 == creuse && matrice[i][colonne].valeur_pion2 == 0){
					matrice[i][colonne].valeur_pion2 = 2;
					matrice[i][colonne].type2 = pleine;
				}
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
			//Verifie si en dessous il y a un ou deux pions en dessous et si ils peuvent fusionner
			i = ligne+1;
			if(matrice[i][colonne].type1 == pleine && matrice[i][colonne].valeur_pion2 == 0){
				while(i < N){
					if(matrice[i][colonne].type1 == bloquante || matrice[i][colonne].type1 == creuse || matrice[i][colonne].valeur_pion2 != 0)
						break;
					i++;
				}
				i--;
				if(matrice[i][colonne].type1 == pleine && matrice[i][colonne].valeur_pion2 == 0){
					matrice[i][colonne].valeur_pion2 = 3;
					matrice[i][colonne].type2 = creuse;
				}
			}

			else{
				matrice[ligne][colonne].valeur_pion1 = 3;
				matrice[ligne][colonne].type1 = creuse;
			}
		}
		else if(type == 2){
			//Verifie si en dessous il y a un ou deux pions en dessous et si ils peuvent fusionner
			i = ligne+1;
			if(matrice[i][colonne].type1 == creuse && matrice[i][colonne].valeur_pion2 == 0){
				while(i < N){
					if(matrice[i][colonne].type1 == bloquante || matrice[i][colonne].type1 == pleine || matrice[i][colonne].valeur_pion2 != 0)
						break;
					i++;
				}
				i--;
				if(matrice[i][colonne].type1 == creuse && matrice[i][colonne].valeur_pion2 == 0){
					matrice[i][colonne].valeur_pion2 = 3;
					matrice[i][colonne].type2 = pleine;
				}
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
			//Verifie si en dessous il y a un ou deux pions en dessous et si ils peuvent fusionner
			i = ligne+1;
			if(matrice[i][colonne].type1 == pleine && matrice[i][colonne].valeur_pion2 == 0){
				while(i < N){
					if(matrice[i][colonne].type1 == bloquante || matrice[i][colonne].type1 == creuse || matrice[i][colonne].valeur_pion2 != 0)
						break;
					i++;
				}
				i--;
				if(matrice[i][colonne].type1 == pleine && matrice[i][colonne].valeur_pion2 == 0){
					matrice[i][colonne].valeur_pion2 = 4;
					matrice[i][colonne].type2 = creuse;
				}
			}

			else{
				matrice[ligne][colonne].valeur_pion1 = 4;
				matrice[ligne][colonne].type1 = creuse;
			}
		}
		else if(type == 2){
			//Verifie si en dessous il y a un ou deux pions en dessous et si ils peuvent fusionner
			i = ligne+1;
			if(matrice[i][colonne].type1 == creuse && matrice[i][colonne].valeur_pion2 == 0){
				while(i < N){
					if(matrice[i][colonne].type1 == bloquante || matrice[i][colonne].type1 == pleine || matrice[i][colonne].valeur_pion2 != 0)
						break;
					i++;
				}
				i--;
				if(matrice[i][colonne].type1 == creuse && matrice[i][colonne].valeur_pion2 == 0){
					matrice[i][colonne].valeur_pion2 = 4;
					matrice[i][colonne].type2 = pleine;
				}
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

int gagne_avance(t_piece grille[N][M]){
	int player1 = 0;
	int player2 = 0;
	int player3 = 0;
	int player4 = 0;
	int i, j, k;

	//Test en ligne
	for(i = 0; i < N; i++){
		player1 = 0;
		player2 = 0;
		player3 = 0;
		player4 = 0;
		for(j = 0; j < M; j++){
			if(grille[i][j].valeur_pion1 == 1 || grille[i][j].valeur_pion2 == 1){
				player1++;
				if(player1 == 4)
					return 1;
			}
			if(grille[i][j].valeur_pion1 == 2 || grille[i][j].valeur_pion2 == 2){
				player2++;
				if(player2 == 4)
					return 2;
			}
			if(grille[i][j].valeur_pion1 == 3 || grille[i][j].valeur_pion2 == 3){
				player3++;
				if(player3 == 4)
					return 3;
			}
			if(grille[i][j].valeur_pion1 == 4 || grille[i][j].valeur_pion2 == 4){
				player4++;
				if(player4 == 4)
					return 4;
			}
			if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
				player1 = 0;
			if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
				player2 = 0;
			if(grille[i][j].valeur_pion1 != 3 && grille[i][j].valeur_pion2 != 3)
				player3 = 0;
			if(grille[i][j].valeur_pion1 != 4 && grille[i][j].valeur_pion2 != 4)
				player4 = 0;
		}
	}

	//Test colonne
	for(j = 0; j < M; j++){
		player1 = 0;
		player2 = 0;
		player3 = 0;
		player4 = 0;
		for(i = 0; i < N; i++){
			if(grille[i][j].valeur_pion1 == 1 || grille[i][j].valeur_pion2 == 1){
				player1++;
				if(player1 == 4)
					return 1;
			}
			if(grille[i][j].valeur_pion1 == 2 || grille[i][j].valeur_pion2 == 2){
				player2++;
				if(player2 == 4)
					return 2;
			}
			if(grille[i][j].valeur_pion1 == 3 || grille[i][j].valeur_pion2 == 3){
				player3++;
				if(player3 == 4)
					return 3;
			}
			if(grille[i][j].valeur_pion1 == 4 || grille[i][j].valeur_pion2 == 4){
				player4++;
				if(player4 == 4)
					return 4;
			}
			if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
				player1 = 0;
			if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
				player2 = 0;
			if(grille[i][j].valeur_pion1 != 3 && grille[i][j].valeur_pion2 != 3)
				player3 = 0;
			if(grille[i][j].valeur_pion1 != 4 && grille[i][j].valeur_pion2 != 4)
				player4 = 0;
		}
	}

	//Test diagonale droite
	for(k = 3; k <= 5; k++){
		player1 = 0;
		player2 = 0;
		player3 = 0;
		player4 = 0;
		i = 0;

		j = k;
		while(i <= k && j >= 0){
			if(grille[i][j].valeur_pion1 == 1 || grille[i][j].valeur_pion2 == 1){
				player1++;
				if(player1 == 4)
					return 1;
			}

			if(grille[i][j].valeur_pion1 == 2 || grille[i][j].valeur_pion2 == 2){
				player2++;
				if(player2 == 4)
					return 2;
			}
			if(grille[i][j].valeur_pion1 == 3 || grille[i][j].valeur_pion2 == 3){
				player3++;
				if(player3 == 4)
					return 3;
			}
			if(grille[i][j].valeur_pion1 == 4 || grille[i][j].valeur_pion2 == 4){
				player4++;
				if(player4 == 4)
					return 4;
			}

			if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
				player1 = 0;
			if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
				player2 = 0;
			if(grille[i][j].valeur_pion1 != 3 && grille[i][j].valeur_pion2 != 3)
				player3 = 0;
			if(grille[i][j].valeur_pion1 != 4 && grille[i][j].valeur_pion2 != 4)
				player4 = 0;
			i++;
			j--;
		}
	}


	for(k = 0; k <= 2; k++){
		player1 = 0;
		player2 = 0;
		player3 = 0;
		player4 = 0;
		j = 6;

		i = k;
		while(i <= 5 && j >= k+1){
			if(grille[i][j].valeur_pion1 == 1 || grille[i][j].valeur_pion2 == 1){
				player1++;
				if(player1 == 4)
					return 1;
			}

			if(grille[i][j].valeur_pion1 == 2 || grille[i][j].valeur_pion2 == 2){
				player2++;
				if(player2 == 4)
					return 2;
			}
			if(grille[i][j].valeur_pion1 == 3 || grille[i][j].valeur_pion2 == 3){
				player3++;
				if(player3 == 4)
					return 3;
			}
			if(grille[i][j].valeur_pion1 == 4 || grille[i][j].valeur_pion2 == 4){
				player4++;
				if(player4 == 4)
					return 4;
			}

			if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
				player1 = 0;
			if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
				player2 = 0;
			if(grille[i][j].valeur_pion1 != 3 && grille[i][j].valeur_pion2 != 3)
				player3 = 0;
			if(grille[i][j].valeur_pion1 != 4 && grille[i][j].valeur_pion2 != 4)
				player4 = 0;
			i++;
			j--;
		}
	}

	//Test diagonale gauche
	for(k = 3; k >= 1; k--){
		player1 = 0;
		player2 = 0;
		player3 = 0;
		player4 = 0;
		i = 0;

		j = k;
		while(i <= 6-k && j <= 6){
			if(grille[i][j].valeur_pion1 == 1 || grille[i][j].valeur_pion2 == 1){
				player1++;
				if(player1 == 4)
					return 1;
			}

			if(grille[i][j].valeur_pion1 == 2 || grille[i][j].valeur_pion2 == 2){
				player2++;
				if(player2 == 4)
					return 2;
			}
			if(grille[i][j].valeur_pion1 == 3 || grille[i][j].valeur_pion2 == 3){
				player3++;
				if(player3 == 4)
					return 3;
			}
			if(grille[i][j].valeur_pion1 == 4 || grille[i][j].valeur_pion2 == 4){
				player4++;
				if(player4 == 4)
					return 4;
			}

			if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
				player1 = 0;
			if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
				player2 = 0;
			if(grille[i][j].valeur_pion1 != 3 && grille[i][j].valeur_pion2 != 3)
				player3 = 0;
			if(grille[i][j].valeur_pion1 != 4 && grille[i][j].valeur_pion2 != 4)
				player4 = 0;
			i++;
			j++;
		}
	}

	for(k = 0; k <= 2; k++){
		player1 = 0;
		player2 = 0;
		player3 = 0;
		player4 = 0;
		j = 0;

		i = k;
		while(i <= 6-k && j <= 5-k){
			if(grille[i][j].valeur_pion1 == 1 || grille[i][j].valeur_pion2 == 1){
				player1++;
				if(player1 == 4)
					return 1;
			}

			if(grille[i][j].valeur_pion1 == 2 || grille[i][j].valeur_pion2 == 2){
				player2++;
				if(player2 == 4)
					return 2;
			}
			if(grille[i][j].valeur_pion1 == 3 || grille[i][j].valeur_pion2 == 3){
				player3++;
				if(player3 == 4)
					return 3;
			}
			if(grille[i][j].valeur_pion1 == 4 || grille[i][j].valeur_pion2 == 4){
				player4++;
				if(player4 == 4)
					return 4;
			}

			if(grille[i][j].valeur_pion1 != 1 && grille[i][j].valeur_pion2 != 1)
				player1 = 0;
			if(grille[i][j].valeur_pion1 != 2 && grille[i][j].valeur_pion2 != 2)
				player2 = 0;
			if(grille[i][j].valeur_pion1 != 3 && grille[i][j].valeur_pion2 != 3)
				player3 = 0;
			if(grille[i][j].valeur_pion1 != 4 && grille[i][j].valeur_pion2 != 4)
				player4 = 0;
			i++;
			j++;
		}
	}


	return 0;
}
