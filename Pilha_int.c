#include "Pilha_int.h"
#include <stdlib.h>

void initPilhaInt(Pilha_int *P) {
    P->topo = NULL;
}

int vaziaPilhaInt(Pilha_int *P) {
    return P->topo == NULL;
}

Node *getNOPilhaInt(int n) {
    Node *novo = (Node*) malloc(sizeof(Node));
    novo->valor = n;
    novo->prox = NULL;
    return novo;
}

int push_int(Pilha_int *P, int n) {
    Node *novo = getNOPilhaInt(n);
    if (!novo) return 0;
    novo->prox = P->topo;
    P->topo = novo;
    return 1;
}

int pop_int(Pilha_int *P) {
    if (vaziaPilhaInt(P)) return 0;
    Node *tmp = P->topo;
    P->topo = tmp->prox;
    free(tmp);
    return 1;
}

int top_int(Pilha_int *P) {
    if (vaziaPilhaInt(P)) return -1;
    return P->topo->valor;
}
