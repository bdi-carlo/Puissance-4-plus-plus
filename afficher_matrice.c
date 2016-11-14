#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 6
#define M 7

void afficher_matrice(int matrice[N][M]){
	int i,j;

	printf("\n");
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			if(matrice[i][j] == 0)printf(" . ");
			if(matrice[i][j] == 1)printf(" x ");
			if(matrice[i][j] == 2)printf(" o ");
		}
		printf("\n");
	}
	printf("\n 1  2  3  4  5  6  7\n");
	printf("\n");
}
