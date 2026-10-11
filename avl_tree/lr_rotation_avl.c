//lr_rotation_avl.c
//code of left-right rotation (or better known as Double Right Rotation) in the avl tree

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

TAVL *LR(TAVL *a){
  a->esq = LR(a->esq);
  return LL(a);
}
