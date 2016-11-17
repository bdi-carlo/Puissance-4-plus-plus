#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "new_fonctions.h"
#define N 6
#define M 7
#define L 20

//Enregistrement du score du gagnant
void save_score_avance(char joueur[L], int nb_coups){
	FILE * fichier;

	fichier = fopen("best_avance.txt", "a");
	fprintf(fichier, "\n%s	%i", joueur, nb_coups);
	fclose(fichier);
}

//Affiche le résultat de la partie
void affich_result(int grille[N][M], char joueur1[L], char joueur2[L], char joueur3[L], char joueur4[L], int tour){
	system("clear");

	if(gagne_avance(grille) == 0){
		printf("\nMATCH NUL\n\n");
	
		afficher_matrice_avance(grille);
	}
	
	else if(gagne_avance(grille) == 1){
		printf("\n%s GAGNE\n\n",joueur1);
		
		afficher_matrice_avance(grille);

		//Enregistre le score du joueur 1
		save_score_avance(joueur1, tour);
	}

	else if(gagne_avance(grille) == 2){
		printf("\n%s GAGNE\n\n",joueur2);
		
		afficher_matrice_avance(grille);

		//Enregistre le score du joueur 2
		save_score_avance(joueur2, tour);
	}
	
	else if(gagne_avance(grille) == 3){
		printf("\n%s GAGNE\n\n",joueur3);
		
		afficher_matrice_avance(grille);

		//Enregistre le score du joueur 3
		save_score_avance(joueur3, tour);
	}

	else if(gagne_avance(grille) == 4){
		printf("\n%s GAGNE\n\n",joueur4);
		
		afficher_matrice_avance(grille);

		//Enregistre le score du joueur 4
		save_score_avance(joueur4, tour);
	}
}

