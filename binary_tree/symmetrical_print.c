//symmetrical_print.c
//printing a binary tree in a symmetrical way

typedef struct arvbin{
  int info;
  struct arvbin *esq, *dir;
}TAB;

//recursion way

void TAB_sy_print(TAB *a){
  if(!a) return;
  TAB_sy_print(a->esq);
  printf("%d", a->info);
  TAB_sy_print(a->dir);
}
