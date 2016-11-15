#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define L 20

void pseudo_classique(char pseudo1[L], char pseudo2[L]){
	system("clear");
	printf("\nVeuillez choisir vos pseudos :\n");
	
	printf("\nJoueur 1 (pions rouges) : ");
	scanf("%s", pseudo1);

	printf("\nJoueur 2 (pions jaunes) : ");
	scanf("%s", pseudo2);
}
