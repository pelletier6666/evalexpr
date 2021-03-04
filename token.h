#ifndef TOKEN_H
#define TOKEN_H

#include <stddef.h>
#include <stdio.h>

struct token
{
    enum type type;
    int value;
};

enum type
{
    ADD = 0,
    MIN = 1,
    MUL = 2,
    DIV = 3,
    MOD = 4,
    POW = 5,
    OPEN_PAR = 6,
    CLOSE_PAR = 7,
    NUM = 8
};

struct token *token_create(enum type type, int value);
void token_print(struct token *t);

#endif /* TOKEN_H */
