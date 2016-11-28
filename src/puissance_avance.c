#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/new_fonctions.h"

#define N 6
#define M 7
#define L 20

/**

*\file puissance_classique.c
*\brief Puissance 4 classique
*\author Benjamin, Julien, Arthur
*\version 1.0
*\date Novembre 2016

*/

/**


*\fn save_score_avance(char joueur[L], int nb_coups)
*\brief Enregistrement du score du gagnant

*\fn affich_result_avance(int grille[N][M], char joueur1[L], char joueur2[L], char joueur3[L], char joueur4[L], int tour)
*\brief Affichage du resultat de la partie

*\fn puissance_avance()
*\brief Programme permettant la construction du jeu Puissance 4 classique à 2, 3 ou 4 joueurs


*/

void player1(t_piece grille[N][M], int *nb_block1, int pions, char pseudo1[L]){
	int num_joueur, ligne, colonne, type, test;

	num_joueur = 1;

	//Demande où il veut jouer et avec quel type de piece
	do{			
		printf("%s: Colonne: ",pseudo1);
		scanf("%i", &colonne);

		do{
			printf("Type: - Creuse (1) ");
			printf("\n      - Pleine (2) ");
			printf("\n      - Bloquante (3) ");
			printf("\n\n>> Choix : ");
			scanf("%i", &type);
				
			//Verification du nombre de piece bloquante
			if(type == 3 && *nb_block1 == 0)
					printf("\nJoueur 1 n'a plus de piece bloquante.\n");
			
		}while(type < 1 || type > 3 || (type == 3 && *nb_block1 == 0));
			
		//Verification du nombre de piece bloquante et decrementation si on en a joue une
		if(type == 3 && *nb_block1 > 0){
			(*nb_block1)--;
			printf("\nJoueur 1: Reste %i piece bloquante a joue.",*nb_block1);
		}
			
		if(colonne < 1 || colonne > 7)
			printf("Erreur: entrez une colonne entre 1 et 7 compris: ");
			
		else{
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
		}
	}while(colonne < 1 || colonne > 7 || test == 1);
		
	//Affichage du numéro du tour
	system("clear");
	printf("\n ---------------------------------------");
	printf("\n|	       TOUR NUMERO %i		|",pions);

	//Mise à jour de la grille
	afficher_matrice_avance(grille);
}

void player2(t_piece grille[N][M], int *nb_block2, int pions, char pseudo2[L]){
	int num_joueur, ligne, colonne, type, test;

	num_joueur = 2;

	//Demande où il veut jouer et avec quel type de piece
	do{			
		printf("%s: Colonne: ",pseudo2);
		scanf("%i", &colonne);

		do{
			printf("Type: - Creuse (1) ");
			printf("\n      - Pleine (2) ");
			printf("\n      - Bloquante (3) ");
			printf("\n\n>> Choix : ");
			scanf("%i", &type);
				
			//Verification du nombre de piece bloquante
			if(type == 3 && *nb_block2 == 0)
					printf("\nJoueur 2 n'a plus de piece bloquante.\n");
				
		}while(type < 1 || type > 3 || (type == 3 && *nb_block2 == 0));
			
		//Verification du nombre de piece bloquante et decrementation si on en a joue une
		if(type == 3 && *nb_block2 > 0){
			(*nb_block2)--;
			printf("\nJoueur 2: Reste %i piece bloquante a joue.",*nb_block2);
		}
			
		if(colonne < 1 || colonne > 7)
			printf("Erreur: entrez une colonne entre 1 et 7 compris: ");
			
		else{
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
		}
	}while(colonne < 1 || colonne > 7 || test == 1);
		
	//Affichage du numéro du tour
	system("clear");
	printf("\n ---------------------------------------");
	printf("\n|	       TOUR NUMERO %i		|",pions);

	//Mise à jour de la grille
	afficher_matrice_avance(grille);
}

void player3(t_piece grille[N][M], int *nb_block3, int pions, char pseudo3[L]){
	int num_joueur, ligne, colonne, type, test;

	num_joueur = 3;

	//Demande où il veut jouer et avec quel type de piece
	do{			
		printf("%s: Colonne: ",pseudo3);
		scanf("%i", &colonne);

		do{
			printf("Type: - Creuse (1) ");
			printf("\n      - Pleine (2) ");
			printf("\n      - Bloquante (3) ");
			printf("\n\n>> Choix : ");
			scanf("%i", &type);
				
			//Verification du nombre de piece bloquante
			if(type == 3 && *nb_block3 == 0)
					printf("\nJoueur 3 n'a plus de piece bloquante.\n");
				
		}while(type < 1 || type > 3 || (type == 3 && *nb_block3 == 0));
			
		//Verification du nombre de piece bloquante et decrementation si on en a joue une
		if(type == 3 && *nb_block3 > 0){
			(*nb_block3)--;
			printf("\nJoueur 3: Reste %i piece bloquante a joue.",*nb_block3);
		}
			
		if(colonne < 1 || colonne > 7)
			printf("Erreur: entrez une colonne entre 1 et 7 compris: ");
			
		else{
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
		}
	}while(colonne < 1 || colonne > 7 || test == 1);
		
	//Affichage du numéro du tour
	system("clear");
	printf("\n ---------------------------------------");
	printf("\n|	       TOUR NUMERO %i		|",pions);

	//Mise à jour de la grille
	afficher_matrice_avance(grille);
}

