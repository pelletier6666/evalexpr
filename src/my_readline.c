#include "my_string.h"
#include "my_readline.h"
#include "my_string.h"

ssize_t my_fgets(char *str, size_t len_to_read, FILE *stream)
{
    str = fgets(str, len_to_read, stream);
    if (str == NULL)
        return -1;
    size_t i = 0;
    while (str[i] != '\0' && str[i] != '\n')
        i++;
    if (str[i] == '\n')
        str[i] = '\0';
    return i;
}

char *my_readline(void)
{
    return my_readline_from_stream(stdin);
}
char *my_readline_from_stream(FILE *stream)
{
    size_t to_read = 8;
    ssize_t read_char = 0;
    size_t content_size = 0;

    char *content = calloc(to_read, sizeof(char));

    while ((read_char = my_fgets(content + content_size, to_read, stream)) != -1)
    {
        content_size += read_char;
        content = realloc(content, ((content_size + to_read) * sizeof(char)));
    }
    return content;
}
