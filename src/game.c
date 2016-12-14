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
	
	menu();
	printf("\nAu revoir !\n");
	
	couleur("0");
}
