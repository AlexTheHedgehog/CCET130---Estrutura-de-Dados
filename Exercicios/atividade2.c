#include<stdio.h>
#include<stdlib.h>

//Atividade de Daniel Gomes Chaves

typedef struct no{
    int chave;
    struct no *esq; // filho da esquerda
    struct no *dir; // filhor da direita
}NO;

NO *criaNo(int chave){
    NO *novo = (NO*)malloc(sizeof(NO*));
    if (!novo){
        printf("\nErro de alocação!");
        exit(1);
    }
    novo->chave = chave;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

int maior(int a, int b){
    if(a>b)
        return a;
    return b;
  }

int altura(NO *raiz){
    if(!raiz){
        return 0;
    } else {
        return 1 + maior(altura(raiz->esq), altura(raiz->esq));
    }
}

// 1 - Verificar se todo nó de uma árvore binária de busca tem 0 ou 2 filhos.

int zeroOuDois(NO *raiz){
    if (!raiz){
        return 1;
    }

    if (((raiz->esq != NULL) && (raiz->dir == NULL)) || (raiz->esq == NULL) && (raiz->dir != NULL)){
        return 0;
    }

    return (zeroOuDois(raiz->esq) && zeroOuDois(raiz->dir));
}

// 2 - Verificar se uma ABB é completa (todas as folhas estão no último nível)

int abbCompleta(NO *raiz, int nivel, int altura){
    if (!raiz){
        return 1;
    }

    if (raiz->dir == NULL && raiz->esq == NULL){
        return nivel == altura;
    }

    if (raiz->dir == NULL || raiz->esq == NULL){
        return 0;
    }

    return abbCompleta(raiz->esq, nivel + 1, altura) && abbCompleta(raiz->dir, nivel + 1, altura);
}