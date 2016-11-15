#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 6
#define M 7
#define L 20

void pseudo_classique(char pseudo1[L], char pseudo2[L]){
	system("clear");
	printf("\nVeuillez choisir vos pseudos :\n");
	
	printf("\nJoueur 1 (pions rouges) : ");
	scanf("%s", pseudo1);

	printf("\nJoueur 2 (pions jaunes) : ");
	scanf("%s", pseudo2);
}

void puissance_classique(){
	int grille[N][M];
	int colonne, ligne, pions, nb_pions, num_joueur;
	char joueur1[L],joueur2[L];

	//Initialisation des pseudos
	pseudo_classique(joueur1, joueur2);

	//Initialisation de la matrice et effaçage de l'écran pour afficher la grille vierge
	init_matrice(grille);
	system("clear");
	printf("\nTOUR NUMERO 1\n");
	afficher_matrice(grille);
	
	nb_pions = 21;
	pions = 0;
	while(pions < nb_pions){
		pions ++;

/****************************** JOUEUR 1 JOUE *****************************************/

		num_joueur = 1;

		//Demande où il veut jouer
		printf("%s: Colonne: ",joueur1);
		scanf("%i", &colonne);

		//Affichage du numéro du tour
		system("clear");
		printf("\nTOUR NUMERO %i\n",pions);

		//Placement du prion et mise à jour de la grille
		placer_pions(grille, colonne, num_joueur);
		afficher_matrice(grille);
		
		//Test pour savoir si le joueur à gagné
		if(gagne(grille) == 1)break;

/****************************** JOUEUR 2 JOUE *****************************************/

		num_joueur = 2;
		//Demande où il veut jouer
		printf("%s: Colonne: ",joueur2);
		scanf("%i", &colonne);

		//Affichage du numéro du tour
		system("clear");
		printf("\nTOUR NUMERO %i\n",pions+1);

		//Placement du prion et mise à jour de la grille
		placer_pions(grille, colonne, num_joueur);
		afficher_matrice(grille);

		//Test pour savoir si le joueur à gagné
		if(gagne(grille) == 2)break;
	}

	//Affichage du résultat de la partie
	system("clear");

	if(gagne(grille) == 0)printf("\nMATCH NUL\n\n");

	else if(gagne(grille) == 1)printf("\n%s GAGNE\n\n",joueur1);

	else if(gagne(grille) == 2)printf("\n%s 2 GAGNE\n\n",joueur2);
}