//Programme permettant la construction du jeu Puissance 4 classique
void puissance_avance(){
	int grille[N][M];
	int colonne, ligne, pions, nb_tours, num_joueur, tour, nb_joueurs;
	char joueur1[L],joueur2[L],joueur3[L],joueur4[L];

/****************************** INITIALISATION ****************************************/

	//Demande à l'utilisateur le nombre de joueurs
	nb_joueurs = nb_joueur();

	//Initialisation des pseudos
	pseudo_avance(joueur1, joueur2, joueur3, joueur4, nb_joueurs);

	//Initialisation de la matrice et effaçage de l'écran pour afficher la grille vierge
	init_matrice(grille);
	system("clear");
	printf("\nTOUR NUMERO 1\n");
	afficher_matrice_avance(grille);
	
	pions = 1;
	tour = 1;


/****************************** DEUX JOUEURS ****************************************/
	if(nb_joueurs == 2){

		nb_tours = 21;
		while(pions <= nb_tours){

/****************************** JOUEUR 1 JOUE *****************************************/

			num_joueur = 1;

			//Demande où il veut jouer
			do{			
				printf("%s: Colonne: ",joueur1);
				scanf("%i", &colonne);
			
				if(colonne < 1 || colonne > 7)
					printf("Erreur: entrez une colonne entre 1 et 7 compris: ");
			
				else{
					//Placement du pion sur la grille si et seulement si la colonne le permet
					ligne = choix_ligne(grille, colonne);
					if(ligne < 0)
						printf("Erreur: colonne pleine veuillez en choisir une autre: ");
					else
						placer_pions_avance(grille, colonne, num_joueur);
				}
			}while(colonne < 1 || colonne > 7 || ligne < 0);
		
			//Affichage du numéro du tour
			system("clear");
			printf("\nTOUR NUMERO %i\n",pions);

			//Mise à jour de la grille
			afficher_matrice_avance(grille);
		
			//Test pour savoir si le joueur à gagné
			if(gagne_avance(grille) == 1)break;

/****************************** JOUEUR 2 JOUE *****************************************/

			num_joueur = 2;
		
			//Demande où il veut jouer
			do{			
				printf("%s: Colonne: ",joueur2);
				scanf("%i", &colonne);
			
				if(colonne < 1 || colonne > 7)
					printf("Erreur: entrez une colonne entre 1 et 7 compris: ");
			
				else{
					//Placement du pion sur la grille si et seulement si la colonne le permet
					ligne = choix_ligne(grille, colonne);
					if(ligne < 0)
						printf("Erreur: colonne pleine veuillez en choisir une autre: ");
					else
						placer_pions_avance(grille, colonne, num_joueur);
				}
			}while(colonne < 1 || colonne > 7 || ligne < 0);

			//Affichage du numéro du tour
			system("clear");
			printf("\nTOUR NUMERO %i\n",pions);

			//Mise à jour de la grille
			afficher_matrice_avance(grille);

			//Test pour savoir si le joueur à gagné
			if(gagne_avance(grille) == 2)break;
			if(tour == 11) break;
		}
	}



/****************************** TROIS JOUEURS ****************************************/
	else if(nb_joueurs == 3){

		nb_tours = 14;
		while(pions <= nb_tours){

/****************************** JOUEUR 1 JOUE *****************************************/

			num_joueur = 1;

			//Demande où il veut jouer
			do{			
				printf("%s: Colonne: ",joueur1);
				scanf("%i", &colonne);
			
				if(colonne < 1 || colonne > 7)
					printf("Erreur: entrez une colonne entre 1 et 7 compris: ");
			
				else{
					//Placement du pion sur la grille si et seulement si la colonne le permet
					ligne = choix_ligne(grille, colonne);
					if(ligne < 0)
						printf("Erreur: colonne pleine veuillez en choisir une autre: ");
					else
						placer_pions_avance(grille, colonne, num_joueur);
				}
			}while(colonne < 1 || colonne > 7 || ligne < 0);
		
			//Affichage du numéro du tour
			system("clear");
			printf("\nTOUR NUMERO %i\n",pions);

			//Mise à jour de la grille
			afficher_matrice_avance(grille);
		
			//Test pour savoir si le joueur à gagné
			if(gagne_avance(grille) == 1)break;

/****************************** JOUEUR 2 JOUE *****************************************/

			num_joueur = 2;
		
			//Demande où il veut jouer
			do{			
				printf("%s: Colonne: ",joueur2);
				scanf("%i", &colonne);
			
				if(colonne < 1 || colonne > 7)
					printf("Erreur: entrez une colonne entre 1 et 7 compris: ");
			
				else{
					//Placement du pion sur la grille si et seulement si la colonne le permet
					ligne = choix_ligne(grille, colonne);
					if(ligne < 0)
						printf("Erreur: colonne pleine veuillez en choisir une autre: ");
					else
						placer_pions_avance(grille, colonne, num_joueur);
				}
			}while(colonne < 1 || colonne > 7 || ligne < 0);

			//Affichage du numéro du tour
			system("clear");
			printf("\nTOUR NUMERO %i\n",pions);

			//Mise à jour de la grille
			afficher_matrice_avance(grille);

			//Test pour savoir si le joueur à gagné
			if(gagne_avance(grille) == 2)break;
			if(tour == 11) break; 

/****************************** JOUEUR 3 JOUE *****************************************/

			num_joueur = 3;

			//Demande où il veut jouer
			do{			
				printf("%s: Colonne: ",joueur3);
				scanf("%i", &colonne);
			
				if(colonne < 1 || colonne > 7)
					printf("Erreur: entrez une colonne entre 1 et 7 compris: ");
			
				else{
					//Placement du pion sur la grille si et seulement si la colonne le permet
					ligne = choix_ligne(grille, colonne);
					if(ligne < 0)
						printf("Erreur: colonne pleine veuillez en choisir une autre: ");
					else
						placer_pions_avance(grille, colonne, num_joueur);
				}
			}while(colonne < 1 || colonne > 7 || ligne < 0);
		
			//Affichage du numéro du tour
			system("clear");
			printf("\nTOUR NUMERO %i\n",pions);

			//Mise à jour de la grille
			afficher_matrice_avance(grille);
		
			//Test pour savoir si le joueur à gagné
			if(gagne_avance(grille) == 3)break;
		}
	}



/****************************** QUATRE JOUEURS ****************************************/
	else if(nb_joueurs == 4){

		nb_tours = 12;
		while(pions <= nb_tours){

/****************************** JOUEUR 1 JOUE *****************************************/

			num_joueur = 1;

			//Demande où il veut jouer
			do{			
				printf("%s: Colonne: ",joueur1);
				scanf("%i", &colonne);
			
				if(colonne < 1 || colonne > 7)
					printf("Erreur: entrez une colonne entre 1 et 7 compris: ");
			
				else{
					//Placement du pion sur la grille si et seulement si la colonne le permet
					ligne = choix_ligne(grille, colonne);
					if(ligne < 0)
						printf("Erreur: colonne pleine veuillez en choisir une autre: ");
					else
						placer_pions_avance(grille, colonne, num_joueur);
				}
			}while(colonne < 1 || colonne > 7 || ligne < 0);
		
			//Affichage du numéro du tour
			system("clear");
			printf("\nTOUR NUMERO %i\n",pions);

			//Mise à jour de la grille
			afficher_matrice_avance(grille);
		
			//Test pour savoir si le joueur à gagné
			if(gagne_avance(grille) == 1)break;

/****************************** JOUEUR 2 JOUE *****************************************/

			num_joueur = 2;
		
			//Demande où il veut jouer
			do{			
				printf("%s: Colonne: ",joueur2);
				scanf("%i", &colonne);
			
				if(colonne < 1 || colonne > 7)
					printf("Erreur: entrez une colonne entre 1 et 7 compris: ");
			
				else{
					//Placement du pion sur la grille si et seulement si la colonne le permet
					ligne = choix_ligne(grille, colonne);
					if(ligne < 0)
						printf("Erreur: colonne pleine veuillez en choisir une autre: ");
					else
						placer_pions_avance(grille, colonne, num_joueur);
				}
			}while(colonne < 1 || colonne > 7 || ligne < 0);

			//Affichage du numéro du tour
			system("clear");
			printf("\nTOUR NUMERO %i\n",pions);

			//Mise à jour de la grille
			afficher_matrice_avance(grille);

			//Test pour savoir si le joueur à gagné
			if(gagne_avance(grille) == 2)break;
			if(tour == 11) break; 

/****************************** JOUEUR 3 JOUE *****************************************/

			num_joueur = 3;

			//Demande où il veut jouer
			do{			
				printf("%s: Colonne: ",joueur3);
				scanf("%i", &colonne);
			
				if(colonne < 1 || colonne > 7)
					printf("Erreur: entrez une colonne entre 1 et 7 compris: ");
			
				else{
					//Placement du pion sur la grille si et seulement si la colonne le permet
					ligne = choix_ligne(grille, colonne);
					if(ligne < 0)
						printf("Erreur: colonne pleine veuillez en choisir une autre: ");
					else
						placer_pions_avance(grille, colonne, num_joueur);
				}
			}while(colonne < 1 || colonne > 7 || ligne < 0);
		
			//Affichage du numéro du tour
			system("clear");
			printf("\nTOUR NUMERO %i\n",pions);

			//Mise à jour de la grille
			afficher_matrice_avance(grille);
		
			//Test pour savoir si le joueur à gagné
			if(gagne_avance(grille) == 3)break;

/****************************** JOUEUR 4 JOUE *****************************************/

			num_joueur = 4;

			//Demande où il veut jouer
			do{			
				printf("%s: Colonne: ",joueur4);
				scanf("%i", &colonne);
			
				if(colonne < 1 || colonne > 7)
					printf("Erreur: entrez une colonne entre 1 et 7 compris: ");
			
				else{
					//Placement du pion sur la grille si et seulement si la colonne le permet
					ligne = choix_ligne(grille, colonne);
					if(ligne < 0)
						printf("Erreur: colonne pleine veuillez en choisir une autre: ");
					else
						placer_pions_avance(grille, colonne, num_joueur);
				}
			}while(colonne < 1 || colonne > 7 || ligne < 0);
		
			//Affichage du numéro du tour
			system("clear");
			pions ++;
			printf("\nTOUR NUMERO %i\n",pions);

			//Mise à jour de la grille
			afficher_matrice_avance(grille);
		
			//Test pour savoir si le joueur à gagné
			if(gagne_avance(grille) == 4)break;
			tour++;
		}


/******************** Affichage du résultat de la partie ******************************/
	
	affich_result(grille, joueur1, joueur2, joueur3, joueur4, tour);

	}
}
