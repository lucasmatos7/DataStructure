//searching_btree.c
//function to search for an element in a B Tree

typedef struct arvb{
  int nchaves;  //number of keys in the node
  int *chaves;  //which key of the node it is
  int folha;  //checks if the node is a leaf
  struct arvb **filho;  //which son of the node it is
}TARVB;

TARVB *TARVB_search(TARVB *a, int x){
  if(!a) return a;
  int i = 0;
  while((i < a->nchaves) && (a->chave[i] < x)) i++;
  if((i < a->nchaves) && (a->chave[i] == x)) return a;
  return TARVB_search(a->filho[i], x);
}

  
