#include <stdio.h>
#include <stdlib.h>
#include "new_fonctions.h"

int main(){

	int choix = menu();

	if(choix != 3){
		if(choix == 1)
			fin_jeux();
		if(choix == 2)
			fin_jeux_avance(); 
	}

	printf("\nAu revoir !\n");
}
