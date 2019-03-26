#include <stdio.h>
#include <stdlib.h>
#include "reader.h"

void main() {
	int **matriz,**matriz_2;
	int linhas,colunas,k,t,j;

	printf("Diga o número de linhas/colunas: ");
	scanf("%d", &linhas);
	scanf("%d", &colunas);

	matriz = (int **) malloc (linhas*sizeof(int*));

	for(k=0; k<linhas; k++) {
		matriz[k] = (int*) malloc (colunas*sizeof(int*));
	}
	
	printf("\t\t\nMatriz 1\n\n");

	for(t=0; t<linhas; t++) {
		for(j=0; j<colunas; j++) {
			matriz[t][j] = rand () % 10;
			printf("Matriz[%d][%d] = %d\n",t,j,matriz[t][j]);
		}
		printf("\n");
	}

	matriz_2 = preenche_matriz(linhas,colunas);

	printf("\n\t\tMatriz 2\n\n");

	for(t=0; t<linhas; t++) {
		for(j=0; j<colunas; j++) {
			matriz_2[t][j] = rand () % 10;
			printf("Matriz[%d][%d] = %d\n",t,j,matriz_2[t][j]);
		}
		printf("\n");
	}

	free(matriz);
	free(matriz_2);


}