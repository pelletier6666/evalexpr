#ifndef MY_STRING_H
#define MY_STRING_H

#include <stddef.h>

size_t my_strlen(const char *s);
int my_strcmp(const char *s1, const char *s2);
char *my_strdup(const char *s);
char *my_strndup(const char *s, size_t n);
char *my_strcat(char *dest, const char *src);

#endif
