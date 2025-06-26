#ifndef PARSER_H
#define PARSER_H

#include "../Token.h"


// Retorna 1 se válido, 0 se inválido e escreve mensagem de erro em 'erro'
int sintaxe_valida(Token tokens[], int n, char *erro);

#endif