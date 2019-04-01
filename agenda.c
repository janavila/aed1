#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct inf{
    char nome[40];
    //int data,mes,ano;
    int cpf,telefone;

}pessoas;

// Pelo jeito, meu pBuffer só vai servir para armazenar minha agenda, mas não irei utiliza-lo para fazer
// as instruções das funções. Ele só irá ser a minha referencia.

void *pBuffer;
pessoas *ptr;


void adicionar(pessoas* p, int* c,int* lacos){
	
	printf("Diga o seu nome: ");
	scanf("%s", p->nome);
	printf("Diga o seu CPF: ");
	scanf("%d", &p->cpf);
	printf("Diga o seu Telefone: ");
	scanf("%d", &p->telefone);
	
//	p =  lacos+1;
}


void listar(pessoas *p) {
	
	printf("Nome: %s\n", p->nome);
	printf("CPF: %d\n", p->cpf);
	printf("Telefone: %d\n", p->telefone);
	
}


int main() {

	int *n,*cont,*lacos;
	
	n = (int*) malloc (sizeof(int));
    cont = (int*) malloc (sizeof(int));
    lacos = (int*) malloc (sizeof(int));
    
    pBuffer = malloc (3*sizeof(int));
    
    n = pBuffer;
    cont = n + 1;
    lacos = cont + 1;

    
    *cont = 0;
    
    
      do{

      printf("1) Adicionar\n2) Apagar\n3) Buscar\n4) Listar\n5) Sair\n");
      scanf("%d", &(*n));
	
    switch(*n) {

     case 1:
			printf("Adicionar\n");
			*cont = *cont +1;
			if(*cont == 1) ptr = (pessoas*) malloc ((*cont)*sizeof(pessoas));
			else ptr = (pessoas*) realloc (ptr,(*cont)*sizeof(pessoas));
			adicionar(ptr,cont,lacos);			
			
			// Quando retornar o ptr, tenho que adicionar ele no pBuffer, provalvemente fazer outro malloc.	
			
			
            break;
     case 2:
            printf("Apagar\n");
            //apagar()
            break;

     case 3:
            printf("Buscar\n");
            //buscar()
            break;
     case 4:
            printf("Listar\n");
            listar(ptr);
            break;

     case 5: break;

     default: printf("Esta opcao nao existe\n");
              break;

   }

   }while(*n != 5);


   return 0;
}
