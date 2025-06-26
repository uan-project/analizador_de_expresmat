#include <string.h>
#include "parser.h"
#include "../Pilha_int.h"

int sintaxe_valida(Token tokens[], int n, char *erro) {
    Pilha_int parenteses;
    initPilhaInt(&parenteses);

    for (int i = 0; i < n; i++) {
        Token atual = tokens[i];
        Token anterior = i > 0 ? tokens[i - 1] : (Token){'n', NONE, -1};

        if (atual.type == PARENTESES) {
            if (atual.value == '(') {
                push_int(&parenteses, 1);
            } else {
                if (vaziaPilhaInt(&parenteses)) {
                    strcpy(erro, "Erro: Parenteses desbalanceados");
                    return 0;
                }
                pop_int(&parenteses);
            }
        }

        // Casos que configuram expressão malformada:
        if (atual.type == OPERADOR && anterior.type == OPERADOR) {
            strcpy(erro, "Erro: Expressao malformada");
            return 0;
        }

        if (atual.type == NUMERO && anterior.type == NUMERO) {
            strcpy(erro, "Erro: Expressao malformada");
            return 0;
        }

        if (atual.value == '(' && anterior.type == NUMERO) {
            strcpy(erro, "Erro: Expressao malformada");
            return 0;
        }

        if (anterior.value == ')' && atual.type == NUMERO) {
            strcpy(erro, "Erro: Expressao malformada");
            return 0;
        }

        if ((i == 0 || i == n - 1) && atual.type == OPERADOR) {
            strcpy(erro, "Erro: Expressao malformada");
            return 0;
        }
    }

    if (!vaziaPilhaInt(&parenteses)) {
        strcpy(erro, "Erro: Parenteses desbalanceados");
        return 0;
    }

    return 1;
}