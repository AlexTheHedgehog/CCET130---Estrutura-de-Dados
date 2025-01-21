#include<stdio.h> // scanf , printf
#include<stdlib.h> // malloc, free, sizeof

typedef struct no{
    int chave;
    struct no *prox;
    struct no *ant;
}NO;


/*
Nome da Função: criaNo
Parâmetros: chave do tipo inteiro
Retorno: um nó contento a chave informada
Forma de uso: <variavel do tipo *NO> = criaNo(chave);
*/
NO *criaNo(int chave){
    NO *novo = (NO*)malloc(sizeof(NO*));
    if (novo==NULL){ // !novo
        printf("\nERRO DE ALOCAÇÃO DE MEMÓRIA");
        exit(1);
    }
    novo->chave = chave; // (*novo).chave = chave
    novo->prox = NULL;   //(*novo).prox = NULL
    novo->ant = NULL;
    return novo;    
}

int listaVazia(NO *l){
    return l?0:1;
}

// Função para verificar se um nó é o último da lista
int ultimo(NO *no){
    if (no && no->prox == NULL)
        return 1;
    else
        return 0;
}

NO *ultimoNo(NO *lista){
    NO* ultimo = lista;
    if (!ultimo)
        return NULL;
    while(ultimo->prox !=NULL)
        ultimo = ultimo->prox;
    return ultimo;
}

void imprime(NO *lista){
    if (listaVazia(lista)) // if (!lista)
        printf("\nLista Vazia");
    else{
        NO *aux = lista;
        while(aux){ // aux!= NULL
            printf(" %d->",aux->chave);
            aux = aux->prox; // Vá para o próximo elemento
        }
    }
}
/*
    Nome da função: imprime_rec
    parâmetros: lista - ponteiro para a lista encadeada da qual queremos imprimir as chaves
    chamada: imprime_rec(<ponteiro-para-uma-lista-encadeada>);
*/

void imprime_rec(NO *lista){
    if (lista !=NULL){
        // FAÇA ALGO
        printf("%d->", lista->chave);
        imprime_rec(lista->prox);
    }

}

int conta_rec(NO *lista){
    if (lista !=NULL){
        // FAÇA ALGO
        return 1+ conta_rec(lista->prox);
    }
    return 0; // lista vazia
}

/*
    Chamada: lista = exclui(lista, valor);
*/

NO *exclui(NO *lista, int chave){
    NO *aux = lista;
    if ( lista ){ // a lista não está vazia
        if ( aux==lista && aux->chave == chave){ // remoção do primeiro elemento
            lista = aux->prox;
            lista->ant = NULL; 
            free(aux);
        }else{
            while(aux && aux->chave!= chave){
              aux = aux->prox;          
            }
            if (aux!= NULL){
                aux->ant->prox = aux->prox;
                if (aux->prox)
                  aux->prox->ant = aux->ant;
                free(aux);
            }
            else{
                printf("\nChave não encontrada");
            }
        }
    }
    else{
        printf("\nLISTA VAZIA");
        return NULL;
    }
    return lista; 
}

NO *busca(NO *lista, int chave){
  NO *aux = lista;
  while(aux && aux->chave!= chave){
    aux = aux->prox;          
  }
  return aux;
}
/*
NO *exclui(NO *lista, int chave){
    NO *aux = busca(lista, chave);
    if (aux){
        if ( aux==lista){ // remoção do primeiro elemento
          lista = aux->prox;
          lista->ant = NULL; 
          free(aux);
        }
        else{
            if (aux!= NULL){
              aux->ant->prox = aux->prox;
              if (aux->prox)
                aux->prox->ant = aux->ant;
              free(aux);
            }
        }
      else{
         printf("\nChave não encontrada");
    }
  return lista; 
}


*/

NO *meioLista(NO *lista){
    NO *aux1 , *aux2;
    aux1 = aux2 = lista;
    if (listaVazia(lista))
        return NULL;
    while(aux2 && aux2->prox!=NULL){
        aux1 = aux1->prox;
        aux2 = aux2->prox->prox;
    }
    return aux1;
}

NO *insereFim(NO *lista, int chave){
    NO *aux = lista, *novo = criaNo(chave);
    // encontrar o final da lista
    if (listaVazia(lista)){
        lista =  novo;
    }
    else{
        while(aux->prox != NULL){
            aux = aux->prox;    
        }
        aux->prox = novo;
        novo->ant = aux;
    }
    return lista;
}
// lista = insereFim(lista, 5);

