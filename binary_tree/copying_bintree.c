//copying_bintree.c
//creating a binary tree that is a copy of another binary tree

typedef struct arvbin{
  int info;
  struct arvbin *esq, *dir;
}TAB;

TAB* TAB_copy(TAB *a){
  if(!a) return a;
  TAB *newelem = (TAB*) malloc (sizeof(TAB));
  newelem->info = a->info;
  newelem->esq = TAB_copy(a->esq);
  newelem->dir = TAB_copy(a->dir);
  return newelem;
}
