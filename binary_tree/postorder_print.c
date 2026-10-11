//postorder_print.c
//printing a binary tree in a post order way

#include <stdio.h>
#include <stdlib.h>

typedef struct arvbin{
  int info;
  struct arvbin *esq, *dir;
}TAB;


void TAB_post_print(TAB *a){
  if(!a) return;
  TAB_post_print(a->esq);
  TAB_post_print(a->dir);
  printf("%d", a->info);
}
