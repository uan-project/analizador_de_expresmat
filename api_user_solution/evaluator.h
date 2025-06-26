#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "../Token.h"

#include "../Fila.h"

void infixa_para_posfixa(Token tokens[], int n, Fila *saida);
int avaliar_posfixa(Fila *posfixa, int *resultado);

#endif