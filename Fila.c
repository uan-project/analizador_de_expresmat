#include "Fila.h"
#include <stdlib.h>

void initFila(Fila *F) {
    F->ini = NULL;
    F->fim = NULL;
}

int vaziaFila(Fila *F) {
    return F->ini == NULL;
}

NO *getNOFila(Token tk) {
    NO *novo = (NO*) malloc(sizeof(NO));
    novo->token = tk;
    novo->prox = NULL;
    return novo;
}

int inserir(Fila *F, Token tk) {
    NO *novo = getNOFila(tk);
    if (F->fim)
        F->fim->prox = novo;
    else
        F->ini = novo;
    F->fim = novo;
    return 1;
}

int remover(Fila *F) {
    if (vaziaFila(F)) return 0;
    NO *tmp = F->ini;
    F->ini = tmp->prox;
    if (F->ini == NULL) F->fim = NULL;
    free(tmp);
    return 1;
}

Token frente(Fila *F) {
    if (!vaziaFila(F)) return F->ini->token;
    Token vazio = {'\0', NONE, -1};
    return vazio;
}