void player4(t_piece grille[N][M], int *nb_block4, int pions, char pseudo4[L]){
	int num_joueur, ligne, colonne, type, test;

	num_joueur = 4;

	//Demande où il veut jouer et avec quel type de piece
	do{			
		printf("%s: Colonne: ",pseudo4);
		scanf("%i", &colonne);

		do{
			printf("Type: - Creuse (1) ");
			printf("\n      - Pleine (2) ");
			printf("\n      - Bloquante (3) ");
			printf("\n\n>> Choix : ");
			scanf("%i", &type);
				
			//Verification du nombre de piece bloquante
			if(type == 3 && *nb_block4 == 0)
					printf("\nJoueur 4 n'a plus de piece bloquante.\n");
				
		}while(type < 1 || type > 3 || (type == 3 && *nb_block4 == 0));
			
		//Verification du nombre de piece bloquante et decrementation si on en a joue une
		if(type == 3 && *nb_block4 > 0){
			(*nb_block4)--;
			printf("\nJoueur 4: Reste %i piece bloquante a joue.",*nb_block4);
		}
			
		if(colonne < 1 || colonne > 7)
			printf("Erreur: entrez une colonne entre 1 et 7 compris: ");
			
		else{
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
		}
	}while(colonne < 1 || colonne > 7 || test == 1);
		
	//Affichage du numéro du tour
	system("clear");
	printf("\n ---------------------------------------");
	printf("\n|	       TOUR NUMERO %i		|",pions);

	//Mise à jour de la grille
	afficher_matrice_avance(grille);
}

//Fonction qui permet d'afficher le resultat de la partie
void affich_result_avance(t_piece grille[N][M], int win, int tour, char pseudo1[L], char pseudo2[L], char pseudo3[L], char pseudo4[L]){
	system("clear");
	

	if(win == 0){
		printf("\n ---------------------------------------");
		printf("\n|	         MATCH NUL		|");
	
		afficher_matrice_avance(grille);
	}
	
	else if(win == 1){
		printf("\n ---------------------------------------");
		printf("\n|	        %s A GAGNE 		|",pseudo1);
		
		afficher_matrice_avance(grille);
	}

	else if(win == 2){
		printf("\n ---------------------------------------");
		printf("\n|	        %s A GAGNE 		|",pseudo2);
		
		afficher_matrice_avance(grille);
	}
	else if(win == 3){
		printf("\n ---------------------------------------",pseudo3);
		printf("\n|	        %s A GAGNE 		|");
		
		afficher_matrice_avance(grille);
	}	
	else if(win == 4){
		printf("\n ---------------------------------------");
		printf("\n|	        %s A GAGNE 		|",pseudo4);
		
		afficher_matrice_avance(grille);
	}
}

//Programme permettant la construction du jeu Puissance 4 classique
void puissance_avance(){
	t_piece grille[N][M];
	int colonne, ligne, pions, num_joueur, tour, nb_joueurs, type, win, nb_block1, nb_block2, nb_block3, nb_block4, test;
	char joueur1[L],joueur2[L],joueur3[L],joueur4[L];

/****************************** INITIALISATION ****************************************/

	nb_joueurs = nb_joueur() ;
	if(nb_joueurs == 1)
		menu() ;
	else {

		pseudo_avance(joueur1, joueur2, joueur3, joueur4, nb_joueurs) ;
		afficher_regles();
		//Initialisation de la matrice et effaçage de l'écran pour afficher la grille vierge
		init_matrice_avance(grille);
		system("clear");
		printf("\n ---------------------------------------");
		printf("\n|	       TOUR NUMERO 1		|");
		afficher_matrice_avance(grille);

		win = 0;
		pions = 1;
		tour = 1;
		nb_block1 = 2;
		nb_block2 = 2;
		nb_block3 = 2 ; 
		nb_block4 = 2 ;

/****************************** 2 JOUEURS ********************************************/

		if(nb_joueurs == 2){
			while(!grille_pleine(grille)){

/****************************** joueur 1 joue *****************************************/

				//Joueur 1 joue
				player1(grille, &nb_block1, pions, joueur1);

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
				player1(grille, &nb_block1, pions,joueur1);

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
				player1(grille, &nb_block1, pions, joueur1);

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

		affich_result_avance(grille, win, tour, joueur1, joueur2, joueur3, joueur4);
	}
}
