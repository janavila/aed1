#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Tem um bug na hora de selecionar a 5 posição na primeira vez, ele sai do programa :(.

typedef struct inf{
    char nome[40];
    int cpf,telefone;

}pessoas;

void *pBuffer;
pessoas *ptr,*ptr_aux;
int *n,*cont,*lacos;


void adicionar(){

    pBuffer = realloc(pBuffer,(3*sizeof(int)) + ((*cont)*sizeof(pessoas)));

	n = (int*) pBuffer;
    cont = (int*) n + 1;
    lacos = (int*) cont + 1;

    if((*cont) == 1) {
    	ptr = (pessoas*) (lacos + 1);
    }
    else{
    	ptr = (int*)lacos + 1;
    for(*lacos = 1; *lacos < *cont; ++(*lacos)) {

	ptr = (pessoas*) ptr + 1;

    }

    }

	printf("Diga o seu nome: ");
	scanf(" %s", ptr->nome);
    printf("Diga seu CPF: ");
    scanf("%d", &ptr->cpf);
    printf("Diga o seu Telefone: ");
    scanf("%d", &ptr->telefone);

    }


void listar() {
	ptr = (int*) lacos + 1;
    for(*lacos = 0; *lacos < *cont; ++(*lacos)){
	printf("Nome: %s\n", ptr->nome);
	printf("CPF: %d\n", ptr->cpf);
	printf("Telefone: %d\n", ptr->telefone);

	ptr = (pessoas*) ptr + 1;
    }

    }

void buscar() {


   ptr = lacos + 1;

   for(*lacos = 1; *lacos<=*cont; *lacos = *lacos +1){

   if(*lacos == *n) {
   printf("Nome: %s\n", ptr->nome);
   printf("CPF: %d\n", ptr->cpf);
   printf("Telefone: %d\n", ptr->telefone);
   }
   ptr = (pessoas*) ptr + 1;
}

}

void apagar() {

	n = (int*) pBuffer;
    cont = (int*) n + 1;
    lacos = (int*) cont + 1;

	ptr = lacos + 1;
	ptr_aux = ptr + 1;

	for(*lacos = 1; *lacos <= *cont; *lacos = *lacos + 1) {

    if(*lacos >= *n) {
    strcpy(ptr->nome,ptr_aux ->nome);
    ptr->telefone = ptr_aux->telefone;
    ptr->cpf = ptr_aux->cpf;

    }

    ptr = ptr + 1;
    ptr_aux = ptr_aux + 1;

	}

    *cont = *cont - 1;

    pBuffer = realloc(pBuffer,(3*sizeof(int)) + (*cont*sizeof(pessoas)));

	}





int main() {

    pBuffer = malloc (3*sizeof(int));

    n = pBuffer;
    cont = n + 1;
    lacos = cont + 1;

    *cont = 0;


      do{

      printf("1) Adicionar\n2) Apagar\n3) Buscar\n4) Listar\n5) Sair\n");
      scanf("%d", n);

    switch(*n) {

    case 1:

			*cont = *cont +1;
            adicionar();

            break;
    case 2:
            printf("Apagar\n");
            printf("Diga o indice que voce deseja apagar: ");
            scanf("%d", n);
            apagar();
            break;

    case 3:
            printf("Diga o indice que voce deseja procurar: ");
            scanf("%d", n);
            buscar();
            break;
    case 4:
            listar();
            break;

     case 5: break;

     default: printf("Esta opcao nao existe\n");
              break;

   }

   }while(*n != 5);


    free(pBuffer);

   return 0;
}
