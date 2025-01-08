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

/*
int criaLista(NO *lista) {
    int i, aux;
    aux = lista;
    for (i=1;i<=20;i++){
        aux->prox = criaNo(i);
        aux = lista->prox;
    }
}
*/

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

/*exercício 1 - crie uma função para:
    1. Imprimir os valores que estão em uma lista encadeada.
*/
int imprimir(NO *lista){
    if (listaVazia(lista)){
        printf("\nLista vazia");
    } else {
        NO *aux = lista;
        while (aux!=NULL){
            printf(" %d->", aux->chave);
            aux = aux->prox; //indo pro próximo elemento
        } 
    }
}

//2. Retornar a soma dos valores em uma lista
int soma(NO *lista){
    int soma = 0;
    if (listaVazia(lista)){
        printf("\nLista vazia");
    } else {
        NO *aux = lista;
        while (aux!=NULL){
            soma = soma + aux->chave;
            aux = aux->prox; //indo pro próximo elemento
        } 
    }
    return soma;
}

//3. Retornar o tamanho de uma lista encadeada
int tamanho(NO *lista){
    int cont = 0;
    if (listaVazia(lista)){
        printf("\nLista vazia");
    } else {
        NO *aux = lista;
        while (aux!=NULL){
            cont = cont + 1;
            aux = aux->prox; //indo pro próximo elemento
        } 
    }
    return cont;
}

//4. Retornar a média dos valores em uma lista encadeada
int media(NO *lista){
    return soma(lista) / tamanho(lista);
}

//5. (Desafio) Retorne o meio de uma lista encadeada (sem usar o tamanho dela)

NO *meioLista(NO *lista){
    NO *aux1, *aux2;
    aux1 = aux2 = lista;
    if (listaVazia(lista)){
        return NULL;
    } else {
        while (aux2 && aux2->prox!=NULL){
            aux1 = aux1->prox;
            aux2 = aux2->prox->prox;
        }
    }
}

//6. Inserir um valor no fim da lista
NO *insereFim(NO *lista, int chave){
    NO *aux = lista;
    //encontrar o final da lista
    if (listaVazia(lista)){
        lista = criaNo(chave);
    } else{
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = criaNo(chave);
    }
    return lista;
}
//lista = insereFim(lista, 5);

int main() {
    NO *l = NULL; // definindo uma variável do tipo NO
    //struct no *l
    //NO *novo = criaNo(7);
    //printf("\nChave = %d, prox = %p", novo->chave, novo->prox);
    criaNo(1); criaNo(40); criaNo(55);
    imprimir(l);
    return 0;
}