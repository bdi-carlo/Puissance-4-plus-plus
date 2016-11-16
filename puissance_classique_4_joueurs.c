#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "new_fonctions.h"
#define N 6
#define M 7
#define L 20

//Demande aux joueurs leur pseudo
void pseudo_classique(char pseudo1[L], char pseudo2[L]), char pseudo3[L], char pseudo4[L]){
	system("clear");
	printf("\nVeuillez choisir vos pseudos :\n");
	
	printf("\nJoueur 1 (pions rouges) : ");
	scanf("%s", pseudo1);

	printf("\nJoueur 2 (pions bleus) : ");
	scanf("%s", pseudo2);
	
	printf("\nJoueur 3 (pions magentas) : ");
	scanf("%s", pseudo3);
	
	printf("\nJoueur 4 (pions verts) : ");
	scanf("%s", pseudo4);
}

//Enregistrement du score du gagnant
void enregistrement_score_classique(char joueur[L], int nb_coups){
		FILE * fichier;

		fichier = fopen("best_classique.txt", "a");
		fprintf(fichier, "\n%s	%i", joueur, nb_coups);
		fclose(fichier);
}

//Programme permettant la construction du jeu Puissance 4 classique
void puissance_classique(){
	int grille[N][M];
	int colonne, ligne, pions, nb_pions, num_joueur;
	char joueur1[L],joueur2[L],joueur3[L],joueur4[L];

/****************************** INITIALISATION ****************************************/

	//Initialisation des pseudos
	pseudo_classique(joueur1, joueur2);

	//Initialisation de la matrice et effaçage de l'écran pour afficher la grille vierge
	init_matrice(grille);
	system("clear");
	printf("\nTOUR NUMERO 1\n");
	afficher_matrice(grille);
	
	nb_pions = 21;
	pions = 1;
	while(pions < nb_pions){

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
		pions ++;
		printf("\nTOUR NUMERO %i\n",pions);

		//Placement du pion et mise à jour de la grille
		placer_pions(grille, colonne, num_joueur);
		afficher_matrice(grille);

		//Test pour savoir si le joueur à gagné
		if(gagne(grille) == 2)break;
	
	
/****************************** JOUEUR 3 JOUE *****************************************/

		num_joueur = 3;
		//Demande où il veut jouer
		printf("%s: Colonne: ",joueur3);
		scanf("%i", &colonne);

		//Affichage du numéro du tour
		system("clear");
		pions ++;
		printf("\nTOUR NUMERO %i\n",pions);

		//Placement du pion et mise à jour de la grille
		placer_pions(grille, colonne, num_joueur);
		afficher_matrice(grille);

		//Test pour savoir si le joueur à gagné
		if(gagne(grille) == 3)break;
	
	
/****************************** JOUEUR 4 JOUE *****************************************/

		num_joueur = 4;
		//Demande où il veut jouer
		printf("%s: Colonne: ",joueur4);
		scanf("%i", &colonne);

		//Affichage du numéro du tour
		system("clear");
		pions ++;
		printf("\nTOUR NUMERO %i\n",pions);

		//Placement du pion et mise à jour de la grille
		placer_pions(grille, colonne, num_joueur);
		afficher_matrice(grille);

		//Test pour savoir si le joueur à gagné
		if(gagne(grille) == 4)break;
	}

/******************** Affichage du résultat de la partie ******************************/
resultat();