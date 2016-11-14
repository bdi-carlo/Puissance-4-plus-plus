#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 6
#define M 7

void puissance_classique(){
	int grille[N][M];
	int colonne, ligne, pions, nb_pions, num_joueur;

	init_matrice(grille);
	system("clear");
	printf("\nTOUR NUMERO 1\n");
	afficher_matrice(grille);
	
	nb_pions = 21;
	pions = 0;
	while(pions < nb_pions){
		pions ++;

		//Le joueur 1 joue
		num_joueur = 1;
		printf("Joueur 1: Colonne: ");
		scanf("%i", &colonne);

		system("clear");
		printf("\nTOUR NUMERO %i\n",pions);
		placer_pions(grille, colonne, num_joueur);
		afficher_matrice(grille);
		
		if(gagne(grille) == 1)break;

		//Le joueur 2 joue
		num_joueur = 2;
		printf("Joueur 2: Colonne: ");
		scanf("%i", &colonne);

		system("clear");
		printf("\nTOUR NUMERO %i\n",pions+1);
		placer_pions(grille, colonne, num_joueur);
		afficher_matrice(grille);

		if(gagne(grille) == 2)break;
	}

	system("clear");
	if(gagne(grille) == 0)printf("\nMATCH NUL\n\n");

	else if(gagne(grille) == 1)printf("\nJOUEUR 1 GAGNE\n\n");

	else if(gagne(grille) == 2)printf("\nJOUEUR 2 GAGNE\n\n");
}
