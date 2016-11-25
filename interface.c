#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "new_fonctions.h"

#define couleur(param) printf("\033[%sm",param)

//Menu de debut de jeu
int menu(){
	int choix;

	system("clear");

	printf("\n ------------------------------- ");
	printf("\n|	        Menu            |");
	printf("\n|				|");
	printf("\n|  1 - Puissance 4 classique	|");
	printf("\n|  2 - Puissance 4 ++		|");
	printf("\n|  3 - Quitter			|");
	printf("\n|				|");
	printf("\n ------------------------------- ");
	
	do{
		printf("\n>> Votre choix : ");
		scanf("%d",&choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix)
		{	case 1: puissance_classique(); return choix;
			case 2: puissance_avance(); return choix;
			case 3: printf("\n Au revoir !\n"); break;
			default: printf("\nErreur: votre choix doit etre compris entre 1 et 3\n");
			}
	}while(choix < 1 || choix > 3);

	return 0;
}

//Menu de fin de jeu
int fin_jeux(){
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
		{	case 1: puissance_classique(); return choix;;
			case 2: menu(); return choix;;
			case 3: printf("\n Au revoir !\n"); break ;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 3\n");
		}
	}while(choix < 1 || choix > 3);
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
