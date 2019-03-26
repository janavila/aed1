#include <stdio.h>
#include <stdlib.h>
#include "reader.h"


void main(){
// Exercicio 1

	int n,k;
	int *vet;

	printf("Diga a quantidade de elementos que você deseja criar: ");
	scanf("%d", &n);

	vet = (int*) malloc (n*sizeof(int));

	preenche_vet(vet,n);

	for(k=0; k<n; k++) {
		printf("Vet [%d] = %d\n", (k+1),vet[k]);
	}

	free(vet);
	
///////////////*/


	

}

