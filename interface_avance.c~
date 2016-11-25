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
