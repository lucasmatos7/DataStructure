//searching_bintree.c
//searching for an element in a binary tree

typedef struct arvbin{
  int info;
  struct arvbin *esq, *dir;
}TAB;

TAB *TAB_search(TAB *a, int x){
  if((!a) || (a->info == x)) return a;
  TAB *resp = TAB_search(a->esq, x);
  if(resp) return resp;
  return TAB_search(a->dir, x);
}
