#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/classique.h"

#define couleur(param) printf("\033[%sm",param)

/**

*\file puissance_classique.c
*\brief Puissance 4 classique
*\author Benjamin, Julien, Arthur
*\version 1.0
*\date Novembre 2016

*/

/**
*\fn void enregistrement_score_classique(char joueur[L], int nb_coups)
*\brief Enregistrement du score du gagnant

*\fn void affich_result(int grille[N][M], char joueur1[L], char joueur2[L], int tour)
*\brief Affichage du resultat de la partie

*\fn void puissance_classique()
*\brief Construction du Puissance 4 classique
*/


void enregistrement_score_classique(char joueur[L], int nb_coups){
	FILE * fichier;

	fichier = fopen("best_classique.txt", "a");
	fprintf(fichier, "\n%s", joueur);
	fprintf(fichier, " %i", nb_coups);
	fclose(fichier);
}

void affich_result(int grille[N][M], char joueur1[L], char joueur2[L], int tour){
	system("clear");

	if(gagne(grille) == 0){
		printf("\n+---------------------------------------+");
		printf("\n|	         MATCH NUL		|");
	
		afficher_matrice(grille);
		
		//On supprime la partie enregistree car on a fini la partie en cours
		remove ("partie_classique.txt");
	}
	
	else if(gagne(grille) == 1){
		printf("\n+---------------------------------------+");
		printf("\n|	        %s A GAGNE 		|",joueur1);
		
		afficher_matrice(grille);

		//Enregistre le score du joueur 1
		enregistrement_score_classique(joueur1, tour);

		//On supprime la partie enregistree car on a fini la partie en cours
		remove ("partie_classique.txt");
	}

	else if(gagne(grille) == 2){
		printf("\n+---------------------------------------+");
		printf("\n|	        %s A GAGNE 		|",joueur2);
		
		afficher_matrice(grille);

		//Enregistre le score du joueur 2
		enregistrement_score_classique(joueur2, tour);
		
		//On supprime la partie enregistree car on a fini la partie en cours
		remove ("partie_classique.txt");
	}	
}

void puissance_classique(){
	int grille[N][M];
	int colonne, ligne, pions, nb_tours, num_joueur, tour, test, party, debut;
	char joueur1[L],joueur2[L];

/****************************** INITIALISATION ****************************************/
	party = 0;
	debut = 0;
	
	//Demande aux joueurs si ils veulent reprendre une partie en cours ou non
	debut = begin();
	if(debut != 3){
		if(debut == 2){
			party = load_classique(grille, &tour, joueur1, joueur2);
			if(party == 0)	
				pions = tour;
		}

		if((party == 1 && debut == 2) || debut == 1){
			//Initialisation des pseudos
			pseudo_classique(joueur1, joueur2, party, debut);

			//Initialisation de la matrice et effaçage de l'écran pour afficher la grille vierge
			init_matrice(grille);

			pions = 1;
			tour = 1;
		}
	
		system("clear");	
		printf("\n+---------------------------------------+");
		printf("\n|	       TOUR NUMERO %i		|",pions);
		afficher_matrice(grille);
	
		test = 0;
		nb_tours = 21;

		while(pions <= nb_tours){

/****************************** JOUEUR 1 JOUE *****************************************/

			num_joueur = 1;
		
			couleur("31");
			printf("		  %s  ",joueur1);
			couleur("0");
			printf("\nRentrer 10 si vous voulez quitter maintenant.\n");
		
			//Demande où il veut jouer
			do{			
				printf("\nColonne: ");
				scanf("%i", &colonne);
			
				if((colonne < 1 || colonne > 7) && colonne != 10)
					printf("Erreur: entrez une colonne entre 1 et 7 compris: ");
			
				else if(colonne != 10){
					//Placement du pion sur la grille si et seulement si la colonne le permet
					ligne = choix_ligne(grille, colonne);
					if(ligne < 0)
						printf("Erreur: colonne pleine veuillez en choisir une autre: ");
					else
						placer_pions(grille, colonne, ligne, num_joueur);
				}
			}while(((colonne < 1 || colonne > 7) && colonne != 10) || ligne < 0);

			//Si le joueur choisi de quitter la partie en cours
			if(colonne == 10){
				test = 1;
				if(quitter() == 2)
					save_quit_classique(grille, tour, joueur1, joueur2);
				break;
			}
		
			//Affichage du numéro du tour
			system("clear");
			printf("\n ---------------------------------------");
			printf("\n|	       TOUR NUMERO %i		|", pions);

			//Mise à jour de la grille
			afficher_matrice(grille);
		
			//Test pour savoir si le joueur à gagné
			if(gagne(grille) == 1)break;

/****************************** JOUEUR 2 JOUE *****************************************/

			num_joueur = 2;
			
			couleur("34");
			printf("		  %s  ",joueur2);
			couleur("0");
			
			//Demande où il veut jouer
			do{			
				printf("\nColonne: ");
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

/***************** Affichage du résultat de la partie et des meilleurs scores *****************/

		if(test == 0){
			affich_result(grille, joueur1, joueur2, tour);
			affich_score_classique();
		}
/***************** Menu de fin de Jeu *****************/
		fin_jeux();
	}
	if(debut == 3)
		menu();
}
