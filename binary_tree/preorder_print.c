//preorder_print.c
//printing a binary tree in a pre order way

typedef struct arvbin{
  int info;
  struct arvbin *esq, *dir;
}TAB;

//recursion way

void TAB_pre_print(TAB *a){
  if(!a) return;
  printf("%d", a->info);
  TAB_pre_print(a->esq);
  TAB_pre_print(a->dir);
}

//stack way

void TAB_pre_print(TAB*a){
  if(!a) return;
  TP *p = TP_cria();
  TP_push(p,a);
  while(!TP_vazia(p)){
    TAB *aux = TP_pop(p);
    printf("%d", aux->info);
    if(aux->dir) TP_push(p, aux->dir);
    if(aux->esq) Tp_push(p, aux->esq);
  }
  TP_libera(p);
}
