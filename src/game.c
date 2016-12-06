#include <stdio.h>
#include <stdlib.h>
#include "../include/classique.h"
#include "../include/avance.h"

#define couleur(param) printf("\033[%sm",param)

/**
*\file game.c
*\brief Programme principal

*\author Benjamin, Julien, Arthur
*\version 1.0
*\date Novembre 2016
*/


/**
*\fn int main()
*\brief Programme principal
*/

int main(){
	couleur("0");
	int choix = menu();
	int choix2;

	if(choix != 3){
		while(choix2 != 3){
			if(choix == 1)
				choix2 = fin_jeux();

			else if(choix == 2)
				choix2 = fin_jeux_avance();
		 }
	}

	printf("\nAu revoir !\n");
	couleur("0");
}
