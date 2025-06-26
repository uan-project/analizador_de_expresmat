#include "Pilha.h"
#include <stdlib.h>

void initPilha(Pilha *P) {
    P->topo = NULL;
}

int vaziaPilha(Pilha *P) {
    return P->topo == NULL;
}

No *getNOPilha(Token tk) {
    No *novo = (No*) malloc(sizeof(No));
    novo->token = tk;
    novo->prox = NULL;
    return novo;
}

int push(Pilha *P, Token tk) {
    No *novo = getNOPilha(tk);
    if (!novo) return 0;
    novo->prox = P->topo;
    P->topo = novo;
    return 1;
}

int pop(Pilha *P) {
    if (vaziaPilha(P)) return 0;
    No *tmp = P->topo;
    P->topo = tmp->prox;
    free(tmp);
    return 1;
}

Token top(Pilha *P) {
    if (vaziaPilha(P)) {
        Token vazio = {'\0', NONE, -1};
        return vazio;
    }
    return P->topo->token;
}
