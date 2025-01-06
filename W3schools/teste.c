#include <stdio.h>

typedef struct liv{
    int id;
    char titulo[60];
    //...
} livro;

livro *novoLivro(livro *liv1) {
    liv1 = (livro*)malloc(sizeof(livro));
    if (!liv1) {
        printf("\nErro na alocação da memória.");
        exit(1); //término anormal
    }

    printf("\nDigite o valor de id: ");
    scanf("%d", &liv1->id);
    
    printf("\nDigite o título: ");
    scanf(" %s", &liv1->titulo);

    return liv1;
};

void imprime(livro *liv1) {
    printf("\nid: %d", &liv1->id);
    printf("\nTítulo:%s", &liv1->titulo);
}

livro *libera(livro liv1){
    free (liv1);
    return NULL;
}

int main(void) {
    livro *liv1; //ponteiro para o tipo livro

    liv1 = novoLivro(liv1);
    imprime(liv1);
    free(liv1);

}