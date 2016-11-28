#include <stdio.h>
#include <stdlib.h>
#include "new_fonctions.h"

int main(){

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
}
