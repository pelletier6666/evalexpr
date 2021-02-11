#include <stdlib.h>
#include "my_string.h"
#include "my_getopt.h"

struct opt *set_error_code(int *error, struct opt *option)
{
    *error = 4;
    free(option);
    return NULL;
}

int is_long_opt(char *option_flag)
{
    if (option_flag[1] == 'b' || option_flag[1] == 'o' || option_flag[1] == 'p')
        return 1;
    return 0;
}


struct opt *my_getopt(int argc, char **argv, int *error)
{
    int idx = 0;
    struct opt *option = calloc(1, sizeof(struct opt));
    option->b = "0123456789";
    option->o = "+-*/%^()";
    if (option == NULL)
        return set_error_code(error, option);

    while (idx < argc)
    {
        if (my_strlen(argv[idx]) != 2)
            return set_error_code(error, option);
        if (is_long_opt(argv[idx]) && idx == argc - 1)
                return set_error_code(error, option);
        switch (argv[idx][1])
        {
            case 'b':
                if (my_strlen(argv[idx + 1]) < 2)
                    return set_error_code(error, option);
                else
                    option->b = argv[idx + 1];
                break;
            case 'o':
                if (my_strlen(argv[idx + 1]) != 8)
                    return set_error_code(error, option);
                else
                    option->o = argv[idx + 1];
                break;
            case 'l':
                option->l = 1;
                break;
            case 'p':
                if (my_strcmp(argv[idx + 1], "prefix") == 0)
                    option->p = prefix;
                else if (my_strcmp(argv[idx + 1], "suffix") == 0)
                    option->p = suffix;
                else if (my_strcmp(argv[idx + 1], "infix") == 0)
                    option->p = infix;
                else
                    return set_error_code(error, option);
                break;
            case 'h':
                option->h = 1;
                break;
            default:
                return set_error_code(error, option);
        }
        idx += (is_long_opt(argv[idx])) ? 2 : 1;
    }
    return option;
}
