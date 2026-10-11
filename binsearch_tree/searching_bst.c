//searching_bst.c
//searching for an element in a binary search tree (bst)

#include <stdio.h>
#include <stdlib.h>

typedef struct arvbinbusca{
  int info;
  struct arvbinbusca *esq, *dir;
}TABB;

TABB *TABB_search(TABB *a, int x){
  if((!a) || (a->info == x )) return a;
  if(a->info > x) return TABB_search(a->esq, x);
  return TABB_search(a->dir, x);
}
  
