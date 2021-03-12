#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include "my_string.h"
#include "queue.h"
#include "my_getopt.h"
#include "my_atoi_itoa_base.h"

int is_belong_to(char c, char *char_collection);
void *handle_error(int *error, int error_code, struct queue *q);
int get_token_type(const char *line, struct opt *options);
int skip_and_get_token_value(const char **line, enum type token_type, char *base);
struct queue *lexer(const char *line, struct opt *options, int *error);

#endif /* LEXER_H */
