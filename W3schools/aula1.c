/*
    Programa para adicionar dois números inteiros
*/
#include <stdio.h> //scanf e printf
#include <stdlib.h>

typedef struct liv{
    int id;
    char titulo[60];
    //...
} livro;

//asterisco antes da variável ao determiná-la: ponteiro
//símbolo & antes da variável: endereço da variável

int main(void) {
    livro *liv1; //ponteiro para o tipo do livro
    liv1 = (livro*)malloc(sizeof(livro));
    if (!liv1) {
        printf("\nErro na alocação da memória.");
        exit(1); //término anormal
    }

    printf("\nDigite o valor de id: ");
    scanf("%d", &liv1->id);

    printf("\nDigite o título: ");
    scanf(" %s", &liv1->titulo);

    printf("\nid: %d", &liv1->id);

    printf("\nTítulo:%s", &liv1->titulo);

    free(liv1);

    return 0; // 0 - término normal; 1 - término anormal;
}

/*
int soma(int a, int b) {
    return a+b;
}

int main(void) {
    int a, b; //soma
    printf("\nDigite dois números inteiros: ");
    scanf("%d%d", &a, &b);
    //soma = a+b;
    printf("\nSoma = %d", soma(a, b));
    return 0; // 0 - término normal; 1 - término anormal;
}
*/

// Estruturas em C
/*
struct livro{
    int id;
    char titulo[60];
    char autor[40];
};
*/