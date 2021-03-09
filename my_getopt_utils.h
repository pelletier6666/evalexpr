#ifndef MY_GETOPT_UTILS_H
#define MY_GETOPT_UTILS_H

#include <stddef.h>

enum traversal_type 
{
    none,
    prefix,
    infix,
    suffix
};

struct opt
{
    char *b;
    char *o;
    enum traversal_type p;
    char l;
    char h;
};


struct opt *set_error_code(int *error, struct opt *option);
int is_last_arg(int idx, int argc);
int is_valid_argv(int argc, char **argv, int idx);
int is_long_opt(char *option_flag);
int is_valid_opt_value(char opt_flag, char *opt_value);

#endif /* MY_GETOPT_UTILS_H */
