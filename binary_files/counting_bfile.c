//counting_bfile.c
//function to count how many records were saved in the binary file 

#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    int mat;
    float cr;
}TA;

int counting_records(char *nome){
    FILE *fp = fopen(nome, "rb");
    if (!fp) return -1;
    TA aux;
    int i=0;
    while(fread(&aux, sizeof(TA), 1, fp) == 1) i++;
    fclose(fp);
    return i;
}
