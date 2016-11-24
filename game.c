#include <stdio.h>
#include <stdlib.h>
#include "new_fonctions.h"

int main(){

	int choix = menu();
	int choix2;

	if(choix != 3){
		while(choix2 != 3){
<<<<<<< HEAD
			if(choix == 1)
				choix2 = fin_jeux();
		
			else if(choix == 2)
				choix2 = fin_jeux_avance();
		 }
=======
		if(choix == 1)
			choix2 = fin_jeux();
		}
>>>>>>> f629ae424dccd42bbe86405465e0d2b50138b592
	}

	printf("\nAu revoir !\n");
}