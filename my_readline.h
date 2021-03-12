#ifndef MY_READLINE_H
#define MY_READLINE_H

#include <stdio.h>
#include <stdlib.h>

ssize_t my_fgets(char *str, size_t len_to_read, FILE *stream);
char *my_readline_from_stream(FILE *stream);
int close_and_erase_file_stream(FILE *stream, char *filename);
char *my_readline(void);

#endif
