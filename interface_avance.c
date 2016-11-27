#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "new_fonctions.h"

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
	printf("\n|	    PUISSANCE 4++       |");
	printf("\n|	   Retour Menu (1)      |");
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
