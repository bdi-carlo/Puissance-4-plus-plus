#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/classique.h"
#include "../include/avance.h"

#define couleur(param) printf("\033[%sm",param)

/**

*\file puissance_avance.c
*\brief Puissance 4 classique
*\author Benjamin, Julien, Arthur
*\version 1.0
*\date Novembre 2016

*/



/**

*\fn int player1(t_piece grille[N][M], int *nb_block1, int pions, char pseudo1[L], char pseudo2[L], char pseudo3[L], char pseudo4[L], int nb_joueurs, int tour, int nb_block2, int nb_block3, int nb_block4)
*\brief Permet au Joueur 1 de jouer ou de quitter et d'enregistrer la partie
*\return 0 si le joueur a joué, 10 s'il a quitté la partie

*/
int player1(t_piece grille[N][M], int *nb_block1, int pions, char pseudo1[L], char pseudo2[L], char pseudo3[L], char pseudo4[L], int nb_joueurs, int tour, int nb_block2, int nb_block3, int nb_block4){
	int num_joueur, ligne, colonne, test;
	unsigned int type;

	num_joueur = 1;

	//Affichage du pseudo
	couleur("31");
	printf("		  %s  ",pseudo1);
	couleur("0");
	printf("\nRentrer 10 si vous voulez quitter maintenant.\n");
	
	//Demande où il veut jouer et avec quel type de piece
	do{

		//Demande la colonne ou il veut jouer
		do{
			printf("\nColonne: ");
			scanf("%i", &colonne);
			printf("\n");
			if((colonne < 1 || colonne > 7) && colonne != 10)
				printf("Erreur: entrez une colonne entre 1 et 7 compris: ");
				
		}while((colonne < 1 || colonne > 7) && colonne != 10);

		//Le joueur choisi de quitter la partie, il peut sauvegarder ou non, puis on retourne 10
		if(colonne == 10){
			if(quitter() == 2)
				save_quit_avance(grille, tour, pseudo1, pseudo2, pseudo3, pseudo4, nb_joueurs, *nb_block1, nb_block2, nb_block3, nb_block4);
			return 10;
		}

		//Choix du type de la piece
		do{
			printf("Type: - Creuse (1) ");
			printf("\n      - Pleine (2) ");
			printf("\n      - Bloquante (3) ");
			printf("\n\n>> Choix : ");
			scanf("%i", &type);
				
			//Verification du nombre de piece bloquante
			if(type == 3 && *nb_block1 == 0)
					printf("\n%s n'a plus de piece bloquante.\n", pseudo1);
			//Verifie si le choix est valide
			if(type < 1 || type > 3)
				printf("Erreur: entrez un type de piece entre 1 et 3 compris: \n");
		}while(type < 1 || type > 3 || (type == 3 && *nb_block1 == 0));
			
		//Verification du nombre de piece bloquante et decrementation si on en a joue une
		if(type == 3 && *nb_block1 > 0){
			(*nb_block1)--;
			printf("\n%s: Reste %i piece bloquante a joue.", pseudo1, *nb_block1);
		}			

		//Placement du pion sur la grille, on redemande les etapes precedentes si la colonne est pleine
		test = 0;
		ligne = choix_ligne_avance(grille, colonne);

		//Dans le cas ou la premiere ligne vide est au dessus de la grille on regarde si la colonne contient des solutions ou non
		if(ligne < 0){
			//Verifie si la colonne est pleine
			if(grille[ligne+1][colonne-1].type1 == bloquante || type == bloquante || grille[ligne+1][colonne-1].type1 == type || grille[ligne+1][colonne-1].valeur_pion2 != 0){
				printf("Erreur: colonne pleine veuillez en choisir une autre: ");
				test = 1;
			}
			else if(grille[ligne+1][colonne-1].type1 != type && grille[ligne+1][colonne-1].valeur_pion2 == 0)
				placer_pions_avance(grille, colonne, ligne, num_joueur, type);
		}
		else
			placer_pions_avance(grille, colonne, ligne, num_joueur, type);
		
	}while(test == 1);
		
	//Affichage du numéro du tour
	system("clear");
	printf("\n+---------------------------------------+");
	printf("\n|	       TOUR NUMERO %i		|",pions);

	//Mise à jour de la grille
	afficher_matrice_avance(grille);
	couleur("0");

	return 0;
}

