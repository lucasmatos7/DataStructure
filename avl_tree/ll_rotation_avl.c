//ll_rotation_avl.c
//code of right rotation (or better known as Left-Left Rotation because of the insertion made in the left son of the left son of the node) in the avl tree

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct avl{
  int info;
  struct avl *esq, *dir;
  int alt;
}TAVL;

TAVL *LL(TAVL *a){
  TAVL *newnode = a->esq;
  a->esq = newnode->dir;
  newnode->dir = a;
  //update the height field (alt)
  return newnode;
}
