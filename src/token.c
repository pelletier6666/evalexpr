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
    token_print_stream(stdout, t);
}

void token_print_stream(FILE *stream, struct token *t)
{
    if (t == NULL)
        return;
    switch (t->type)
    {
    case ADD:
        fprintf(stream, "ADD");
        break;
    case MIN:
        fprintf(stream, "MIN");
        break;
    case MUL:
        fprintf(stream, "MUL");
        break;
    case DIV:
        fprintf(stream, "DIV");
        break;
    case MOD:
        fprintf(stream, "MOD");
        break;
    case POW:
        fprintf(stream, "POW");
        break;
    case OPEN_PAR:
        fprintf(stream, "(");
        break;
    case CLOSE_PAR:
        fprintf(stream, ")");
        break;
    case NUM:
        fprintf(stream, "%d", t->value);
        break;
    }
}











