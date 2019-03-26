#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ler_aposta(int*aposta, int n) {
	int k;
	for(k=0; k<n; ++k) {
		do{
			printf("Digite o numero [%d]:", k+1);
			scanf("%d", &aposta[k]);
			if(aposta[k] > 100) printf("\nNumero invalido, digite novamente\n");
			
		}while(aposta[k] >= 100);
	}
}

void sorteia_valores(int *sorteia, int n) {
	int k;
	for(k=0; k<n; ++k) {
		sorteia[k] = rand()%101;
	}
}

int* compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns) {
	int t,k,cont;
	int temp[50],*retorno;
	
	
	for(k=0; k<na; ++k) {
		for(t=0; t<ns; ++t) {
			if(aposta[k] == sorteio[t]) {
				cont++;
				temp[k] = aposta[k];
				
			}
		}
	}
	
	retorno = (int*) malloc (cont*sizeof(int));
	*qtdacertos = cont;
	retorno = temp;
	
	for(k=0; k<cont; ++k) printf("retorno [%d]\n",retorno[k]);
	
	return retorno;
}

void main() {
	int *vet,*vet_comp,*vet_acerto;
	int n,k,acertos,j;
	
	printf("Diga a quantidade de numeros que voce deseja apostar(1 a 20): ");
	scanf("%d", &n);
	
	vet = (int*) malloc (n*sizeof(int));
	
	ler_aposta(vet,n);
	
	/*
	for(k=0; k<n; ++k){
		printf("[%d] ", vet[k]);
	
		
	}*/
	
	vet_comp = (int*) malloc (20*sizeof(int));
	srand(time(NULL));
	sorteia_valores(vet_comp,20);
	
	/*for(k=0; k<20; ++k) {
		printf("[%d] ", vet_comp[k]);
	}
	*/
	
	 
	vet_acerto = compara_aposta(vet,vet_comp,&acertos,n,20);
	
	printf("Acertos: ");
	if(acertos == 0) printf("Voce nao acertou nenhum numero :(\n\n");
	else {
	
	for(k=0; k<acertos; ++k) {
		printf("[%d] ",vet_acerto[k]);
	}
}
	
	//free(vet);
	//free(vet_comp);
	//free(vet_acerto);
	
}
