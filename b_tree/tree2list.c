//tree2list.c
//function that turns a B Tree into a linked list in descending order

#include <stdio.h>
#include <stdlib.h>

typedef struct arvb {
    int nchaves;
    int folha;
    int *chave;
    struct arvb **filho;
} TARVB;

typedef struct lse{
  int info;
  struct lse *prox;
}TLSE;

TLSE* TLSE_inicializa(void){
  return NULL;
}

TLSE* TLSE_insere(TLSE *l, int elem){
  TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
  novo->prox = l;
  novo->info = elem;
  return novo;
}

TLSE* arvore_pra_lista_aux(TARVB *a, TLSE *l) {
    if (!a) return l;
    int i;
    l = arvore_pra_lista_aux(a->filho[a->nchaves], l);
    
    for (i = a->nchaves; i >= 0; i--) {
        l = TLSE_insere(l, a->chave[i]);
        l = arvore_pra_lista_aux(a->filho[i], l);
    }

    return l;
}

TLSE* arvore_pra_lista(TARVB *a) {
    TLSE *l = TLSE_inicializa();
    if(!a) return l;
    return arvore_pra_lista_aux(a, l);
}
