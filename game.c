#include <stdio.h>
#include <stdlib.h>

int main(){
	menu();

	while(fin_jeux() != 1)
		fin_jeux();

	printf("\nAu revoir !\n");
}
