#include <stdio.h> //scanf, printf
#include <stdlib.h> //malloc, free, sizeof

typedef struct no{
    int chave;
    struct no *prox;
}NO;
/*
prototipação
Nome da função: criaNo
Parâmetros: um nó contendo a chave informada
Formas de uso: <variável do tipo no> = criaNo(chave)
*/
NO *criaNo(int chave) {
    NO *novo = (NO*)malloc(sizeof(NO*));
    if (novo==NULL){ // !novo
        printf("\nERRO DE ALOCAÇÃO DE MEMÓRIA");
        exit(1);
    }
    novo->chave = chave; // (*novo).chave = chave
    novo->prox = NULL; // (*novo).prox = NULL
}

int listaVazia(NO *l) {
    if(!l){
        return 0;
    }
    return 1;
    //return l==NULL?0:1;
}

// Função para verificar se o nó é o último da lista
int ultimoNo(NO *no){
    if(no && no->prox == NULL){
        return 1;
    } else {
        return 0;
    }
}

int main() {
    NO *l = NULL; // definindo uma variável do tipo NO
    //struct no *l
    NO *novo = criaNo(7);
    printf("\nChave = %d, prox = %p", novo->chave, novo->prox);
    return 0;
}