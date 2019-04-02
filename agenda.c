#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct inf{
    int nome[40];
    //int data,mes,ano;
    int cpf,telefone;

}pessoas;

void *pBuffer;
pessoas *ptr,*ptr_aux;


void adicionar(pessoas* p,pessoas *ptr_aux, int* c,int *lacos){

    if((*c) == 1) ptr_aux = (pessoas*) malloc (sizeof(pessoas));
    else ptr_aux = (pessoas*) realloc (ptr_aux,(*c)*sizeof(pessoas));

	printf("Diga o seu nome: ");
	scanf(" %s", ptr_aux->nome);
    printf("Diga seu CPF: ");
    scanf("%d", &ptr_aux->cpf);
    printf("Diga o seu Telefone: ");
    scanf("%d", &ptr_aux->telefone);


    pBuffer = realloc(pBuffer,(3*sizeof(int)) + ((*c)*sizeof(pessoas)));

    if((*c) == 1) {
    ptr_aux = (pessoas*)(lacos + 1);
    ptr = ptr_aux;
    }
    else {
    ptr_aux = (pessoas*) ptr + 1;
    }


    printf("memoria ptr: %d\n", ptr);
    printf("memoria ptr_aux: %d\n", ptr_aux);
    }


void listar(pessoas *p,pessoas *p_aux,int *lacos, int* c) {

    for(*lacos = 0; *lacos <= *c; ++(*lacos)){
	printf("Nome: %s\n", p->nome);
	printf("CPF: %d\n", p->cpf);
	printf("Telefone: %d\n", p->telefone);
	p = p + sizeof(pessoas);
    }

    }





int main() {

	int *n,*cont,*lacos;

    pBuffer = malloc (3*sizeof(int));

    n = pBuffer;
    cont = n + 1;
    lacos = cont + 1;

    printf("n = %d\n",n);
    printf("cont = %d\n",cont);
    printf("lacos = %d\n", lacos);

    *cont = 0;


      do{

      printf("1) Adicionar\n2) Apagar\n3) Buscar\n4) Listar\n5) Sair\n");
      scanf("%d", &(*n));

    switch(*n) {

     case 1:

			*cont = *cont +1;
            adicionar(ptr,ptr_aux,cont,lacos);





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
            listar(ptr,ptr_aux,&lacos,cont);
            break;

     case 5: break;

     default: printf("Esta opcao nao existe\n");
              break;

   }

   }while(*n != 5);


   return 0;
}
