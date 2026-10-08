//levelorder_print.c
//printing a binary tree in a level-order traversal

typedef struct arvbin{
  int info;
  struct arvbin *esq, *dir;
}TAB;

//queue structure is necessary for this case

void TAB_levelqueue_print(TAB *a){
  if(!a) return;
  TF *f = TF_cria();
  TF_insere = (f,a);
  while(!TF_vazia(f)){
    TAB *aux =n TF_retira(f);
    printf("%d", aux->info);
    if(aux->esq) TF_insere(f, aux->esq);
    if(aux->dir) TF_insere(f, aux->dir);
  }
  TF_libera(f);
}
