//reg_search.c
//function that returns -1 if the file couldn't be opened, 0 if the registration wasn't found or wasn't active and 1 if it was found and was active

#include <stdio.h>

int busca_aluno(char *nome, int matricula) {
    FILE *fp = fopen(nome, "rb");
    if (!fp) return -1;

    TA aux;
    int encontrado = 0;

    while (fread(&aux, sizeof(TA), 1, fp) == 1) {
        if (aux.mat == matricula && aux.status == 1) {
            encontrado = 1;
            break;
        }
    }

    fclose(fp);
    return encontrado;
}
