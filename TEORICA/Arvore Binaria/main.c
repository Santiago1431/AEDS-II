#include <stdio.h>
#include <stdlib.h>

//no de itens para a arvore
typedef struct no_{
    int dado;
    struct no_ *esq;
    struct no_ *dir;
}no;



void * inserir(no *raiz, no *n){

    if (raiz == NULL){
        return n;
    }else
        if (raiz->dado > n->dado){
            raiz->esq = inserir(raiz->esq, n);
        }else
            raiz->dir = inserir(raiz->dir, n);
        return raiz;
}   

void imprime(no *raiz){
    if(raiz->esq != NULL){
        imprime(raiz->esq);
    }
    printf("%d ",raiz->dado);
    if(raiz->dir != NULL){
        imprime(raiz->dir);
    }
}

int main(int argc, char const *argv[])
{
    no *raiz = NULL;
    no *n1 = (no*)malloc(sizeof(no));
    no *n2 = (no*)malloc(sizeof(no));
    no *n3 = (no*)malloc(sizeof(no));
    printf("insira o Valor de n1: \n");
    scanf("%d",&n1->dado);
    n1->esq = NULL;
    n1->dir = NULL;

    printf("insira o Valor de n2: \n");
    scanf("%d",&((*n2).dado));
    n2->esq = NULL;
    n2->dir = NULL;
    printf("insira o Valor de n3: \n");
    scanf("%d",&n3->dado);
    n3->esq = NULL;
    n3->dir = NULL;

    raiz = inserir(raiz, n1);
    raiz = inserir(raiz, n2);
    raiz = inserir(raiz, n3);
    imprime(raiz);
    
    return 0;
}
