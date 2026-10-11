//rl_rotation_avl.c
//code of right-left rotation (or better known as Double Left Rotation) in the avl tree

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct avl{
  int info;
  struct avl *esq, *dir;
  int alt;
}TAVL;

TAVL *RR(TAVL *a){
  TAVL *newnode = a->dir;
  a->dir = newnode->esq;
  newnode->esq = a;
  //update the height field (alt)
  return newnode;
}

TAVL *RL(TAVL *a){
  a->dir = RR(a->dir);
  return RR(a);
}
