#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct inf{
    char nome[40];
    int data,mes,ano;
    double cpf,telefone;

}pessoas;

typedef struct auxiliar{
    int n,cont;
}aux;

void *pBuffer;
pessoas *ptr;

void adiciona(pessoas *p) {
    pBuffer = malloc (sizeof(pessoas));

    printf("Diga o nome: ");
    scanf("%s", pBuffer->nome);



}

aux *help;

// Utilizar da struct de variaveis auxiliares para fazer as referencias.
// So corno.


int main() {
    int n; // Temporário só para fazer a seleção de funções.

    do{

      printf("1) Adicionar\n2) Apagar\n3) Buscar\n4) Listar\n\n");
      scanf("%d", &n);
    switch(n) {

     case 1:
            adicionar(ptr);
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

   }while(n != 5);


    return 0;

}
