#include "my_getopt_utils.h"
#include "my_string.h"
#include <stdio.h>
#include <stdlib.h>

struct opt *set_error_code(int *error, struct opt *option)
{
    *error = 4;
    if (option != NULL)
        free(option);
    return NULL;
}

int is_long_opt(char *option_flag)
{
    return (option_flag[1] == 'b' || option_flag[1] == 'o' || option_flag[1] == 'p');
}

int is_last_arg(int idx, int argc)
{
    return (idx == argc - 1);
}

int is_valid_argv(int argc, char **argv, int idx)
{
    if (my_strlen(argv[idx]) != 2 || (is_long_opt(argv[idx]) && is_last_arg(idx, argc)))
        return 0;
    else
        return 1;
}
int is_valid_opt_value(char opt_flag, char *opt_value)
{
    if (opt_flag == 'b')
    {
        return (my_strlen(opt_value) >= 2);
    }
    if (opt_flag == 'o')
    {
        return (my_strlen(opt_value) == 8);
    }
    if (opt_flag == 'p')
    {
        return (my_strcmp(opt_value, "prefix") == 0
                || my_strcmp(opt_value, "suffix") == 0
                || my_strcmp(opt_value, "infix") == 0);
    }
    if (opt_flag == 'l' || opt_flag == 'h')
    {
        return 1;
    }
    return 0;
}
