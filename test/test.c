#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/classique.h"

#define couleur(param) printf("\033[%sm",param)

void fct_test(int grille[N][M], int tour){
	int i, j, nb_joueur1 = 0;

/* Premier cas de test: Joueur 1 qui joue tout en bas à gauche de la grille */
	if(tour == 1){
		i = 5;
		j = 0;

		if(tour == 1 && grille[i][j] != 1)
			printf("\nLe test a rate");
		else
			printf("\nLe test a reussi");

		getchar();
		getchar();
	}

/* Deuxième cas de test: Joueur 1 qui doit gagner en 4 coups sur la première colonne */
	if(tour == 4){
		j = 0;
	
		for(i = 0; i < N; i++){
			if(grille[i][j] == 1)
				nb_joueur1++;
		}
	
		if(tour == 4 && nb_joueur1 == 4)
			printf("\nLe test a reussi");
		else
			printf("\nLe test a rate");

		getchar();
		getchar();
	}
}
