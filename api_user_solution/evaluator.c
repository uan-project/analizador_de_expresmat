#include "../dstlib_include.h"
#include "evaluator.h"
#include "../Pilha.h"
#include "../Pilha_int.h"

void infixa_para_posfixa(Token tokens[], int n, Fila *saida) {
    Pilha operadores;
    initPilha(&operadores);

    for (int i = 0; i < n; i++) {
        Token tk = tokens[i];

        if (tk.type == NUMERO) {
            inserir(saida, tk);
        } else if (tk.type == OPERADOR) {
            while (!vaziaPilha(&operadores) &&
                   top(&operadores).type == OPERADOR &&
                   top(&operadores).peso >= tk.peso) {
                inserir(saida, top(&operadores));
                pop(&operadores);
            }
            push(&operadores, tk);
        } else if (tk.value == '(') {
            push(&operadores, tk);
        } else if (tk.value == ')') {
            while (!vaziaPilha(&operadores) && top(&operadores).value != '(') {
                inserir(saida, top(&operadores));
                pop(&operadores);
            }
            if (!vaziaPilha(&operadores)) pop(&operadores);
        }
    }

    while (!vaziaPilha(&operadores)) {
        inserir(saida, top(&operadores));
        pop(&operadores);
    }
}

int avaliar_posfixa(Fila *posfixa, int *resultado) {
    Pilha_int numeros;
    initPilhaInt(&numeros);

    while (!vaziaFila(posfixa)) {
        Token tk = frente(posfixa);
        remover(posfixa);

        if (tk.type == NUMERO) {
            int valor = tk.value - '0';
            push_int(&numeros, valor);
        } else if (tk.type == OPERADOR) {
            if (vaziaPilhaInt(&numeros)) return 0;
            int b = top_int(&numeros); pop_int(&numeros);
            if (vaziaPilhaInt(&numeros)) return 0;
            int a = top_int(&numeros); pop_int(&numeros);

            int res = 0;
            switch (tk.value) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': if (b == 0) return INT_MIN; res = a / b; break;
                case '%': if (b == 0) return INT_MIN; res = a % b; break;
                case '^': res = 1; for (int i = 0; i < b; i++) res *= a; break;
                default: return 0;
            }
            push_int(&numeros, res);
        }
    }

    if (vaziaPilhaInt(&numeros)) return 0;
    *resultado = top_int(&numeros);
    return 1;
}