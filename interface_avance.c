#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "new_fonctions.h"

//Menu de fin de jeu
void fin_jeux_avance(){
	int choix;

	do{
		printf("\nFIN :\n");
		printf(" 1 - Rejouer\n");
		printf(" 2 - Retour au menu\n");
		printf(" 3 - Quitter\n");
		printf("Votre choix : ");
		scanf("%d",&choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix)
		{	case 1: puissance_avance(); break;
			case 2: menu(); break;
			case 3: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 3\n");
		}
	}while(choix != 3);
}

int nb_joueur(){
	int choix;

	printf("\nNombre de joueurs :\n");
	printf(" 1 - 2 joueurs\n");
	printf(" 2 - 3 joueurs\n");
	printf(" 3 - 4 joueurs\n");
	printf("Votre choix : ");
	scanf("%d",&choix);

	return choix+1;
}

//Demande aux joueurs leur pseudo
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
