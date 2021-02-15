#include "my_readline.h"

char *my_fgets(char *str, size_t len_to_read, FILE *stream)
{
    if (str == NULL)
        return NULL;
    fgets(str, len_to_read, stream);
    size_t i = 0;
    while (str[i] != '\0' && str[i] != '\n')
        i++;
    return (str[i] == '\0') ? str + i : NULL;

}

char *my_readline(void)
{
    return my_readline_with_stream(stdin);
}
char *my_readline_with_stream(FILE *stream)
{
    size_t len_line = 8;
    char *line_ptr = calloc(len_line, sizeof(char));
    char *read_stream_pos = line_ptr;

    read_stream_pos = my_fgets(read_stream_pos, len_line, stream);

    char *new_line_ptr = NULL;
    while (read_stream_pos != NULL)
    {
        len_line += len_line;
        new_line_ptr = realloc(line_ptr, len_line * sizeof(char));
        read_stream_pos = my_fgets(read_stream_pos, len_line, stdin);
    }
    return new_line_ptr;
}
