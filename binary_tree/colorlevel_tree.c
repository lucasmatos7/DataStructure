//colorlevel_tree.c
//implementing function that colors a binary tree w/ 2 colors (alternating according to the level)

#include <stdio.h>
#include <stdlib.h>

typedef struct arvbin{
  int info;
  int color;
  struct arvbin *esq, *dir;
}TAB;

void colors_aux(TAB *a, int color){
  if(!a) return;
  a->color = color;
  colors_aux(a->esq, !color);
  colors_aux(a->dir, !color);
}

void colors(TAB *a){
  if(!a) return;
  a->color = 0;
  colors_aux(a->esq, 1);
  colors_aux(a->dir, 1);
}