/**

*\fn void player2(t_piece grille[N][M], int *nb_block2, int pions, char pseudo2[L])
*\brief Choix du type et de la position de la pièce du Joueur 2

*/
void player2(t_piece grille[N][M], int *nb_block2, int pions, char pseudo2[L]){
	int num_joueur, ligne, colonne, test;
	unsigned int type;

	num_joueur = 2;
	
	//Affichage du pseudo
	couleur("34");
	printf("		  %s  ",pseudo2);
	couleur("0");
	
	//Demande où il veut jouer et avec quel type de piece
	do{		

		//Demande la colonne ou il veut jouer	
		do{
			
			printf("\nColonne: ");
			scanf("%i", &colonne);
			printf("\n");
			if(colonne < 1 || colonne > 7)
				printf("Erreur: entrez une colonne entre 1 et 7 compris: ");
		}while(colonne < 1 || colonne > 7);

		//Choix du type de la piece
		do{
			printf("Type: - Creuse (1) ");
			printf("\n      - Pleine (2) ");
			printf("\n      - Bloquante (3) ");
			printf("\n\n>> Choix : ");
			scanf("%i", &type);
				
			//Verification du nombre de piece bloquante
			if(type == 3 && *nb_block2 == 0)
					printf("\n%s n'a plus de piece bloquante.\n", pseudo2);
			//Verifie si le choix est valide
			if(type < 1 || type > 3)
				printf("Erreur: entrez un type de piece entre 1 et 3 compris: \n");
		}while(type < 1 || type > 3 || (type == 3 && *nb_block2 == 0));
			
		//Verification du nombre de piece bloquante et decrementation si on en a joue une
		if(type == 3 && *nb_block2 > 0){
			(*nb_block2)--;
			printf("\n%s: Reste %i piece bloquante a joue.", pseudo2, *nb_block2);
		}
		
		//Placement du pion sur la grille si et seulement si la colonne le permet
		test = 0;
		ligne = choix_ligne_avance(grille, colonne);

		//Dans le cas ou la premiere ligne vide est au dessus de la grille on regarde si la colonne contient des solutions ou non
		if(ligne < 0){
			//Verifie si la colonne est pleine
			if(grille[ligne+1][colonne-1].type1 == bloquante || type == bloquante || grille[ligne+1][colonne-1].type1 == type || grille[ligne+1][colonne-1].valeur_pion2 != 0){
				printf("Erreur: colonne pleine veuillez en choisir une autre: ");
				test = 1;
			}
			else if(grille[ligne+1][colonne-1].type1 != type && grille[ligne+1][colonne-1].valeur_pion2 == 0)
				placer_pions_avance(grille, colonne, ligne, num_joueur, type);
		}
		else
			placer_pions_avance(grille, colonne, ligne, num_joueur, type);
			
	}while(test == 1);
		
	//Affichage du numéro du tour
	system("clear");
	printf("\n+---------------------------------------+");
	printf("\n|	       TOUR NUMERO %i		|",pions);

	//Mise à jour de la grille
	afficher_matrice_avance(grille);
	couleur("0");
}

