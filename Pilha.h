#ifndef PILHA_H
#define PILHA_H

#include "Token.h"

typedef struct no {
    Token token;
    struct no* prox;
} No;

typedef struct {
    No* topo;
} Pilha;

void initPilha(Pilha* P);
No* getNOPilha(Token tk);
int vaziaPilha(Pilha* P);
int push(Pilha* P, Token tk);
int pop(Pilha* P);
Token top(Pilha* P);

#endif // PILHA_H
