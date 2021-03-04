#include "token.h"
#include "queue.h"
#include "lexer.h"

int is_belong_to(char c, char *char_collection, size_t len_collection)
{
    for (size_t i = 0; i < len_collection; i++)
    {
        if (char_collection[i] == c)
            return 1;
    }
    return 0;
}

int get_num_value(char **line_ptr, char *base)
{
    char *line = *line_ptr;
}

int get_operator_type(char **line_ptr)
{
    char *line = *line_ptr;
}

struct token *build_num_token(char **line, char *base, size_t len_base, int *error)
{
    struct token *token = calloc(1, sizeof(struct token));
    if (token == NULL)
    {
        *error = 4;
        return NULL;
    }
    token->value = get_num_value(line, option->b);
    token->type = NUM;
    return token;
}

struct token *build_operator_token(char **line, char *operator_symbols, int *error)
{
    struct token *token = calloc(1, sizeof(struct token));
    if (token == NULL)
    {
        *error = 4;
        return NULL;
    }
    token->value = 0;
    token->type = get_operator_type(line);
    return token;
}

struct queue *lexer(const char *line, struct opt *options, int *error)
{
    struct queue *q = queue_init();
    if (q == NULL)
    {
        *error = 4;
        return NULL;
    }
    
    while (*line != '\0')
    {
        struct token *token = NULL;
        if (is_belong_to(*line, options->b, my_strlen(options->b)))
            token = build_num_token(line, options->b, my_strlen(options->b), error); 

        if (is_belong_to(*line, options->o))
            token = build_operator_token(line, options->b, my_strlen(options->b), error); 
        while (is_space(line))
            line++;

        if (queue_push(q, token) == 0)
        {
            *error = 4;
            return NULL;
        }
            
    }
}
