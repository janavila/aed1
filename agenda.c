#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct inf{
    char nome[20];
    int idade,telefone;

}pessoas;

void *pBuffer;
pessoas *ptr,*ptr_aux,*ptr_aux3;
int *n,*cont,*lacos,*escolha;


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

void insertionsort(){

    pBuffer = realloc(pBuffer,(4*sizeof(int)) + ((*cont+1)*sizeof(pessoas))); // Adiciona o auxiliar temporário.
	n = (int*) pBuffer;
    cont = (int*) n + 1;
    lacos = (int*) cont + 1;
    escolha = (int*) lacos + 1;
    ptr = (int*) (escolha + 1);
    for(*lacos = 1; *lacos < *cont; ++(*lacos)) {
	ptr = (pessoas*) ptr + 1;
    }

    ptr_aux3 = ptr + 1;
    ptr = escolha + 1;


    for(*lacos = 1; *lacos<*cont; *lacos = *lacos + 1){
        *escolha = *lacos - 1; // i = j - 1;
        *(ptr_aux3) = *(ptr+(*lacos)); // tmp = data[j];

        while( (*escolha>=0) && (ptr_aux3->idade < (ptr+(*escolha))->idade)) {
            *(ptr+(*escolha)+1) = *(ptr+(*escolha));
            *escolha = *escolha - 1;
        }

        *(ptr+(*escolha)+1) = *(ptr_aux3);

    }

    pBuffer = realloc(pBuffer,(4*sizeof(int)) + ((*cont)*sizeof(pessoas)));

    }


// Arrumar essa função...

void selectionsort() {

    pBuffer = realloc(pBuffer,(4*sizeof(int)) + ((*cont+1)*sizeof(pessoas))); // Adiciona o auxiliar temporário.
	n = (int*) pBuffer;
    cont = (int*) n + 1;
    lacos = (int*) cont + 1;
    escolha = (int*) lacos + 1;
    ptr = (int*) (escolha + 1);
    for(*lacos = 1; *lacos < *cont; ++(*lacos)) {
	ptr = (pessoas*) ptr + 1;
    }

    ptr_aux3 = ptr + 1;
    ptr = escolha + 1;

   for (*lacos=0; *lacos<*cont-1; *lacos = *lacos + 1) {
     *(ptr_aux3) = *(ptr+(*lacos));
     for(*escolha=*lacos+1; *escolha<*cont; *escolha = *escolha + 1)
        if((ptr+(*escolha))->idade < ptr_aux3->idade){



     	 }
     }

}

void bubblesort() {

    pBuffer = realloc(pBuffer,(4*sizeof(int)) + ((*cont+1)*sizeof(pessoas)));
	n = (int*) pBuffer;
    cont = (int*) n + 1;
    lacos = (int*) cont + 1;
    escolha = (int*) lacos + 1;
    ptr = (int*) (escolha + 1);
    for(*lacos = 1; *lacos < *cont; ++(*lacos)) {
	ptr = (pessoas*) ptr + 1;
    }

    ptr_aux3 = ptr + 1;
    ptr = escolha + 1;

    for(*lacos = 0; *lacos<*cont-1; (*lacos)++){

        for(*escolha = 0; *escolha<(*cont)-1; (*escolha)++){

            if((ptr+(*escolha))->idade > (ptr+(*escolha)+1)->idade){

            *(ptr_aux3) = *(ptr+(*escolha)); // temp
            *(ptr+(*escolha)) = *(ptr+(*escolha)+1); //
            *(ptr+(*escolha)+1) = *(ptr_aux3);

            }
        }
    }
    pBuffer = realloc(pBuffer,(4*sizeof(int)) + ((*cont)*sizeof(pessoas)));
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

      printf("1) Adicionar\n2) Apagar\n3) Buscar\n4) Listar\n5) Insertion Sort\n6) Selection Sort\n7) BubbleSort\n8) Sair\n");
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
            listar();
            break;

    case 5:
            insertionsort();
            listar();
            break;

    case 6:
            selectionsort();
            listar();
            break;

    case 7:
            bubblesort();
            listar();
            break;

    case 8: break;

    default: printf("Esta opcao nao existe\n");
            break;

   }

   }while(*n != 8);


    free(pBuffer);

   return 0;
}
