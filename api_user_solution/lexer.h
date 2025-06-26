#ifndef LEXER_H
#define LEXER_H

#include "../Token.h"


int tokenizar(const char *expr, Token tokens[], int *n);

#endif