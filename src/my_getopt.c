#include <stdlib.h>
#include "my_string.h"
#include "my_getopt.h"

#define FORWARD_TOKEN(ARGV, ARGC, IDX) \
(is_last_arg(IDX, ARGC) ? (NULL) : (ARGV[IDX + 1]))

struct opt *build_opt(char *base, char *oper, enum traversal_type print_format, char lexer_flag, char help_flag)
{
    struct opt *option = calloc(1, sizeof(struct opt));
    if (option == NULL)
        return NULL;
    option->b = base;
    option->o = oper;
    option->p = print_format;
    option->l = lexer_flag;
    option->h = help_flag;
    return option;
}

enum traversal_type get_traversal_type(char *opt_value)
{
    if (my_strcmp(opt_value, "prefix") == 0)
        return prefix;
    else if (my_strcmp(opt_value, "suffix") == 0)
        return suffix;
    else if (my_strcmp(opt_value, "infix") == 0)
        return infix;
    else
        return none;
}

void set_option_field(struct opt *option, char opt_flag, char *opt_value)
{
    switch (opt_flag)
    {
        case 'b':
            option->b = opt_value;
            break;
        case 'o':
            option->o = opt_value;
            break;
        case 'p':
            option->p = get_traversal_type(opt_value);
            break;
        case 'l':
            option->l = 1;
            break;
        case 'h':
            option->h = 1;
            break;
    }
}

struct opt *my_getopt(int argc, char **argv, int *error)
{
    int idx = 0;
    struct opt *option = build_opt("0123456789", "+-*/%^()", none, 0, 0);
    if (option == NULL)
        return set_error_code(error, option);

    while (idx < argc)
    {
        if (is_valid_argv(argc, argv, idx) 
            && is_valid_opt_value(argv[idx][1], FORWARD_TOKEN(argv, argc, idx)))
        {
            set_option_field(option, argv[idx][1], FORWARD_TOKEN(argv, argc, idx));
        }


        else
        {
            return set_error_code(error, option);
        }
        idx += (is_long_opt(argv[idx])) ? 2 : 1;
    }
    return option;
}
