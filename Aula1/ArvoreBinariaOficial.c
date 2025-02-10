#include<stdio.h>
#include<stdlib.h>
typedef struct no{
  int chave;
  struct no *esq; //filho da esquerda
  struct no *dir;  //filho da direita
}NO;

NO *inserir(NO *arv, int chave);
NO *excluir(NO *arv, int chave);
NO *criaNo(chave);
int contaFolha(NO *arv);
int altura(NO *arv);
void preordem(NO *arv);//caminhamento em pré-ordem
void ordemCentral(NO *arv);//caminhamento em ordem central
void posordem(NO *arv);//caminhamento em pos-ordem
NO *novo(int chave);
NO *inserir(NO *raiz, int chave);
void imprimir(NO *raiz);
int contaNo(NO *raiz);
NO *monimo(NO *raiz);


int main(){
    NO *raiz = NULL;
    int opcao;
    opcao=menu();
    int chave = scanf("&d", &chave);
    NO *arv;
    int cont;
    int alt;
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


NO *criaNo(int chave){
    NO *novo = (NO*)malloc(sizeof(NO*));
    if(novo == NULL){
        printf("\nFalha na alocação de memoria");
        exit(1);
    }
    novo->chave = chave;
    novo->esq = novo->dir = NULL;
    return novo;
}

/*
    PRÉ-ORDEM
    -processa a raiz
    -Visite a árvore da esquerda
    -Visite a árvore da direita
*/
void preOrdem(NO *raiz){
    if(raiz){
        printf("\n%d", raiz->chave);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);

    }
}

/*
    ORDEM CENTRAL
    -visite a arvore da esquerda
    -processa a raiz
    -visite a árvore da direita
*/
void ordemCentral(NO *raiz){
    if(raiz){
        ordemCentral(raiz->esq);
        printf("\n%d", raiz->chave);
        ordemCentral(raiz->dir);

    }
}

/*
    PÓS-ORDEM
    -visite a arvore da esquerda
    -visite a árvore da direita
    -processa a raiz
*/
void posOrdem(NO *raiz){
    if(raiz){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("\n%d", raiz->chave);

    }
}

NO *inserir(NO *raiz, int chave){
    if(!raiz){
        raiz = criaNo(chave);
    }else{
        if(chave <= raiz->chave){
            raiz->esq = inserir(raiz->esq, chave);
        }else{
            raiz->dir = inserir(raiz->dir, chave);
        }
    }
    return raiz;
}

void imprimir(NO *raiz){
    if(raiz){
        imprimir(raiz->esq);
        printf("\n%d", raiz->chave);
        imprimir(raiz->dir);
    }
}
/*
int menu(){
    int opcao;
    do{
        printf("\n 1 - Inserir");
        printf("\n 2 - Excluir");
        printf("\n 3 - Contar Folhas");
        printf("\n 4 - Altura da árvore");
        printf("\n 5 - Caminhar em pré-ordem");
        printf("\n 6 - Caminhar em ordem central");
        printf("\n 7 - Caminhar em pos-ordem");
        printf("\n 8 - Criar um novo nó");
        printf("\n 9 - Imprimir");
        printf("\n 9 - Imprimir");
        scanf("&d",&opcao);
    }while(opcao<1 || opcao>=9);
    return opcao;
}*/

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


int altura(NO *raiz){
    if(!raiz)
        return 0;
    else{
        return 1 + maior(altura(raiz->esq), altura(raiz->dir));
    }
}




/*
    Como devemos excluir?
    Devemos considerar três casos:
    1 - O nó a ser excluído é um folha: nesse caso basta removê-lo
    2 - O nó a ser excluído tem um filho á esquerda
*/
NO *excluir(NO *raiz, int chave){
    if(raiz == NULL)
        return raiz;

    //Percorrendo a árvore para encontrar o nó a ser excluído
    if(chave < raiz->chave){
        raiz ->esq = excluir(raiz->esq, chave);
    }else if(chave > raiz->chave){
             raiz->dir = excluir(raiz->dir, chave);
    } else{
        //caso 1: Nó sem filhos (folha)
        if(raiz ->esq == NULL && raiz->dir == NULL){
            free(raiz);
            return NULL;
        }
        //Caso 2: Nó com um único filho
        else if(raiz->esq == NULL){
            NO *temp = raiz->dir;
            free(raiz);
            return temp;
        }else if(raiz->dir == NULL){
            struct NO *temp = raiz->esq;
            free(raiz);
            return temp;
        }
        //Caso 3: Nó com doi filhos
        else{
            NO *temp = minimo(raiz->dir);
            raiz->chave = temp->chave;
            raiz->dir = excluir(raiz->dir, temp->chave);
        }

    }
    return raiz;
}



int balanceada(NO *raiz){
    if(raiz){
        if(altura(raiz->esq) - altura(raiz->dir)<2){
            return balanceada(raiz->esq) && balanceada(raiz->dir);
        }else{
            return 0;
        }
    }
    return 1;
}




//verificar se a arvore é binaria de oerquisa
//verificar se todos os nos de uma arvore de busca tem 0 ou 2 filhos
//verificar se uma ABB é completa (todas as folhas estão no ultimo nivel)