/*
Função: insereInicio
Descrição: Função para inserir um novo valor no início de uma lista simplesmente
encadeada
Parâmentros: lista - lista encadeada onde queremos inserir um novo nó
             chave - valor que vamos inserir na lista
Chamada: <ponteiro-para-NO> = insereInicio(lista, chave)
*/

NO *insereInicio(NO *lista, int chave){
    NO *novo = criaNo(chave);
    if (!novo){
        printf("\nFalha de alocação de memória");
        exit(1);
    }
    novo->prox = lista;
    return novo;
}

void imprime_recursivo(NO *lista){
    if (lista){
        printf(" %d->",lista->chave);
        imprime_recursivo(lista->prox);
    }
}
void imprime_inverso(NO *lista){
     if (lista){
        imprime_inverso(lista->prox);
        printf(" %d->",lista->chave);
    }
}
/*
    chamada: lista = reverso_lista(lista, NULL);
*/
NO *reverso_lista(NO *lista, NO *aux){
  NO *a1;
  if (lista){
        a1 = lista->prox;
        lista->prox = aux;
        aux = lista;
        if (a1)
            lista = reverso_lista(a1, aux);
        else
            lista = aux;
    }
    return lista;
}


NO *libera(NO *lista){
    NO *aux = lista;
    while (aux){
        lista = aux->prox;
        free(aux);
    }   
    return lista;
}

NO *merge(NO *lista1, NO *lista2){
  NO *a1 = lista1, *a2 = lista2, *lista3 = NULL;
    while (a1 && a2){
        if (a1->chave <= a2->chave){
            lista3 = insereFim(lista3, a1->chave);
            a1 = a1->prox;
        }
        else{
          lista3 = insereFim(lista3, a2->chave);
          a2 = a2->prox;
        }
    }
    while(a1){
      lista3 = insereFim(lista3, a1->chave);
      a1 = a1->prox;
    }
    while(a2){
      lista3 = insereFim(lista3, a2->chave);
      a2 = a2->prox;
    }
  return lista3;
}

int main()
{
    NO *l = NULL ; // definindo uma variável do tipo NO
  // fazer um  menu para as chamadas das funções
   // struct no *l;
 /*
    l = criaNo(7);
    l->prox = criaNo(8);
    l->prox->prox = criaNo(9);
    l->prox->prox->prox = criaNo(5);
    l->prox->prox->prox->prox = criaNo(1);    
    imprime(l);
    
    NO *meio = meioLista(l);
    if ( meio )
        printf("\n\nValor que está no meio da lista = %d", meio->chave);
    else
        printf("\nLISTA VAZIA");
    printf("\n\n");    
    imprime(reverso_lista(l, NULL));
    
    l = libera(l); // libera a memória alocada
   */ 
    return 0;
}


/*
EXERCÍCIOS
Escreva uma função em C para:

1(*).  Imprimir os valores que estão em uma lista encadeada l.
2.  Retornar a soma dos valores em uma lista
3.  Retornar o tamanho de uma lista encadeada
4.  Retornar a média dos valores em uma lista encadeada
5(*).  (Desafio)Retorne o meio de uma lista encadeada (sem
    usar o tamanho dela) ...
6(*).  Inserir uma nova chave na lista.
7.  Inserir uma chave no início da lista
8.  Quantos nós têm chaves pares?
9.  Inserir chaves em uma lista encadeada de forma que ela fique sempre ordenada.
10. Imprimir a lista de trás para frente.
11. Remover um nó de uma lista encadeada.
12. Remover todos os nós de uma lista encadeada.
13. Inverter uma lista encadeada.
14. Retornar o último nó de uma lista encadeada.
15. Retornar o penúltimo nó de uma lista encadeada.
16. Retornar o n-ésimo nó de uma lista encadeada.
17. Retornar o n-ésimo nó de uma lista encadeada a 
partir do final.
18. Retornar o n-ésimo nó de uma lista encadeada a partir do meio.
19. Retornar o n-ésimo nó de uma lista encadeada a partir do início.
20. Retornar o n-ésimo nó de uma lista encadeada a partir do final.
21. Escreva uma função para concatentar de forma que a 
segunda seja incluída no final primeira. Ao final as duas 
listas devem permanecer independentes.
22. Escreva um função para fazer a fusão de duas, l1 e l2,  de forma que a lista final contenha os valores contidos em l1 e l2 e esteja ordenada.
*/

//crie uma lista de exercícios mais difíceis sobre 
//listas simplesmente encadeadas , duplamente encadeadas e listas circulares