// func
#include <stdio.h>
#include <stdlib.h>
#include "reader.h"


void preenche_vet(int *vet, int n) {


		int k;

	for(k=0; k<n; k++) {
		printf("Diga o elemento %d: ", k+1);
		scanf("%d", &vet[k]);
	}
}

int *vet_preenche(int n) {
	int *vet;

	vet = (int*) malloc (n*sizeof(int));

	return vet;
}

void imprime(int *vetor,int n) {
	int k;
	for(k=0; k<n; k++) {
		printf("Vetor %d = %d", k, vetor[k]);
	}

}

void limpa(int *vetor) {
	free(vetor);
}

int **preenche_matriz(int l,int c) {
	int **m,k;

	m = (int **) malloc (l*sizeof(int*));

	for(k=0; k<l; k++) {
		m[k] = (int *) malloc (c*sizeof(int*));
	}

	return m;

}

