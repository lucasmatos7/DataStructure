//rr_rotation_avl.c
//code of left rotation (or most known as Right-Right Rotation because of the insertion made in the right son of the right son of the node) in the avl tree

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
