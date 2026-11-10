//cr_changer.c
//function that checks if we the student is active and when his registration is found we update his general grades using binary file manipulation

#include <stdio.h>

typedef struct aluno {
    int mat;
    int prox;
    int status;
    float cr;
} TA;

int altera_cr(char *nome, int matricula, float novo_cr){
    FILE *fp = fopen(nome, "rb+");
    if(!fp) return -1;
    
    int alterado = 0;
    TA aux;

    while (1) {
    int pos = ftell(fp);

    if (fread(&aux, sizeof(TA), 1, fp) != 1)
        break;

    if (aux.mat == matricula && aux.status == 1) {
        aux.cr = novo_cr;

        fseek(fp, pos, SEEK_SET);
        fwrite(&aux, sizeof(TA), 1, fp);

        fclose(fp);
        return 1;
    }
}

fclose(fp);
return 0;
}
