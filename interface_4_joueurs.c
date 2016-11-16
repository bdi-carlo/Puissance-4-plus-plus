#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "new_fonctions.h"

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
		{	case 1: puissance_classique(); break;
			case 2: /*puissance_avance();*/ break;
			case 3: return 1;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 3\n");
		}

	return 0;
}

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



void resultat(){
	system("clear");

	if(gagne(grille) == 0)printf("\nMATCH NUL\n\n");

	else if(gagne(grille) == 1){
		printf("\n%s GAGNE\n\n",joueur1);

		//Enregistre le score du joueur 1
		enregistrement_score_classique(joueur1, pions);
	}

	else if(gagne(grille) == 2){
		printf("\n%s GAGNE\n\n",joueur2);

		//Enregistre le score du joueur 2
		enregistrement_score_classique(joueur2, pions);
	}
	else if(gagne(grille) == 3){
		printf("\n%s GAGNE\n\n",joueur3);

		//Enregistre le score du joueur 3
		enregistrement_score_classique(joueur3, pions);
	}
	else if(gagne(grille) == 4){
		printf("\n%s GAGNE\n\n",joueur4);

		//Enregistre le score du joueur 4
		enregistrement_score_classique(joueur4, pions);
	}
}