/**

*\fn void player3(t_piece grille[N][M], int *nb_block3, int pions, char pseudo3[L])
*\brief Choix du type et de la position de la pièce du Joueur 3

*/
void player3(t_piece grille[N][M], int *nb_block3, int pions, char pseudo3[L]){
	int num_joueur, ligne, colonne, test;
	unsigned int type;

	num_joueur = 3;
	couleur("33");
	printf("		   %s  ",pseudo3);
	couleur("0");
	//Demande où il veut jouer et avec quel type de piece
	do{			
		do{
			
			printf("\nColonne: ");
			scanf("%i", &colonne);
			printf("\n");
			if(colonne < 1 || colonne > 7)
				printf("Erreur: entrez une colonne entre 1 et 7 compris: ");
		}while(colonne < 1 || colonne > 7);
		do{
			printf("Type: - Creuse (1) ");
			printf("\n      - Pleine (2) ");
			printf("\n      - Bloquante (3) ");
			printf("\n\n>> Choix : ");
			scanf("%i", &type);
				
			//Verification du nombre de piece bloquante
			if(type == 3 && *nb_block3 == 0)
					printf("\n%s n'a plus de piece bloquante.\n", pseudo3);
			if(type < 1 || type > 3)
				printf("Erreur: entrez un type de piece entre 1 et 3 compris: \n");
		}while(type < 1 || type > 3 || (type == 3 && *nb_block3 == 0));
			
		//Verification du nombre de piece bloquante et decrementation si on en a joue une
		if(type == 3 && *nb_block3 > 0){
			(*nb_block3)--;
			printf("\n%s: Reste %i piece bloquante a joue.", pseudo3, *nb_block3);
		}

		//Placement du pion sur la grille si et seulement si la colonne le permet
		test = 0;
		ligne = choix_ligne_avance(grille, colonne);
		if(ligne < 0){
			if(grille[ligne+1][colonne-1].type1 == bloquante || type == bloquante || grille[ligne+1][colonne-1].type1 == type || grille[ligne+1][colonne-1].valeur_pion2 != 0){
				printf("Erreur: colonne pleine veuillez en choisir une autre: ");
				test = 1;
			}
			else if(grille[ligne+1][colonne-1].type1 != type && grille[ligne+1][colonne-1].valeur_pion2 == 0)
				placer_pions_avance(grille, colonne, ligne, num_joueur, type);
		}
		else
			placer_pions_avance(grille, colonne, ligne, num_joueur, type);
			
	}while(test == 1);
		
	//Affichage du numéro du tour
	system("clear");
	printf("\n+---------------------------------------+");
	printf("\n|	       TOUR NUMERO %i		|",pions);

	//Mise à jour de la grille
	afficher_matrice_avance(grille);
	couleur("0");
}

/**
*\fn void player4(t_piece grille[N][M], int *nb_block4, int pions, char pseudo4[L])
*\brief Choix du type et de la position de la pièce du Joueur 4

*/
void player4(t_piece grille[N][M], int *nb_block4, int pions, char pseudo4[L]){
	int num_joueur, ligne, colonne, test;
	unsigned int type;

	num_joueur = 4;
	couleur("32");
	printf("		   %s  ",pseudo4);
	couleur("0");
	//Demande où il veut jouer et avec quel type de piece
	do{			
		do{
			
			printf("\nColonne: ");
			scanf("%i", &colonne);
			printf("\n");
			if(colonne < 1 || colonne > 7)
				printf("Erreur: entrez une colonne entre 1 et 7 compris: ");
		}while(colonne < 1 || colonne > 7);
		do{
			printf("Type: - Creuse (1) ");
			printf("\n      - Pleine (2) ");
			printf("\n      - Bloquante (3) ");
			printf("\n\n>> Choix : ");
			scanf("%i", &type);
				
			//Verification du nombre de piece bloquante
			if(type == 3 && *nb_block4 == 0)
					printf("\n%s n'a plus de piece bloquante.\n", pseudo4);
			if(type < 1 || type > 3)
				printf("Erreur: entrez un type de piece entre 1 et 3 compris: \n");
		}while(type < 1 || type > 3 || (type == 3 && *nb_block4 == 0));
			
		//Verification du nombre de piece bloquante et decrementation si on en a joue une
		if(type == 3 && *nb_block4 > 0){
			(*nb_block4)--;
			printf("\n%s: Reste %i piece bloquante a joue.", pseudo4, *nb_block4);
		}

		//Placement du pion sur la grille si et seulement si la colonne le permet
		test = 0;
		ligne = choix_ligne_avance(grille, colonne);
		if(ligne < 0){
			if(grille[ligne+1][colonne-1].type1 == bloquante || type == bloquante || grille[ligne+1][colonne-1].type1 == type || grille[ligne+1][colonne-1].valeur_pion2 != 0){
				printf("Erreur: colonne pleine veuillez en choisir une autre: ");
				test = 1;
			}
			else if(grille[ligne+1][colonne-1].type1 != type && grille[ligne+1][colonne-1].valeur_pion2 == 0)
				placer_pions_avance(grille, colonne, ligne, num_joueur, type);
		}
		else
			placer_pions_avance(grille, colonne, ligne, num_joueur, type);

	}while(test == 1);
		
	//Affichage du numéro du tour
	system("clear");
	printf("\n+---------------------------------------+");
	printf("\n|	       TOUR NUMERO %i		|",pions);

	//Mise à jour de la grille
	afficher_matrice_avance(grille);
	couleur("0");
}

