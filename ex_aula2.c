#include <stdio.h>
#include <stdlib.h>
#include "reader.h"

void main() {
	int n,k;
	int *vetor;

	printf("Diga o número de elementos: ");
	scanf("%d", &n);

	vetor = vet_preenche(n);

	for(k=0; k<n; k++) {
		printf("Preencha o vetor %d: ",k);
		scanf("%d", &vetor[k]);
	}

	imprime(vetor,n);

	limpa(vetor);

}