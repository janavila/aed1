#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* valores_entre(int *v, int n, int min, int max, int *qtd) {
	int *vet_temp,k,max_pos,min_pos,maior,menor,aux,*vet_new;
	int t;

	//vet_temp = (int *) malloc (n*sizeof(int));
	
	vet_temp = v;
	for(k=0; k<n; ++k) {
		if(vet_temp[k] == max) max_pos = k;
		if(vet_temp[k] == min) min_pos = k; 
	}

	printf("Posicao do Maximo: %d\n", max_pos);
	printf("Posicao do Minimo: %d\n", min_pos);

	if(max_pos > min_pos) { 
		maior = max_pos;
		menor = min_pos;
}
	else {
		menor = max_pos;
		maior = min_pos;
	}
	aux = maior - menor;

	vet_new = (int *) malloc (aux*sizeof(int));

	for(t= menor; t<maior; ++t) {

		vet_new[t] = vet_temp[t];
		printf("[%d] ", vet_new[t]);

	}

	//printf("Aux = %d\n", aux);

}


void main() {

	int n, *vet, *vet_new;
	int max,min,tam,k;

	printf("Diga o numero de posicoes: ");
	scanf("%d", &n);

	srand(time(NULL));

	vet = (int *) malloc (n*sizeof(int));

	for(k=0; k<n; ++k) {
		vet[k] = rand () % 20;
		printf("[%d] ", vet[k]);
	}
	printf("\n"); 

	printf("Diga o numero maximo: ");
	scanf("%d", &max);
	printf("Diga o numero minimo: ");
	scanf("%d", &min);

	vet_new = valores_entre(vet,n,min,max,&tam);

}
