//programa q cria pilha com alocação dinamica 

#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <stdbool.h>

//no de itens para a pilha
typedef struct no_{
    int dado;
    struct no_ *prox; 
}no;

//struct pilha tamanho ilimitado
typedef struct pilha_{
    no *topo;
}pilha;

void iniciarpilha(pilha *p){
    p->topo = NULL;
}
void empilha(int dado, pilha *p){
    no *ptr = (no*)malloc(sizeof(no));
    if (ptr == NULL){
        printf("erro na alocação");
        return;
    }else{
        ptr->dado = dado;
        ptr->prox = p->topo;
        p->topo = ptr;
    }
}

int desempilha(pilha *p){
    no* ptr = p->topo;
    int dado;
    if (ptr == NULL)
    {
        printf("pilha vazia");
        return;
    }else{
        p->topo = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        return dado;
    }  
    
}

void imprime(pilha *p){
    no *ptr = p->topo;
    if (ptr == NULL)
    {
        printf("pilha vazia");
        return;
    }
    
    while(ptr != NULL){
        printf("%d\n",ptr->dado);
        ptr = ptr->prox;
    }
}

int main(int argc, char const *argv[])
{
    pilha *p = (pilha*)malloc(sizeof(pilha));
    if (p == NULL)
    {
        printf("erro na alocação");
        return;
    }else{
        iniciarpilha(p);

        empilha(10,p);
        empilha(20,p);
        empilha(30,p);

        imprime(p);

        printf("desempilhando\n");

        printf("%d\n",desempilha(p));
        printf("%d\n",desempilha(p));

        printf("pilha restante\n");
        imprime(p);
        printf("\n");
    }
     
    
    
    return 0;
}



