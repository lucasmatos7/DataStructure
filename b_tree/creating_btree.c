//creating_btree.c
//implementing a function that creates a node in a B Tree

typedef struct arvb{
  int nchaves;  
  int *chaves;  
  int folha;  
  struct arvb **filho;  
}TARVB;

TARVB *TARVB_create(int t){
  TARVB *a = (TARVB*) malloc (sizeof(TARVB));
  a->folha = 1;
  a->nchaves = 0;
  a-chave = (int*) malloc (sizeof(int) * (2 *(t-1)));
  a->filho = (TARVB**) malloc (sizeof(TARVB*) * (2*t));
  int i, tam = 2*t;
  for( i=0; i<tam; i++) a->filho[i] = NULL;
  return a;
}
