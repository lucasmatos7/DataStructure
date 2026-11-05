//printing_bfile.c
//function to print data structures in binary files using C language

#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    int mat;
    float cr;
}TA;

void printing(char *nome){
    FILE *fp = fopen(nome, "rb");
    if (!fp) exit(1);
    TA aux;
    while(fread(&aux, sizeof(TA), 1, fp) == 1) printf("mat = %d | cr = %.2f\n", aux.mat, aux.cr);
    fclose(fp);
}
