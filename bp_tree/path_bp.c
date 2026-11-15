//path_bp.c
//function that returns in a string the path traveled to find the expected element

typedef struct arvbm{
  int nchaves, folha, *chave;
  struct arvbm **filho, *prox;
}TARVBM;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* caminho_aux(TARVBM *a, int x, char *resposta, int *pos) {
    int i = 0;

    if (!a)
        return "nao encontrado";

    while (i < a->nchaves && x > a->chave[i])
        i++;

    if (a->folha) {
        if (i < a->nchaves && x == a->chave[i])
            return resposta;

        return "nao encontrado";
    }

    if (i < a->nchaves && a->chave[i] == x)
        i++;

    *pos += sprintf(resposta + *pos, "%d", i);

    return caminho_aux(a->filho[i], x, resposta, pos);
}

char* caminho(TARVBM *a, int x) {
    if (!a)
        return "arvore esta vazia";

    char *resposta = malloc(100 * sizeof(char));

    if (!resposta)
        return NULL;

    resposta[0] = '\0';

    int pos = 0;

    char *resultado = caminho_aux(a, x, resposta, &pos);

    if (resultado != resposta) {
        free(resposta);
        return resultado;
    }

    return resposta;
}
