#ifndef TOKEN_H
#define TOKEN_H

#define MAX 100

enum tokenType{
  NUMERO,
  PARENTESES,
  OPERADOR,
  NONE
};

typedef struct {
  char value;
  enum tokenType type;
  int peso;
}Token;

#endif