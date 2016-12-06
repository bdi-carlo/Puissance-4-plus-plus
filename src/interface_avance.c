#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/classique.h"
#include "../include/avance.h"

#define couleur(param) printf("\033[%sm",param)
#define T 100

/**
*\file interface_avance.c
*\brief Interface du Puissance 4

*\author Benjamin, Julien, Arthur
*\version 1.0
*\date Novembre 2016
*/

/**
*\fn int fin_jeux_avance()
*\brief Menu pour la fin de la partie

*\fn int nb_joueur()
*\brief Choix du nombre de joueurs

*\fn void pseudo_avance(char pseudo1[L], char pseudo2[L], char pseudo3[L], char pseudo4[L], int nb_joueurs)
*\brief Choix des pseudos

*\fn void afficher_regles()
*\brief Affiche les règles du Puissance 4++
*/

void affich_score_avance(){
	int i, j, taille;
	t_score temp;
	
	FILE * fichier;
	t_score tab[T];

	fichier = fopen("best_avance.txt", "r");

	//Met tout les scores dans un tableau
	i = 0;
	do{
		fscanf(fichier, "%s", &tab[i].pseudo);
		fscanf(fichier, "%i", &tab[i].score);
		i++;
	}while(!feof(fichier));
	taille = i;

	//Tri du tableau dans l'ordre croissant des scores pour avoir les meilleurs scores
	for(i = 0; i < taille; i++){							//Parcours complet de la sequence a trier
		
		for(j = taille-1; j > i; j--){						//Parcours de la sequence non triee
			
			if(tab[j-1].score > tab[j].score){				
				temp = tab[j];
				tab[j] = tab[j-1];				//Permute tab[j] et tab[j-1]
				tab[j-1] = temp;
			}
		}
	}

	fclose(fichier);

	//Affichage des 5 meilleurs scores
	printf("	  Records   	");
	printf("\n");
	for(i = 0; i < 5 && i < taille; i++){
		printf("\n	  %i - %s  :  %i", i+1, tab[i].pseudo, tab[i].score);
	}
	printf("\n");
}

int fin_jeux_avance(){
	int choix;

	printf("\n+-------------------------------+ ");
	printf("\n|	        FIN             |");
	printf("\n|				|");
	printf("\n| 	 1 - Rejouer		|");
	printf("\n|  	 2 - Retour au menu	|");
	printf("\n|  	 3 - Quitter		|");
	printf("\n|				|");
	printf("\n+-------------------------------+ ");

	do{		
		printf("\n>> Votre choix : ");
		scanf("%d",&choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix)
		{	case 1: puissance_avance(); return choix;
			case 2: menu(); return choix;
			case 3: return choix;
			default: printf("\nErreur: votre choix doit etre compris entre 1 et 3\n");
		}
	}while(choix < 1 || choix > 3);
}

int nb_joueur(){
	int choix;

	printf("\n+-------------------------------+ ");
	printf("\n|	  PUISSANCE 4 avance    |");
	printf("\n|	    Retour Menu (1)     |");
	printf("\n|				|");
	printf("\n|	  Nombre de joueurs:    |");
	printf("\n| 	      2 joueurs		|");
	printf("\n|  	      3 joueurs		|");
	printf("\n|  	      4 joueurs		|");
	printf("\n|				|");
	printf("\n+-------------------------------+ ");

	do{
		printf("\n>>Votre choix : ");
		scanf("%d",&choix);
	}while(choix < 1 || choix > 4);

	return choix;
}

void pseudo_avance(char pseudo1[L], char pseudo2[L], char pseudo3[L], char pseudo4[L], int nb_joueurs){
	system("clear");

	printf("\nVeuillez choisir vos pseudos sachant qu'ils ne doivent pas depasser 5 caracteres \n \n");
	
	do{
		couleur("31");
		printf("\nJoueur 1: ");
		scanf("%s", pseudo1);
		couleur("0");
		if(strlen(pseudo1) > 5)
			printf("Erreur: votre pseudo ne doit pas depasser 5 caracteres");
	}while(strlen(pseudo1) > 5);
	couleur("0");

	do{
		couleur("34");
		printf("\nJoueur 2: ");
		scanf("%s", pseudo2);
		couleur("0");
		if(strlen(pseudo2) > 5)
			printf("Erreur: votre pseudo ne doit pas depasser 5 caracteres");
	}while(strlen(pseudo2) > 5);

	if(nb_joueurs ==  3 || nb_joueurs == 4){
		do{
			couleur("33");
			printf("\nJoueur 3: ");
			scanf("%s", pseudo3);
			couleur("0");
			if(strlen(pseudo3) > 5)
				printf("Erreur: votre pseudo ne doit pas depasser 5 caracteres");
		}while(strlen(pseudo3) > 5);
	}

	if(nb_joueurs == 4){
		do{
			couleur("32");
			printf("\nJoueur 4: ");
			scanf("%s", pseudo4);
			couleur("0");
			if(strlen(pseudo4) > 5)
				printf("Erreur: votre pseudo ne doit pas depasser 5 caracteres");
		}while(strlen(pseudo4) > 5);
	}
	couleur("0");
}

void afficher_regles(){
	int regles;
	do{
		system("clear");
		printf("\n+--------------------------------------------------------------------------------------------------------------+");
		printf("\n|													       |");
		printf("\n|						 Regles du jeu  					       |");
		printf("\n|													       |");
		printf("\n|	- Pour gagner la partie il suffit d'aligner 4 pions de sa couleur				       |");
		printf("\n|	- Le joueur a à sa disposition 3 types de pièces : Bloquantes, Creuses et Pleines		       |");
		printf("\n|		* Une pièce creuse peut passer au dessus d’une pièce pleine (ou s’arrêter dessus)	       |");
		printf("\n|		* Une pièce pleine peut passer au travers d’une pièce creuse (ou s’arrêter dessus)	       |");
		printf("\n|		* Deux pièces de même type ne peuvent pas se traverser					       |");
		printf("\n|		* Une pièce bloquante ne peut être traversée ni par une pièce creuse ni par une pièce pleine.  |");
		printf("\n|		* Les joueurs n’ont droit qu’à 2 pièces bloquantes durant une partie.			       |");
		printf("\n|													       |");
		printf("\n+--------------------------------------------------------------------------------------------------------------+");
		printf("\n \n				    Tapez 1 pour passer au jeu : ");
		scanf("%i",&regles);
	}while(regles != 1);
}
