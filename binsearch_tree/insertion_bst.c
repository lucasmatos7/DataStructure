//insertion_bst.c
//function to insert new element(s) in a binary search tree (bst)

#include <stdio.h>
#include <stdlib.h>

typedef struct arvbinbusca{
  int info;
  struct arvbinbusca *esq, *dir;
}TABB;

TABB *TABB_insert(TABB *a, int x){
  if(!a) return a;
  if(a->info > x) a->esq = TABB_insert(a->esq, x);
  else if(a->info < x) a->dir = TABB_insert(a->dir, x);
  return a;
}

