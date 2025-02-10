#include<stdio.h>
#include<stdlib.h>

typedef struct no{
  int chave;
  struct no *esq; // filho da esquerda
  struct no *dir; // filhor da direita
}NO;

NO *inserir(NO *arv, int chave);

/*
  Como excluir?
  - Devemos considerar 3 casos:
    1 - O nó a ser excluído é uma folha; nesse caso basta removê-lo
    2 - O nó a ser excluído tem um filho à esquerda
*/

NO *excluir(NO *raiz, int chave){
  if (raiz==NULL){
    return raiz;
  }
  if (chave < raiz->chave){
    raiz->esq = excluir(raiz->esq, chave);
  }
}

int contaFolha(NO *raiz);

int altura(NO *raiz){
  if(!raiz){
    return 0;
  } else {
    return 1 + maior(altura(raiz->esq), altura(raiz->esq));
  }
}

int balanceada(NO *raiz){
  static int var1 = 0;
  if (raiz){
    if (balanceada(raiz->esq) && balanceada(raiz->dir) < 2){
      return balanceada(raiz->esq) && balanceada(raiz->dir);
    } else {
      return 0;
    }
  }
  return 1;
}

NO *criaNO(int chave);
NO *inserir(NO *raiz, int chave);
void imprimir(NO *raiz);


int main(){
   NO *raiz = NULL;
   int opcao, cont, alt;
   opcao = menu();
   int chave = scanf("&d", &chave);
   NO *arv;
   switch(opcao){
    case 1: // inserir
        raiz = inserir(raiz, chave);
        break;
    /*case 2: //excluir um nó
        raiz = excluir(raiz, chave);
        break;
    case 3: // conta as folhas
        cont = contarFolhas(raiz);
        break;
    case 4: // altura da arvore
        alt = altura(arv);
        break;*/
    case 5: //caminhamento em pré-ordem
        preOrdem(arv);
        break;
    case 6: //caminhamento em ordem central
        ordemCentral(arv);
        break;
    case 7: //caminhamento em pos-ordem
        posOrdem(arv);
        break;
    case 8: // criar um novo nó
        raiz = criaNo(chave);
        break;
    case 9: //imprimir um nó
        imprimir(raiz);
        break;
    default:
        printf("\nRetorno padrao");

};
return 0;
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
  if(raiz){
          if(!raiz->esq && !raiz->dir){
              return 1;
          }else{
              return contaFolha(raiz->esq)+contaFolha(raiz->dir);
          }
  }else{
      return 0;
  }
}

int contaNo(NO *raiz){
  if(!raiz){
      return 0;
  }else{
      return 1+contaNo(raiz->esq)+contaNo(raiz->dir);
  }
}

NO *minimo(NO *raiz){
  NO *aux = raiz;
  if(aux)
      while(aux->esq)
          aux = aux ->esq;
  return aux;
}



NO *minimoRec(NO *raiz){
  if(raiz && raiz->esq){
      return minimoRec(raiz->esq);
  }else{
      return raiz;
  }
}


NO *maio(NO *raiz){
  NO *aux = raiz;
  if(aux)
      while (aux->dir)
          aux = aux -> dir;
  return aux;
}


NO *maiorRec(NO *raiz){
  if(raiz && raiz->dir){
      return maiorRec(raiz->dir);
  }else{
      return raiz;
  }
}
/*
O antecessor em ordem de um dado nó, é o nó da árvore da esquerda que tem a maior chave
*/

NO *antecessor(NO *raiz){
  if(raiz && raiz->esq){
      return maximo(raiz->esq);
  }
  return raiz;
}



int maior(int a, int b){
  if(a>b)
      return a;
  return b;
}

/*
Escreva uma função em C para:

*/