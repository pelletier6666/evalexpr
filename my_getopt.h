#ifndef MY_GETOPT_H
#define MY_GETOPT_H

#include "my_getopt_utils.h"

struct opt *my_getopt(int argc, char **argv, int *error);

void set_option_field(struct opt *option, char opt_flag, char *opt_value);

enum traversal_type get_traversal_type(char *opt_value);

struct opt *build_opt(char *base, char *oper, enum traversal_type print_format, char lexer_flag, char help_flag);

#endif /* MY_GETOPT_H */
