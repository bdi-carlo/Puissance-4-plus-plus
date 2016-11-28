#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "new_fonctions.h"

#define N 6
#define M 7
#define L 20

/**
*\file puissance_avance.c
*\brief Puissance 4 ++
*\author Benjamin, Julien, Arthur
*\version 1.0
*\date Novembre 2016
*/

/**
*\fn void affich_result_avance(t_piece grille[N][M], int win, int tour)
*\brief Afficher le resultat de la partie

*\fn puissance_avance()
*\brief Construction du jeu Puissance 4++

*/

void affich_result_avance(t_piece grille[N][M], int win, int tour){
	system("clear");

	if(win == 0){
		printf("\n ---------------------------------------");
		printf("\n|	         MATCH NUL		|");

		afficher_matrice_avance(grille);
	}

	else if(win == 1){
		printf("\n ---------------------------------------");
		printf("\n|	        joueur1 A GAGNE 		|");

		afficher_matrice_avance(grille);
	}

	else if(win == 2){
		printf("\n ---------------------------------------");
		printf("\n|	        joueur2 A GAGNE 		|");

		afficher_matrice_avance(grille);
	}
	else if(win == 3){
		printf("\n ---------------------------------------");
		printf("\n|	        joueur3 A GAGNE 		|");

		afficher_matrice_avance(grille);
	}
	else if(win == 4){
		printf("\n ---------------------------------------");
		printf("\n|	        joueur4 A GAGNE 		|");

		afficher_matrice_avance(grille);
	}
}

