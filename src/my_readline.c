#include "my_readline.h"

char *my_fgets(char *str, size_t len_to_read, FILE *stream)
{
    if (str == NULL)
        return NULL;
    str = fgets(str, len_to_read, stream);
    if (str == NULL)
        return NULL;
    size_t i = 0;
    while (str[i] != '\0' && str[i] != '\n')
        i++;
    if (str[i] == '\n')
    {
        str[i] = '\0';
        return NULL;
    }
    return (str[i] == '\0') ? str + i : NULL;

}

char *my_readline(void)
{
    return my_readline_from_stream(stdin);
}
char *my_readline_from_stream(FILE *stream)
{
    size_t len_line = 8;
    char *line_ptr = calloc(len_line + 1, sizeof(char));
    char *end_line_ptr = line_ptr;

    end_line_ptr = my_fgets(end_line_ptr, len_line, stream);

    while (end_line_ptr != NULL)
    {
        len_line += 8;
        line_ptr = realloc(line_ptr, len_line * sizeof(char));
        end_line_ptr = my_fgets(end_line_ptr, 9, stream);
    }
    return line_ptr;
}
