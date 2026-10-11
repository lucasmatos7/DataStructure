//sortedgreater_bst.c
//implementing a function that find the elements greater than N and return them in a sorted array without using sort algorithms

#include <stdio.h>
#include <stdlib.h>

typedef struct arvbinbusca{
  int info;
  struct arvbinbusca *esq, *dir;
} TABB;

int count_greater(TABB *a, int N){
  if(!a) return 0;
  if(a->info <= N) return count_greater(a->dir, N);
  return 1 + count_greater(a->esq, N) + count_greater(a->dir, N);
}

void filling(TABB *a, int *vet, int *ind, int N){
  if(!a) return;
  if(a->info <= N){
    filling(a->dir, vet, ind, N);
  } else {
    filling(a->esq, vet, ind, N);
    vet[*ind] = a->info;
    (*ind)++;
    filling(a->dir, vet, ind, N);
  }
}

int *greaterN(TABB *a, int N){
  if(!a) return NULL;
  
  int i = count_greater(a, N);
  if (i == 0) return NULL;
  
  int *vet = (int*) malloc(sizeof(int) * i);
  if (!vet) return NULL; 
  
  int ind = 0;
  filling(a, vet, &ind, N);
  
  return vet;
}
