#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Tem um bug na hora de selecionar a 5 posição na primeira vez, ele sai do programa :(.

typedef struct inf{
    char nome[40];
    int idade,telefone;

}pessoas;

void *pBuffer;
pessoas *ptr,*ptr_aux,*ptr_aux3;
int *n,*cont,*lacos,*escolha;
int teste; // variável temporária para tentar o algoritmo de inserção.


void adicionar(){

    pBuffer = realloc(pBuffer,(4*sizeof(int)) + ((*cont)*sizeof(pessoas)));

	n = (int*) pBuffer;
    cont = (int*) n + 1;
    lacos = (int*) cont + 1;
    escolha = (int*) lacos + 1;

    if((*cont) == 1) {
    	ptr = (pessoas*) (escolha + 1);
    }
    else{
    	ptr = (int*) (escolha + 1);
    for(*lacos = 1; *lacos < *cont; ++(*lacos)) {

	ptr = (pessoas*) ptr + 1;

    }

    }

	printf("Diga o seu nome: ");
	scanf(" %s", ptr->nome);
    printf("Diga seu Idade: ");
    scanf("%d", &ptr->idade);
    printf("Diga o seu Telefone: ");
    scanf("%d", &ptr->telefone);

    }


void listar() {
	ptr = (int*) escolha + 1;

    for(*lacos = 0; *lacos < *cont; ++(*lacos)){
	printf("Nome: %s\n", ptr->nome);
	printf("Idade: %d\n", ptr->idade);
	printf("Telefone: %d\n", ptr->telefone);

	ptr = (pessoas*) ptr + 1;
    }

    }

void ordena(){

    ptr = escolha + 1;
    ptr_aux3 = escolha + 1;

    for(*lacos = 1; *lacos<*cont; *lacos = *lacos + 1){
        teste = *lacos - 1; // i = j - 1;
        ptr_aux = ptr + 1; // tmp = data[j];

        while( (teste>=0) && (ptr_aux->idade < ptr->idade)) {

            strcpy(ptr->nome,ptr_aux->nome); // passa o nome do próximo para o anterior.
            ptr->idade = ptr_aux->idade; // passa a idade do próximo para o anterior.
            ptr->telefone = ptr_aux->telefone; // passa o telefone do próximo para o anterior.

            strcpy(ptr_aux3->nome,ptr->nome); // passa o nome do anterior para o próximo.
            ptr_aux3->idade = ptr->idade; // passa a idade do anterior para o próximo.
            ptr_aux3->telefone = ptr->telefone; // passa o telefone do anterior para o próximo.
            teste--;
        }
        ptr = ptr + 1;
        ptr_aux3 = ptr_aux3 + 1;
    }



    }




void buscar() {


   ptr = escolha + 1;

   for(*lacos = 1; *lacos<=*cont; *lacos = *lacos +1){

   if(*lacos == *escolha) {
   printf("Nome: %s\n", ptr->nome);
   printf("Idade: %d\n", ptr->idade);
   printf("Telefone: %d\n", ptr->telefone);
   }
   ptr = (pessoas*) ptr + 1;
}

}

void apagar() {

	n = (int*) pBuffer;
    cont = (int*) n + 1;
    lacos = (int*) cont + 1;
    escolha = (int*) lacos + 1;

	ptr = escolha + 1;
	ptr_aux = ptr + 1;

	for(*lacos = 1; *lacos <= *cont; *lacos = *lacos + 1) {

    if(*lacos >= *escolha) {
    strcpy(ptr->nome,ptr_aux ->nome);
    ptr->telefone = ptr_aux->telefone;
    ptr->idade = ptr_aux->idade;

    }

    ptr = ptr + 1;
    ptr_aux = ptr_aux + 1;

	}

    *cont = *cont - 1;

    pBuffer = realloc(pBuffer,(4*sizeof(int)) + (*cont*sizeof(pessoas)));

	}





int main() {

    pBuffer = malloc (4*sizeof(int));

    n = pBuffer;
    cont = n + 1;
    lacos = cont + 1;
    escolha = lacos + 1;

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
            scanf("%d", escolha);
            apagar();
            break;

    case 3:
            printf("Diga o indice que voce deseja procurar: ");
            scanf("%d", escolha);
            buscar();
            break;
    case 4:
            ordena();
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
