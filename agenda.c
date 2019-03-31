#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct inf{
    char nome[40];
    int data,mes,ano;
    double cpf,telefone;

}pessoas;

typedef struct auxiliar{
    int n,cont,escolha;
}aux;


void *pBuffer;
pessoas *ptr;
aux *help;

void adiciona(void *buf,pessoas *p,aux *h) {
    pessoas *auxi;

    if(h->cont == 1) {
    ptr = (pessoas*) malloc ((h->cont)*(sizeof(pessoas)));
    pBuffer = malloc (sizeof(aux) + ((h->cont)*(sizeof(pessoas))));

    }

    else {
    ptr = realloc(ptr,(h->cont)*(sizeof(pessoas)));
    pBuffer = malloc (sizeof(aux) + ((h->cont)*(sizeof(pessoas))));
    }





}



int main() {

    help = (aux*) malloc (sizeof(aux));
    help->cont = 0;

      do{

      printf("1) Adicionar\n2) Apagar\n3) Buscar\n4) Listar\n\n5)Sair\n");
      scanf("%d", &help->escolha);


    switch(help->escolha) {

     case 1:

            help->cont= help->cont + 1;
            adicionar(pBuffer,ptr,help);

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
            //listar()
            break;

     case 5: break;

     default: printf("Esta opcao nao existe\n");
              break;

   }

   }while(help->escolha != 5);


   return 0;
}