void puissance_avance(){
	t_piece grille[N][M];
	int colonne, ligne, pions, nb_tours, num_joueur, tour, nb_joueurs, type, win, nb_block1, nb_block2, nb_block3, nb_block4 ;
	char joueur1[L],joueur2[L],joueur3[L],joueur4[L];

/****************************** INITIALISATION ****************************************/

	nb_joueurs = nb_joueur() ;
	if(nb_joueurs == 1)
		menu() ;
	else { 

		pseudo_avance(joueur1, joueur2, joueur3, joueur4, nb_joueurs) ;
		//Initialisation de la matrice et effaçage de l'écran pour afficher la grille vierge
		init_matrice_avance(grille);
		system("clear");
		printf("\n ---------------------------------------");
		printf("\n|	       TOUR NUMERO 1		|");
		afficher_matrice_avance(grille);

		win = 0;
		nb_tours = 21;
		pions = 1;
		tour = 1;
		nb_block1 = 2 ;
		nb_block2 = 2 ;
		nb_block3 = 2 ;
		nb_block4 = 2 ;


/****************************** 2 JOUEURS ********************************************/

		if(nb_joueurs == 2) {
			while(!grille_pleine(grille)){

/****************************** JOUEUR 1 JOUE *****************************************/

				num_joueur = 1;

				//Demande où il veut jouer et avec quel type de piece
				do{
					printf("%s : Colonne: ", joueur1);
					scanf("%i", &colonne);

					do{
						printf("Type: - Creuse (1) ");
						printf("\n      - Pleine (2) ");
						printf("\n      - Bloquante (3) ");
						printf("\n\n>> Choix : ");
						scanf("%i", &type);

						//Verification du nombre de piece bloquante
						if(type == 3 && nb_block1 == 0)
								printf("\nVous n'avez plus de piece bloquante.\n");

					}while(type < 1 || type > 3 || (type == 3 && nb_block1 == 0));

					//Verification du nombre de piece bloquante et decrementation si on en a joue une
					if(type == 3 && nb_block1 > 0){
						nb_block1--;
						printf("\nIl vous reste %i piece bloquante a jouer.",nb_block1);
					}

					if(colonne < 1 || colonne > 7)
						printf("Erreur: entrez une colonne entre 1 et 7 compris: ");

					else{
						//Placement du pion sur la grille si et seulement si la colonne le permet
						ligne = choix_ligne_avance(grille, colonne);
						if(ligne < 0)
							printf("Erreur: colonne pleine veuillez en choisir une autre: ");
						else
							placer_pions_avance(grille, colonne, ligne, num_joueur, type);
					}
				}while(colonne < 1 || colonne > 7 || ligne < 0);

				//Affichage du numéro du tour
				system("clear");
				printf("\n ---------------------------------------");
				printf("\n|	       TOUR NUMERO %i		|",pions);

				//Mise à jour de la grille
				afficher_matrice_avance(grille);

				//Test pour savoir si le joueur à gagné
				win = gagne_avance(grille);
				if(win == 1)break;

/****************************** JOUEUR 2 JOUE *****************************************/

				num_joueur = 2;

				//Demande où il veut jouer et avec quel type de piece
				do{
				printf("%s : Colonne: ", joueur2);
				scanf("%i", &colonne);

					do{
						printf("Type: - Creuse (1) ");
						printf("\n      - Pleine (2) ");
						printf("\n      - Bloquante (3) ");
						printf("\n\n>> Choix : ");
						scanf("%i", &type);

					//Verification du nombre de piece bloquante
						if(type == 3 && nb_block2 == 0)
								printf("\nVous n'avez plus de piece bloquante.\n");

					}while(type < 1 || type > 3 || (type == 3 && nb_block2 == 0));

					//Verification du nombre de piece bloquante et decrementation si on en a joue une
					if(type == 3 && nb_block2 > 0){
						nb_block2--;
						printf("\nIl vous reste %i piece bloquante a jouer.",nb_block2);
					}

					if(colonne < 1 || colonne > 7)
						printf("Erreur: entrez une colonne entre 1 et 7 compris: ");

					else{
						//Placement du pion sur la grille si et seulement si la colonne le permet
						ligne = choix_ligne_avance(grille, colonne);
						if(ligne < 0)
							printf("Erreur: colonne pleine veuillez en choisir une autre: ");
						else
							placer_pions_avance(grille, colonne, ligne, num_joueur, type);
					}
				}while(colonne < 1 || colonne > 7 || ligne < 0);

				//Affichage du numéro du tour
				system("clear");
				pions ++;
				printf("\n ---------------------------------------");
				printf("\n|	       TOUR NUMERO %i		|",pions);

				//Mise à jour de la grille
				afficher_matrice_avance(grille);

				//Test pour savoir si le joueur à gagné
				win = gagne_avance(grille);
				if(win == 2)break;
			}
		}

/****************************** 3 JOUEURS ********************************************/
		else if(nb_joueurs == 3) {
			while(!grille_pleine(grille)){

/****************************** JOUEUR 1 JOUE *****************************************/

				num_joueur = 1;

				//Demande où il veut jouer et avec quel type de piece
				do{
					printf("%s : Colonne: ", joueur1);
					scanf("%i", &colonne);

					do{
						printf("Type: - Creuse (1) ");
						printf("\n      - Pleine (2) ");
						printf("\n      - Bloquante (3) ");
						printf("\n\n>> Choix : ");
						scanf("%i", &type);

					//Verification du nombre de piece bloquante
						if(type == 3 && nb_block1 == 0)
								printf("\nVous n'avez plus de piece bloquante.\n");

					}while(type < 1 || type > 3 || (type == 3 && nb_block1 == 0));

					//Verification du nombre de piece bloquante et decrementation si on en a joue une
					if(type == 3 && nb_block1 > 0){
						nb_block1--;
						printf("\nIl vous reste %i piece bloquante a jouer.",nb_block1);
					}

					if(colonne < 1 || colonne > 7)
						printf("Erreur: entrez une colonne entre 1 et 7 compris: ");

					else{
						//Placement du pion sur la grille si et seulement si la colonne le permet
						ligne = choix_ligne_avance(grille, colonne);
						if(ligne < 0)
							printf("Erreur: colonne pleine veuillez en choisir une autre: ");
						else
							placer_pions_avance(grille, colonne, ligne, num_joueur, type);
					}
				}while(colonne < 1 || colonne > 7 || ligne < 0);

				//Affichage du numéro du tour
				system("clear");
				printf("\n ---------------------------------------");
				printf("\n|	       TOUR NUMERO %i		|",pions);

				//Mise à jour de la grille
				afficher_matrice_avance(grille);

				//Test pour savoir si le joueur à gagné
				win = gagne_avance(grille);
				if(win == 1)break;

/****************************** JOUEUR 2 JOUE *****************************************/

				num_joueur = 2;

				//Demande où il veut jouer et avec quel type de piece
				do{
				printf("%s : Colonne: ", joueur2);
				scanf("%i", &colonne);

					do{
						printf("Type: - Creuse (1) ");
						printf("\n      - Pleine (2) ");
						printf("\n      - Bloquante (3) ");
						printf("\n\n>> Choix : ");
						scanf("%i", &type);

					//Verification du nombre de piece bloquante
						if(type == 3 && nb_block2 == 0)
								printf("\nVous n'avez plus de piece bloquante.\n");

					}while(type < 1 || type > 3 || (type == 3 && nb_block2 == 0));

					//Verification du nombre de piece bloquante et decrementation si on en a joue une
					if(type == 3 && nb_block2 > 0){
						nb_block2--;
						printf("\nIl vous reste %i piece bloquante a jouer.",nb_block2);
					}

					if(colonne < 1 || colonne > 7)
						printf("Erreur: entrez une colonne entre 1 et 7 compris: ");

					else{
						//Placement du pion sur la grille si et seulement si la colonne le permet
						ligne = choix_ligne_avance(grille, colonne);
						if(ligne < 0)
							printf("Erreur: colonne pleine veuillez en choisir une autre: ");
						else
							placer_pions_avance(grille, colonne, ligne, num_joueur, type);
					}
				}while(colonne < 1 || colonne > 7 || ligne < 0);

				//Affichage du numéro du tour
				system("clear");
				pions ++;
				printf("\n ---------------------------------------");
				printf("\n|	       TOUR NUMERO %i		|",pions);

				//Mise à jour de la grille
				afficher_matrice_avance(grille);

				//Test pour savoir si le joueur à gagné
				win = gagne_avance(grille);
				if(win == 2)break;

/****************************** JOUEUR 3 JOUE *****************************************/

				num_joueur = 3;

				//Demande où il veut jouer et avec quel type de piece
				do{
				printf("%s : Colonne: ", joueur3);
				scanf("%i", &colonne);

					do{
						printf("Type: - Creuse (1) ");
						printf("\n      - Pleine (2) ");
						printf("\n      - Bloquante (3) ");
						printf("\n\n>> Choix : ");
						scanf("%i", &type);

					//Verification du nombre de piece bloquante
						if(type == 3 && nb_block3 == 0)
								printf("\nVous n'avez plus de piece bloquante.\n");

					}while(type < 1 || type > 3 || (type == 3 && nb_block3 == 0));

					//Verification du nombre de piece bloquante et decrementation si on en a joue une
					if(type == 3 && nb_block3 > 0){
						nb_block3--;
						printf("\nIl vous reste %i piece bloquante a jouer.",nb_block3);
					}

					if(colonne < 1 || colonne > 7)
						printf("Erreur: entrez une colonne entre 1 et 7 compris: ");

					else{
						//Placement du pion sur la grille si et seulement si la colonne le permet
						ligne = choix_ligne_avance(grille, colonne);
						if(ligne < 0)
							printf("Erreur: colonne pleine veuillez en choisir une autre: ");
						else
							placer_pions_avance(grille, colonne, ligne, num_joueur, type);
					}
				}while(colonne < 1 || colonne > 7 || ligne < 0);

				//Affichage du numéro du tour
				system("clear");
				pions ++;
				printf("\n ---------------------------------------");
				printf("\n|	       TOUR NUMERO %i		|",pions);

				//Mise à jour de la grille
				afficher_matrice_avance(grille);

				//Test pour savoir si le joueur à gagné
				win = gagne_avance(grille);
				if(win == 3)break;
			}
		}

/****************************** 4 JOUEURS ********************************************/

		else if(nb_joueurs == 4){

			while(!grille_pleine(grille)){

/****************************** JOUEUR 1 JOUE *****************************************/

				num_joueur = 1;

				//Demande où il veut jouer et avec quel type de piece
				do{
					printf("%s : Colonne: ", joueur1);
					scanf("%i", &colonne);

					do{
						printf("Type: - Creuse (1) ");
						printf("\n      - Pleine (2) ");
						printf("\n      - Bloquante (3) ");
						printf("\n\n>> Choix : ");
						scanf("%i", &type);

					//Verification du nombre de piece bloquante
						if(type == 3 && nb_block1 == 0)
								printf("\nVous n'avez plus de piece bloquante.\n");

					}while(type < 1 || type > 3 || (type == 3 && nb_block1 == 0));

					//Verification du nombre de piece bloquante et decrementation si on en a joue une
					if(type == 3 && nb_block1 > 0){
						nb_block1--;
						printf("\nIl vous reste %i piece bloquante a jouer.",nb_block1);
					}

					if(colonne < 1 || colonne > 7)
						printf("Erreur: entrez une colonne entre 1 et 7 compris: ");

					else{
						//Placement du pion sur la grille si et seulement si la colonne le permet
						ligne = choix_ligne_avance(grille, colonne);
						if(ligne < 0)
							printf("Erreur: colonne pleine veuillez en choisir une autre: ");
						else
							placer_pions_avance(grille, colonne, ligne, num_joueur, type);
					}
				}while(colonne < 1 || colonne > 7 || ligne < 0);

				//Affichage du numéro du tour
				system("clear");
				printf("\n ---------------------------------------");
				printf("\n|	       TOUR NUMERO %i		|",pions);

				//Mise à jour de la grille
				afficher_matrice_avance(grille);

				//Test pour savoir si le joueur à gagné
				win = gagne_avance(grille);
				if(win == 1)break;

/****************************** JOUEUR 2 JOUE *****************************************/

				num_joueur = 2;

				//Demande où il veut jouer et avec quel type de piece
				do{
				printf("%s : Colonne: ", joueur2);
				scanf("%i", &colonne);

					do{
						printf("Type: - Creuse (1) ");
						printf("\n      - Pleine (2) ");
						printf("\n      - Bloquante (3) ");
						printf("\n\n>> Choix : ");
						scanf("%i", &type);

					//Verification du nombre de piece bloquante
						if(type == 3 && nb_block2 == 0)
								printf("\nVous n'avez plus de piece bloquante.\n");

					}while(type < 1 || type > 3 || (type == 3 && nb_block2 == 0));

					//Verification du nombre de piece bloquante et decrementation si on en a joue une
					if(type == 3 && nb_block2 > 0){
						nb_block2--;
						printf("\nIl vous reste %i piece bloquante a jouer.",nb_block2);
					}

					if(colonne < 1 || colonne > 7)
						printf("Erreur: entrez une colonne entre 1 et 7 compris: ");

					else{
						//Placement du pion sur la grille si et seulement si la colonne le permet
						ligne = choix_ligne_avance(grille, colonne);
						if(ligne < 0)
							printf("Erreur: colonne pleine veuillez en choisir une autre: ");
						else
							placer_pions_avance(grille, colonne, ligne, num_joueur, type);
					}
				}while(colonne < 1 || colonne > 7 || ligne < 0);

				//Affichage du numéro du tour
				system("clear");
				pions ++;
				printf("\n ---------------------------------------");
				printf("\n|	       TOUR NUMERO %i		|",pions);

				//Mise à jour de la grille
				afficher_matrice_avance(grille);

				//Test pour savoir si le joueur à gagné
				win = gagne_avance(grille);
				if(win == 2)break;

/****************************** JOUEUR 3 JOUE *****************************************/

				num_joueur = 3;

				//Demande où il veut jouer et avec quel type de piece
				do{
				printf("%s : Colonne: ", joueur3);
				scanf("%i", &colonne);

					do{
						printf("Type: - Creuse (1) ");
						printf("\n      - Pleine (2) ");
						printf("\n      - Bloquante (3) ");
						printf("\n\n>> Choix : ");
						scanf("%i", &type);

					//Verification du nombre de piece bloquante
						if(type == 3 && nb_block3 == 0)
								printf("\nVous n'avez plus de piece bloquante.\n");

					}while(type < 1 || type > 3 || (type == 3 && nb_block3 == 0));

					//Verification du nombre de piece bloquante et decrementation si on en a joue une
					if(type == 3 && nb_block3 > 0){
						nb_block3--;
						printf("\nIl vous reste %i piece bloquante a jouer.",nb_block3);
					}

					if(colonne < 1 || colonne > 7)
						printf("Erreur: entrez une colonne entre 1 et 7 compris: ");

					else{
						//Placement du pion sur la grille si et seulement si la colonne le permet
						ligne = choix_ligne_avance(grille, colonne);
						if(ligne < 0)
							printf("Erreur: colonne pleine veuillez en choisir une autre: ");
						else
							placer_pions_avance(grille, colonne, ligne, num_joueur, type);
					}
				}while(colonne < 1 || colonne > 7 || ligne < 0);

				//Affichage du numéro du tour
				system("clear");
				pions ++;
				printf("\n ---------------------------------------");
				printf("\n|	       TOUR NUMERO %i		|",pions);

				//Mise à jour de la grille
				afficher_matrice_avance(grille);

				//Test pour savoir si le joueur à gagné
				win = gagne_avance(grille);
				if(win == 3)break;


/****************************** JOUEUR 4 JOUE *****************************************/

				num_joueur = 4;

				//Demande où il veut jouer et avec quel type de piece
				do{
				printf("%s : Colonne: ", joueur4);
				scanf("%i", &colonne);

					do{
						printf("Type: - Creuse (1) ");
						printf("\n      - Pleine (2) ");
						printf("\n      - Bloquante (3) ");
						printf("\n\n>> Choix : ");
						scanf("%i", &type);

					//Verification du nombre de piece bloquante
						if(type == 3 && nb_block4 == 0)
								printf("\nVous n'avez plus de piece bloquante.\n");

					}while(type < 1 || type > 3 || (type == 3 && nb_block4 == 0));

					//Verification du nombre de piece bloquante et decrementation si on en a joue une
					if(type == 3 && nb_block4 > 0){
						nb_block4--;
						printf("\nIl vous reste %i piece bloquante a jouer.",nb_block4);
					}

					if(colonne < 1 || colonne > 7)
						printf("Erreur: entrez une colonne entre 1 et 7 compris: ");

					else{
						//Placement du pion sur la grille si et seulement si la colonne le permet
						ligne = choix_ligne_avance(grille, colonne);
						if(ligne < 0)
							printf("Erreur: colonne pleine veuillez en choisir une autre: ");
						else
							placer_pions_avance(grille, colonne, ligne, num_joueur, type);
					}
				}while(colonne < 1 || colonne > 7 || ligne < 0);

				//Affichage du numéro du tour
				system("clear");
				pions ++;
				printf("\n ---------------------------------------");
				printf("\n|	       TOUR NUMERO %i		|",pions);

				//Mise à jour de la grille
				afficher_matrice_avance(grille);

				//Test pour savoir si le joueur à gagné
				win = gagne_avance(grille);
				if(win == 4)break;
				tour++;

			}
		}

/******************** Affichage du résultat de la partie ******************************/

		affich_result_avance(grille, win, tour);
		fin_jeux_avance();
	}
}
