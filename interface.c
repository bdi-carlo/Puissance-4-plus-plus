#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "new_fonctions.h"

//Menu de debut de jeu
int menu(){
	int choix;

	
		system("clear");

		printf("\nMenu :\n");
		printf(" 1 - Puissance 4 classique\n");
		printf(" 2 - Puissance 4 ++\n");
		printf(" 3 - Quitter\n");
		printf("Votre choix : ");
		scanf("%d",&choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix)
		{	case 1: puissance_classique(); return choix;
			case 2: puissance_avance(); return choix;
			case 3: return choix;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 3\n");
		}

	return 0;
}

//Menu de fin de jeu
void fin_jeux(){
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
		{	case 1: puissance_classique(); break;
			case 2: menu(); break;
			case 3: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 3\n");
		}
	}while(choix != 3);
}

//Demande aux joueurs leur pseudo
void pseudo_classique(char pseudo1[L], char pseudo2[L]){
	system("clear");
	printf("\nVeuillez choisir vos pseudos :\n");
	
	printf("\nJoueur 1 (pions rouges) : ");
	scanf("%s", pseudo1);

	printf("\nJoueur 2 (pions bleus) : ");
	scanf("%s", pseudo2);
}
