#include "../dstlib_include.h"
#include "lexer.h"

int tokenizar(const char *expr, Token tokens[], int *n) {
    int i = 0, j = 0;
    while (expr[i] != '\0') {
        char c = expr[i];

        if (isspace(c)) {
            i++;
            continue;
        }

        if (isdigit(c)) {
            tokens[j].value = c;
            tokens[j].type = NUMERO;
            tokens[j].peso = 3;
        } else if (c == '+' || c == '-') {
            tokens[j].value = c;
            tokens[j].type = OPERADOR;
            tokens[j].peso = 1;
        } else if (c == '*' || c == '/' || c == '%') {
            tokens[j].value = c;
            tokens[j].type = OPERADOR;
            tokens[j].peso = 2;
        } else if (c == '^') {
            tokens[j].value = c;
            tokens[j].type = OPERADOR;
            tokens[j].peso = 4;
        } else if (c == '(' || c == ')') {
            tokens[j].value = c;
            tokens[j].type = PARENTESES;
            tokens[j].peso = 0;
        } else {
            return 0;
        }

        j++;
        i++;
    }

    *n = j;
    return 1;
}