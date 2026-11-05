//active_clients.c
//function to check if the student is still active (checking his status) 

#include <stdio.h>

typedef struct aluno {
    int mat;
    int prox;
    int status;
    float cr;
} TA;

int active_clients(char *nome){
    FILE *fp = fopen(nome, "rb");
    if(!fp) return -1;
    int actives = 0;
    TA aux;
    while((fread(&aux, sizeof(TA), 1, fp) == 1)){
        if(aux.status==1) actives++;
    }
    fclose(fp);
    return actives;
}
