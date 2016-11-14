#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 6
#define M 7

void init_matrice(int matrice[N][M]){
	int i,j;

	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			matrice[i][j] = 0;
		}
	}
}
