//removing_bst.c
//function to remove element(s) of a binary search tree (bst)

typedef struct arvbinbusca{
  int info;
  struct arvbinbusca *esq, *dir;
}TABB;

TABB *TABB_remove(TABB*a, int x){
  if(!a) return a;
  if(a->info > x) a->esq = TABB_remove(a->esq, x);
  else if(a->info < x) a->dir = TABB_remove(a->dir, x);
  else{
    if((!a->esq) && (!a->dir)){
      free(a);
      a = NULL;
    }
    else if((!a->esq) || (!a->dir)){
      TABB *temp = a;
      if(a->esq) a = a->esq;
      else a= a->dir;
      free(temp);
    }
    else{
      TABB *f = a->esq;
      while(f->dir) f = f->dir;
      a->info = f->info;
      f->info = x;
      a->esq = TABB_remove(a->esq, x);
    }
  }
  return a;
}
