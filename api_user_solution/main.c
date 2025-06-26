#include "../Token.h"
#include "../dstlib_include.h"
#include "lexer.h"
#include "parser.h"
#include "evaluator.h"


int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <arquivo_entrada>\n", argv[0]);
        return 1;
    }

    FILE *fin = fopen(argv[1], "r");
    if (!fin) {
        printf("Erro ao abrir %s\n", argv[1]);
        return 1;
    }

    FILE *fout = fopen("../output/out.txt", "w");
    if (!fout) {
        printf("Erro ao criar arquivo de saída.\n");
        fclose(fin);
        return 1;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), fin)) {
        linha[strcspn(linha, "\n")] = 0;

        Token tokens[100];
        int n;
        char erro_msg[100] = "";

        if (!tokenizar(linha, tokens, &n)) {
            fprintf(fout, "Erro: Caracteres invalidos\n");
            continue;
        }

        if (!sintaxe_valida(tokens, n, erro_msg)) {
            fprintf(fout, "%s\n", erro_msg);
            continue;
        }

        Fila posfixa;
        initFila(&posfixa);
        infixa_para_posfixa(tokens, n, &posfixa);

        int resultado;
        int status = avaliar_posfixa(&posfixa, &resultado);
        if (status == INT_MIN) {
            fprintf(fout, "Erro: Divisao por zero\n");
        } else if (!status) {
            fprintf(fout, "Erro: Expressao malformada\n");
        } else {
            fprintf(fout, "%d\n", resultado);
        }
    }

    fclose(fin);
    fclose(fout);
    return 0;
}


#include "lexer.c"
#include "parser.c"
#include "evaluator.c"
#include "../Fila.c"
#include "../Pilha.c"
#include "../Pilha_int.c"



