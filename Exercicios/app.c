#include<stdio.h>
#include<stdlib.h>

// Define o tipo do nó
typedef struct no{
    int chave;
    struct no *prox;
    struct no *ant;
}NO;

// Cria o nó
NO *criaNo(int chave){
    NO *novo = (NO*)malloc(sizeof(NO*));
    if (!novo){
        printf("\nErro de alocação!");
        novo->chave = chave;
        novo->prox = NULL;
        novo->ant == NULL;
        return novo;
    }
}

// 1(*).  Imprimir os valores que estão em uma lista encadeada l.
void imprimir(NO *lista){
    if (!lista){
        printf("\nLista Vazia!");
    } else {
        NO *aux = lista;
        while(aux){
            printf(" %d", aux->chave);
            aux = aux->prox;
        }
    }
}

// 2  Retornar a soma dos valores em uma lista
int somar(NO *lista){
    int soma = 0;

    if (!lista){
        printf("\nLista Vazia!");
    } else {
        NO *aux = lista;
        while (aux){
            soma = soma + aux->chave;
            /*
            soma = soma * aux->chave;
            soma = soma - aux->chave;
            */
            aux = aux->prox;
        }
        return soma;
    }
}

// 3. Retornar o tamanho da lista
int tamanho(NO *lista){
    int cont = 0;
    
    if (!lista){
        printf("\nLista Vazia!");
    } else {
        NO *aux = lista;
        while (aux){
            cont = cont + 1;
            aux = aux->prox;
        }
        return cont;
    }
}

// 4.  Retornar a média dos valores em uma lista encadeada
int media(NO *lista){
    NO *aux = lista;
    return somar(aux) / tamanho(aux);
}

// 5(*). (Desafio)Retorne o meio de uma lista encadeada (sem usar o tamanho dela)
NO *meioLista(NO *lista){
    NO *aux1, *aux2;
    aux1 = aux2 = lista;

    if (!lista){
        printf("\nLista Vazia!");
    } else {
        while (aux2 && aux2->prox){
            aux1 = aux2->prox;
            aux2 = aux2->prox->prox;
        }
        return aux1;
    }
}

// 6(*). Inserir uma nova chave na lista.
void insereFim(NO *lista, int chave){
    NO *aux = lista;

    if (!lista){
        lista = criaNo(chave);
    } else {
        while (aux->prox){
            aux = aux->prox;
        }
        aux->prox = criaNo(chave);
    }
    return lista;
}

// 7. Inserir uma chave no início da lista
NO *insereInicio(NO *lista, int chave){
    NO *novo = criaNo(chave);

    if (!novo){
        printf("\nFalha de alocação!");
        exit(1);
    }
    novo->prox = lista;
    return novo;
}

// 8. Quantos nós têm chaves pares?
int chavesPares(NO *lista){
    int cont = 0;

    if (!lista){
        printf("\nLista vazia!");
    } else {
        NO *aux = lista;

        while (aux){
            if (aux->chave % 2 == 0){
                cont = cont + 1;
            }
        }
        return cont;
    }
}

// 9. Inserir chaves em uma lista encadeada de forma que ela fique sempre ordenada.
