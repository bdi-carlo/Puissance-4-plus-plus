#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 6
#define M 7

int placer_pions(int matrice[N][M], int colonne, int num_joueur){
	int i;
	int ligne = N-1;

	colonne--;
	
	for(i = 1; i <= N; i++){
		if(matrice[N-i][colonne] == 1 || matrice[N-i][colonne] == 2)ligne--;
	}

	if(num_joueur == 1)
		matrice[ligne][colonne] = 1;
	else if(num_joueur == 2)
		matrice[ligne][colonne] = 2;
}
