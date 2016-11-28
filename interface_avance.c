#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "new_fonctions.h"

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
*\brief Demande aux joueurs leur pseudo


*/

int fin_jeux_avance(){
	int choix;

	printf("\n ------------------------------- ");
	printf("\n|	        FIN             |");
	printf("\n|				|");
	printf("\n| 	 1 - Rejouer		|");
	printf("\n|  	 2 - Retour au menu	|");
	printf("\n|  	 3 - Quitter		|");
	printf("\n|				|");
	printf("\n ------------------------------- ");

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

	printf("\n ------------------------------- ");
	printf("\n|	  PUISSANCE 4 avance    |");
	printf("\n|	    Retour Menu (1)     |");
	printf("\n|				|");
	printf("\n|	  Nombre de joueurs:    |");
	printf("\n| 	      2 joueurs		|");
	printf("\n|  	      3 joueurs		|");
	printf("\n|  	      4 joueurs		|");
	printf("\n|				|");
	printf("\n ------------------------------- ");

	do{
		printf("\n>>Votre choix : ");
		scanf("%d",&choix);
	}while(choix < 1 || choix > 4);

	return choix;
}

void pseudo_avance(char pseudo1[L], char pseudo2[L], char pseudo3[L], char pseudo4[L], int nb_joueurs){
	system("clear");
	printf("\nVeuillez choisir vos pseudos :\n");
	
	printf("\nJoueur 1 (pions rouges) : ");
	scanf("%s", pseudo1);

	printf("\nJoueur 2 (pions bleus) : ");
	scanf("%s", pseudo2);

	if(nb_joueurs ==  3 || nb_joueurs == 4){
		printf("\nJoueur 3 (pions magentas) : ");
		scanf("%s", pseudo3);
	}

	if(nb_joueurs == 4){
		printf("\nJoueur 4 (pions verts) : ");
		scanf("%s", pseudo4);
	}
}

//Fonction affichant les regles
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
