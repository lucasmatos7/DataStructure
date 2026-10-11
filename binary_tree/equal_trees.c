//equal_trees.c
//function that checks if two binary trees are equal

#include <stdio.h>
#include <stdlib.h>

typedef struct arvbin{
  int info;
  struct arvbin *esq, *dir;
}TAB;

int equal(TAB *a1, TAB *a2){
  if((!a1) && (!a2)) return 1;
  if((!a1) || (!a2)) return 0;
  if(a1->info != a2->info) return 0;
  return equal(a1->esq, a2->esq) && equal(a1->dir, a2->dir);
}
