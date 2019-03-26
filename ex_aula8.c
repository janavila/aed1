#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 int* uniao(int *v1, int n1, int *v2, int n2) {
    int *v3;
    int tam;
	int j,t;
	
	tam = n1+n2;
	
	v3 = (int*) malloc (tam*sizeof(int));
	
	for(j=0; j<n1; ++j) {
		v3[j] = v1[j];
	}
	
	for(t=0; t<n2; ++t) {
		v3[j] = v2[t];
		j++;
	}
		return v3;
 } 


void main() {
	
	int *v1,*v2,*v3;
	int n1,n2,n3;
	int t;
	
	printf("Diga a quantidade de elementos do vetor1 e vetor2: ");
	scanf("%d %d", &n1,&n2);

	v1 = (int*) malloc (n1*sizeof(int));
	v2 = (int*) malloc (n2*sizeof(int));
	
	printf("Vetor 1: ");
	for(t=0; t<n1; ++t) {
		v1[t] = rand()%10;
		printf("[%d] ", v1[t]);
	}
	printf("\n");
	printf("Vetor 2: ");
	for(t=0; t<n2; ++t) {
		v2[t] = rand()%10;
		printf("[%d] ", v2[t]);
	}
	
	n3 = n1 + n2;
	printf("\n");
	//v3 = (int*) malloc (n3*sizeof(int));
	
	v3 = uniao(v1,n1,v2,n2);
	
	
	printf("Vetor 3: ");
	for(t=0; t<n3; ++t) {
		printf("[%d] ", v3[t]);
	}
	
	free(v1);
	free(v2);
}
