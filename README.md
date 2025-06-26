# Projeto de Analisador e Avaliador de Expressões Matemáticas

## 📘 Descrição

Este projeto foi desenvolvido no âmbito da disciplina de **Programação Imperativa**, com o objetivo de criar um programa capaz de **analisar, validar e avaliar expressões matemáticas** contendo operadores básicos, números e parênteses.

As expressões são lidas de um arquivo de entrada (`in.txt`) e os resultados ou mensagens de erro são gravados em `output/out.txt`.

---

## 📁 Estrutura do Projeto

```
.
├── api_user_solution/
│   ├── main.c
│   ├── lexer.c / lexer.h
│   ├── parser.c / parser.h
│   └── evaluator.c / evaluator.h
├── Fila.c / Fila.h
├── Pilha.c / Pilha.h
├── Pilha_int.c / Pilha_int.h
├── Token.h
├── dstlib_include.h
└── output/
    ├── in.txt
    └── out.txt
```

---

## ⚙️ Compilação

A compilação deve ser feita **dentro da pasta `api_user_solution`** com o seguinte comando obrigatório:

```bash
gcc -o analisador main.c -lm
```

> Obs: Os arquivos `.c` de apoio são incluídos diretamente no `main.c` com `#include "../X.c"`.

---

## ▶️ Execução

Execute o programa passando como argumento o arquivo de entrada:

```bash
./analisador in.txt
```

O resultado será gerado automaticamente em:

```
../output/out.txt
```

---

## ✅ Funcionalidades

- Tokenização da expressão
- Validação sintática (estrutura correta, parênteses, operadores)
- Conversão de notação infixa para posfixa
- Avaliação da expressão usando pilhas
- Detecção e tratamento dos seguintes erros:
  - Divisão por zero
  - Parênteses desbalanceados
  - Caracteres inválidos
  - Expressões malformadas

---



---