/**

*\fn void enregistrement_score_avance(char joueur[L], int nb_coups)
*\brief Enregistrement du score du gagnant pour le Puissance 4++

*/
void enregistrement_score_avance(char joueur[L], int nb_coups){
	FILE * fichier;

	fichier = fopen("best_avance.txt", "a");
	fprintf(fichier, "\n%s	%i", joueur, nb_coups);
	fclose(fichier);
}

/**

*\fn void affich_result_avance(t_piece grille[N][M], int win, int tour, char pseudo1[L], char pseudo2[L], char pseudo3[L], char pseudo4[L])
*\brief Affichage du vainqueur ou du match nul de la partie du Puissance 4++

*/
void affich_result_avance(t_piece grille[N][M], int win, int tour, char pseudo1[L], char pseudo2[L], char pseudo3[L], char pseudo4[L]){
	system("clear");
	

	if(win == 0){
		printf("\n+---------------------------------------+");
		printf("\n|	         MATCH NUL		|");
	
		afficher_matrice_avance(grille);
	}
	
	else if(win == 1){
		printf("\n+---------------------------------------+");
		printf("\n|	        %s A GAGNE 		|", pseudo1);
		
		afficher_matrice_avance(grille);

		//Enregistrement du score du joueur
		enregistrement_score_avance(pseudo1, tour);
		
		//On supprime la partie enregistree car on a fini la partie en cours
		remove ("partie_avance.txt");
	}

	else if(win == 2){
		printf("\n+---------------------------------------+");
		printf("\n|	        %s A GAGNE 		|", pseudo2);
		
		afficher_matrice_avance(grille);

		//Enregistrement du score du joueur
		enregistrement_score_avance(pseudo2, tour);
		
		//On supprime la partie enregistree car on a fini la partie en cours
		remove ("partie_avance.txt");
	}
	else if(win == 3){
		printf("\n+---------------------------------------+");
		printf("\n|	        %s A GAGNE 		|", pseudo3);
		
		afficher_matrice_avance(grille);

		//Enregistrement du score du joueur
		enregistrement_score_avance(pseudo3, tour);
		
		//On supprime la partie enregistree car on a fini la partie en cours
		remove ("partie_avance.txt");
	}	
	else if(win == 4){
		printf("\n+---------------------------------------+");
		printf("\n|	        %s A GAGNE 		|", pseudo4);
		
		afficher_matrice_avance(grille);

		//Enregistrement du score du joueur
		enregistrement_score_avance(pseudo4, tour);
		
		//On supprime la partie enregistree car on a fini la partie en cours
		remove ("partie_avance.txt");
	}
}

