// Fila.h (CORRIGIDO)
#ifndef FILA_H
#define FILA_H

#include "Token.h"

typedef struct nof {
  Token token;
  struct nof *prox;
} NO;

typedef struct {
  NO *ini;
  NO *fim;
} Fila;

void initFila(Fila *F);
int vaziaFila(Fila *F);
NO *getNOFila(Token tk);
int inserir(Fila *F, Token tk);
int remover(Fila *F);
Token frente(Fila *F);

#endif
