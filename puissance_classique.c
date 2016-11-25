#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "new_fonctions.h"

#define N 6
#define M 7
#define L 20

//Enregistrement du score du gagnant
void enregistrement_score_classique(char joueur[L], int nb_coups){
	FILE * fichier;

	fichier = fopen("best_classique.txt", "a");
	fprintf(fichier, "\n%s	%i", joueur, nb_coups);
	fclose(fichier);
}

//Fonction qui permet d'afficher le resultat de la partie
void affich_result(int grille[N][M], char joueur1[L], char joueur2[L], int tour){
	system("clear");

	if(gagne(grille) == 0){
		printf("\n ---------------------------------------");
		printf("\n|	         MATCH NUL		|");
	
		afficher_matrice(grille);
	}
	
	else if(gagne(grille) == 1){
		printf("\n ---------------------------------------");
		printf("\n|	        %s A GAGNE 		|",joueur1);
		
		afficher_matrice(grille);

		//Enregistre le score du joueur 1
		enregistrement_score_classique(joueur1, tour);
	}

	else if(gagne(grille) == 2){
		printf("\n ---------------------------------------");
		printf("\n|	        %s A GAGNE 		|",joueur2);
		
		afficher_matrice(grille);

		//Enregistre le score du joueur 2
		enregistrement_score_classique(joueur2, tour);
	}	
}

//Programme permettant la construction du jeu Puissance 4 classique
void puissance_classique(){
	int grille[N][M];
	int colonne, ligne, pions, nb_tours, num_joueur, tour;
	char joueur1[L],joueur2[L];

/****************************** INITIALISATION ****************************************/

	//Initialisation des pseudos
	pseudo_classique(joueur1, joueur2);

	//Initialisation de la matrice et effaçage de l'écran pour afficher la grille vierge
	init_matrice(grille);
	system("clear");
	printf("\n ---------------------------------------");
	printf("\n|	       TOUR NUMERO 1		|");
	afficher_matrice(grille);
	
	nb_tours = 21;
	pions = 1;
	tour = 1;
	while(pions <= nb_tours){

/****************************** JOUEUR 1 JOUE *****************************************/

		num_joueur = 1;

		//Demande où il veut jouer
		do{			
			printf("\n%s: Colonne: ",joueur1);
			scanf("%i", &colonne);
			
			if(colonne < 1 || colonne > 7)
				printf("Erreur: entrez une colonne entre 1 et 7 compris: ");
			
			else{
				//Placement du pion sur la grille si et seulement si la colonne le permet
				ligne = choix_ligne(grille, colonne);
				if(ligne < 0)
					printf("Erreur: colonne pleine veuillez en choisir une autre: ");
				else
					placer_pions(grille, colonne, ligne, num_joueur);
			}
		}while(colonne < 1 || colonne > 7 || ligne < 0);
		
		//Affichage du numéro du tour
		system("clear");
		printf("\n ---------------------------------------");
		printf("\n|	       TOUR NUMERO %i		|",pions);

		//Mise à jour de la grille
		afficher_matrice(grille);
		
		//Test pour savoir si le joueur à gagné
		if(gagne(grille) == 1)break;

/****************************** JOUEUR 2 JOUE *****************************************/

		num_joueur = 2;
		
		//Demande où il veut jouer
		do{			
			printf("\n%s: Colonne: ",joueur2);
			scanf("%i", &colonne);
			
			if(colonne < 1 || colonne > 7)
				printf("Erreur: entrez une colonne entre 1 et 7 compris: ");
			
			else{
				//Placement du pion sur la grille si et seulement si la colonne le permet
				ligne = choix_ligne(grille, colonne);
				if(ligne < 0)
					printf("Erreur: colonne pleine veuillez en choisir une autre: ");
				else
					placer_pions(grille, colonne, ligne, num_joueur);
			}
		}while(colonne < 1 || colonne > 7 || ligne < 0);

		//Affichage du numéro du tour
		system("clear");
		pions ++;
		printf("\n ---------------------------------------");
		printf("\n|	       TOUR NUMERO %i		|",pions);

		//Mise à jour de la grille
		afficher_matrice(grille);

		//Test pour savoir si le joueur à gagné
		if(gagne(grille) == 2)break;
		tour++;
	}

/******************** Affichage du résultat de la partie ******************************/

	affich_result(grille, joueur1, joueur2, tour);
	fin_jeux() ;
}
