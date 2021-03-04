#include "token.h"

struct token *token_create(enum type type, int value)
{
    struct token *token = calloc(1, sizeof(struct token));
    if (token == NULL)
        return NULL;
    token->type = type;
    token->value = value;
    return token;
}
void token_print(struct token *t)
{
    if (token == NULL)
        return;
    switch (t->type)
    {
    case ADD:
        printf("+");
        break;
    case MIN:
        printf("-");
        break;
    case MUL:
        printf("*");
        break;
    case DIV:
        printf("/");
        break;
    case MOD:
        printf("%");
        break;
    case POW:
        printf("^");
        break;
    case OPEN_PAR:
        printf("(");
        break;
    case CLOSE_PAR:
        printf(")");
        break;
    case NUM:
        printf("%d", t->value);
        break;
    }
}









