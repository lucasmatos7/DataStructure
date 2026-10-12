//mirror_btree.c
//implementing function that creates a mirror tree of a B Tree

typedef struct arvb{
  int nchaves;  
  int *chaves;  
  int folha;  
  struct arvb **filho;  
}TARVB;

TARVB* mirror(TARVB*a, int t){
  if(!a) return a;
  TARVB* newel = TARVB_create(t);
  newel->nchaves = a->nchaves;
  newel->folha = a->folha;
  int i = 0;

  for(i = 0; i < a->nchaves; i++){
    newel->chave[i] = a->chave[a->nchaves - 1 - i];
  }

  if(!a->folha){
    for(i = 0; i <= a->nchaves; i++){
      newel->filho[i] = mirror(a->filho[a->nchaves - i], t);
    }
  }
  return newel;
}
