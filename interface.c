#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int menu(){
	int choix;

	do{
		system("clear");

		printf("\nChoix du jeu :\n");
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
	}while(choix != 3);
	return 0;
}

int fin_jeux(){
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
			case 3: return 1;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 3\n");
		}
	}while(choix != 3);
}
