 #include<stdio.h>
#include<stdlib.h>

typedef struct no{
  int chave;
  struct no *esq; // filho da esquerda
  struct no *dir; // filhor da direita
}NO;

NO *inserir(NO *arv, int chave);
NO *excluir(NO *arv, int chave);
int contaFolha(NO *arv);
int altura(NO *arv);
NO *criaNO(int chave);
NO *inserir(NO *raiz, int chave);
void imprimir(NO *raiz);


int main(){
   NO *raiz = NULL;
   int opcao;
   opcao = menu();
   switch(opcao){
      case 1: // inserir uma chave
          raiz = inserir(raiz, chave);
          break;
      case 2: // excluir um nó
          raiz = excluir(raiz, chave);
          break;
      
   };
}

NO *criaNO(int chave){
  NO *novo = (NO*)malloc(sizeof(NO*));
  if (!novo){
    printf("\nFALHA DE ALOCAÇÃO DE MEMÓRIA");
    exit(1);
  }
  novo->chave = chave;
  novo->esq = novo->dir = NULL;
  return novo;
}
/*
  CAMINHAMENTOS EM ÁRVORES

  PRÉ-ORDEM
  - Processa a raiz
  - Visite a árvore da esquerda
  - Visite a árvore da direita
  ORDEM-CENTRAL
   - Visite a árvore da esquerda
   - Processa a raiz
   - Visite a árvore da direita
  PÓS-ORDEM
  - Visite a árvore da esquerda
  - Visite a árvore da direita
  - Processa a raiz
*/
void preOrdem(NO *arv); // caminhamento em pré-ordem
void ordemCentral(NO *arv); // caminhamento em ordem central
void posOrdem(NO *arv); // caminhamento em pós-ordem

/*
  PRÉ-ORDEM
  - Processa a raiz
  - Visite a árvore da esquerda
  - Visite a árvore da direita

*/
void preOrdem(NO *raiz){
  if (raiz){
    printf("\n%d", raiz->chave);
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
  }
}
/*
  ORDEM-CENTRAL
  - Visite a árvore da esquerda
  - Processa a raiz
  - Visite a árvore da direita

*/
void ordemCentral(NO *raiz){
  if (raiz){
    ordemCentral(raiz->esq);
    printf("\n%d", raiz->chave);
    ordemCentral(raiz->dir);
  }
}

/*
  ORDEM-CENTRAL
  - Visite a árvore da esquerda
  - Processa a raiz
  - Visite a árvore da direita

*/
void posOrdem(NO *raiz){
  if (raiz){
    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
    printf("\n%d", raiz->chave);
  }
}

NO *inserir(NO *raiz, int chave){
    //NO *novo = criaNO(chave);
    if (!raiz){ // raiz == NULL
        raiz = criaNO(chave);
    }
    else{
        if(chave <= raiz->chave ){
             // vai ser inserida na sub-árvore da esquerda
             raiz->esq = inserir(raiz->esq, chave);
        }else{ // vai ser inserida na sub-árvore da direita
             raiz->dir = inserir(raiz->dir, chave);
        }
    }
    return raiz;
}
void imprimir(NO *raiz){
  if (raiz){
    imprimir(raiz->esq);
    printf(" %d", raiz->chave);
    imprimir(raiz->dir);
  }
}

int contaFolha(NO *raiz){
    
}