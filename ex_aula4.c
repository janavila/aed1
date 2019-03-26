#include <stdio.h>
#include <stdlib.h>
#include "reader.h"

void main() {
	int l,c,k,t;
	int *matriz,*p;
	printf("Diga o número de colunas/linhas: ");
	scanf("%d", &l);
	scanf("%d", &c);


	matriz = (int *) malloc ((l* c) *sizeof(int*));

	p = matriz;
	// P é um auxiliar
	// http://www.ic.unicamp.br/~norton/disciplinas/mc1022s2005/03_11.html - Link de Referencia.
	for(k=0; k<l; k++) {
		for(t=0; t<c; t++) {
			printf("Digite o valor da M[%d][%d]: ",k,t);
			scanf("%d", p);
			p++;
		}
		
	}



	
	}