/**
*\fn void puissance_avance()
*\brief Construction du Puissance 4++

*/
void puissance_avance(){
	t_piece grille[N][M];
	int colonne, ligne, pions, num_joueur, tour, nb_joueurs, type, win, nb_block1, nb_block2, nb_block3, nb_block4, test, menutest, quit, party ,debut;
	char joueur1[L],joueur2[L],joueur3[L],joueur4[L];

/****************************** INITIALISATION ****************************************/
	menutest = 0;
	party = 0;
	debut = 0;
	
	//Demande aux joueurs si ils veulent reprendre une partie en cours ou non
	debut = begin();
	if(debut != 3){
		if(debut == 2){
			//Recuperation de la partie
			party = load_avance(grille, &tour, joueur1, joueur2, joueur3, joueur4, &nb_joueurs, &nb_block1, &nb_block2, &nb_block3, &nb_block4);
			//Si on a bien recupere la partie on met a jour tour
			if(party == 0)	
				pions = tour;
		}

		//Si le joueur commence une nouvelle partie ou si il n'y avais pas de partie a restaurer on demande le nombre de joueur
		if(debut == 1 || (debut == 2 && party == 1)){
			nb_joueurs = nb_joueur(party, debut) ;
			if(nb_joueurs == 1){
				menu();
				menutest = 1;
			}
		}

		//Si le joueur ne voulais pas retourner au menu on peut jouer
		if(menutest != 1){

			//Si le joueur commence une nouvelle partie ou si il n'y avais pas de partie a restaurer on fais toutes les initialisations de bases
			if(debut == 1 || (debut == 2 && party == 1)){
				//Initialisation des pseudos
				pseudo_avance(joueur1, joueur2, joueur3, joueur4, nb_joueurs);

				//Affichage des regles
				afficher_regles();
			
				//Initialisation de la matrice et effaçage de l'écran pour afficher la grille vierge
				init_matrice_avance(grille);

				pions = 1;
				tour = 1;
				nb_block1 = 2;
				nb_block2 = 2;
				nb_block3 = 2 ; 
				nb_block4 = 2 ;
			}
		
			system("clear");
			printf("\n+---------------------------------------+");
			printf("\n|	       TOUR NUMERO %i		|", pions);
			afficher_matrice_avance(grille);

			win = 0;
			quit = 0;

/****************************** 2 JOUEURS ********************************************/

			if(nb_joueurs == 2){
				while(!grille_pleine(grille)){

/****************************** joueur 1 joue *****************************************/

					//Joueur 1 joue
					if(player1(grille, &nb_block1, pions, joueur1, joueur2, joueur3, joueur4, nb_joueurs, tour, nb_block2, nb_block3, nb_block4) == 10){
						quit = 1;
						break;
					};

					//Test pour savoir si le joueur à gagné
					win = gagne_avance(grille);
					if(win == 1)break;

/****************************** joueur 2 joue *****************************************/
					pions ++;

					//Joueur 2 joue
					player2(grille, &nb_block2, pions, joueur2);

					//Test pour savoir si le joueur à gagné
					win = gagne_avance(grille);
					if(win == 2)break;

					tour++;
				}
			}

/****************************** 3 JOUEURS ********************************************/

			else if(nb_joueurs == 3){
				while(!grille_pleine(grille)){

/****************************** joueur 1 joue *****************************************/

					//Joueur 1 joue
					if(player1(grille, &nb_block1, pions, joueur1, joueur2, joueur3, joueur4, nb_joueurs, tour, nb_block2, nb_block3, nb_block4) == 10){
						quit = 1;
						break;
					};

					//Test pour savoir si le joueur à gagné
					win = gagne_avance(grille);
					if(win == 1)break;

/****************************** joueur 2 joue *****************************************/

					//Joueur 2 joue
					player2(grille, &nb_block2, pions, joueur2);

					//Test pour savoir si le joueur à gagné
					win = gagne_avance(grille);
					if(win == 2)break;

/****************************** joueur 3 joue *****************************************/
					pions ++;
				
					//Joueur 3 joue
					player3(grille, &nb_block3, pions, joueur3);

					//Test pour savoir si le joueur à gagné
					win = gagne_avance(grille);
					if(win == 3)break;

					tour++;
				}
			}

/****************************** 4 JOUEURS ********************************************/

			else if(nb_joueurs == 4){
				while(!grille_pleine(grille)){

/****************************** joueur 1 joue *****************************************/

					//Joueur 1 joue
					if(player1(grille, &nb_block1, pions, joueur1, joueur2, joueur3, joueur4, nb_joueurs, tour, nb_block2, nb_block3, nb_block4) == 10){
						quit = 1;
						break;
					};

					//Test pour savoir si le joueur à gagné
					win = gagne_avance(grille);
					if(win == 1)break;

/****************************** joueur 2 joue *****************************************/

					//Joueur 2 joue
					player2(grille, &nb_block2, pions, joueur2);

					//Test pour savoir si le joueur à gagné
					win = gagne_avance(grille);
					if(win == 2)break;

/****************************** joueur 3 joue *****************************************/

					//Joueur 3 joue
					player3(grille, &nb_block3, pions, joueur3);

					//Test pour savoir si le joueur à gagné
					win = gagne_avance(grille);
					if(win == 3)break;

/****************************** joueur 4 joue *****************************************/

					pions ++;
				
					//Joueur 4 joue
					player4(grille, &nb_block3, pions, joueur4);

					//Test pour savoir si le joueur à gagné
					win = gagne_avance(grille);
					if(win == 4)break;

					tour++;
				}
			}

/******************** Affichage du résultat de la partie ******************************/

			if(quit == 0){
				affich_result_avance(grille, win, tour, joueur1, joueur2, joueur3, joueur4);
				affich_score_avance();
			}
		}
/***************** Menu de fin de Jeu *****************/
		fin_jeux_avance();
	}
	if(debut == 3)
		menu();
}
