#include <stdio.h>
#include <stdlib.h>
#include "puissance_classique.h"
#include "puissance_avance.h"

void choix_jeux(){
	int choix;

	printf("\nChoix du jeu :\n");
	printf(" 1 - Puissance 4 classique\n");
	printf(" 2 - Puissance 4 ++\n");
	printf(" 3 - Quitter\n");
	printf("Votre choix : ");
	scanf("%d",&choix);

	/* Traitement du choix de l'utilisateur */
	switch(choix)
	{	case 1: puissance_classique(); break;
		case 2: puissance_avance(); break;
		case 3: break;
		default: printf("Erreur: votre choix doit etre compris entre 1 et 3\n");
	}
}

int main(){
	choix_jeux();	
	printf("Au revoir !\n");
}
