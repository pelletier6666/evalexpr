#include "lexer.h"


void *handle_error(int *error, int error_code, struct queue *q)
{
    *error = error_code;
    queue_destroy(q);
    return NULL;
}

int is_belong_to(char c, char *char_collection)
{
    size_t len_collection = my_strlen(char_collection);

    for (size_t i = 0; i < len_collection; i++)
    {
        if (char_collection[i] == c)
            return 1;
    }
    return 0;
}

int get_token_type(const char *line, struct opt *options)
{
    if (is_belong_to(*line, options->b))
        return NUM;
    if (*line == options->o[0])
        return ADD;
    else if (*line == options->o[1])
        return MIN;
    else if (*line == options->o[2])
        return MUL;
    else if (*line == options->o[3])
        return DIV;
    else if (*line == options->o[4])
        return MOD;
    else if (*line == options->o[5])
        return POW;
    else if (*line == options->o[6])
        return OPEN_PAR;
    else if (*line == options->o[7])
        return CLOSE_PAR;
    else
        return -1;
}

int skip_token(const char **line, enum type token_type, char *base)
{
    if (token_type != NUM)
    {
        line++;
        return 0;
    }
    size_t len_num = 0;
    while (is_belong_to(*(*line++), base))
        len_num++;
    char *num = my_strndup(*line, len_num);
    int token_value = my_atoi_base(num, base);

    line += len_num;
    free(num);
    return token_value;
}

struct queue *lexer(const char *line, struct opt *options, int *error)
{
    struct queue *q = queue_init();
    if (q == NULL)
        return handle_error(error, 4, q);

    while (*line != '\0')
    {

        struct token *token = NULL;

        int token_type = get_token_type(line, options);
        int token_value = skip_token(&line, token_type, options->b);
        
        if (token_type == -1 || token_value == -1)
            return handle_error(error, 1, q);

        token = token_create(token_type, token_value);

        if (queue_push(q, token) == 0)
            return handle_error(error, 4, q);
    }
    return q;
}
