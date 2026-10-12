//printing_btree.c
//implementing a function that prints the elements of a B Tree

typedef struct arvb{
  int nchaves;  
  int *chaves;  
  int folha;  
  struct arvb **filho;  
}TARVB;

void TARVB_print(TARVB *a){
  if(!a) return;
  int i;
  for( i=0 ; i<a->nchaves ; i++){
    TARVB_print(a->filho[i]);
    printf("%d", a->chave[i]);
  }
  TARVB_print(a->filho[i]);
}
