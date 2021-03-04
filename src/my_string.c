#include <stdlib.h>

#include "my_string.h"

size_t my_strlen(const char *s)
{
    size_t i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}
int my_strcmp(const char *s1, const char *s2)
{
    size_t i = 0;
    int res = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    if (s1[i] != s2[i])
        return (s1[i] < s2[i]) ? -1 : 1;
    if (s1[i] == '\0')
        res += -1;
    if (s2[i] == '\0')
        res += 1;
    return res;
}
char *my_strdup(const char *s)
{
    size_t len_s = my_strlen(s);
    char *dup_str = calloc(len_s, sizeof(char));
    if (dup_str == NULL)
        return NULL;
    size_t i = 0;
    while (s[i] != '\0')
    {
        dup_str[i] = s[i];
        i++;
    }
    return dup_str;
}

char *my_strndup(const char *s, size_t n)
{
    char *dup_str = calloc(n + 1, sizeof(char));
    if (dup_str == NULL)
        return NULL;
    size_t i = 0;
    while (s[i] != '\0' && i < n)
    {
        dup_str[i] = s[i];
        i++;
    }
    return dup_str;
}
char *my_strcat(char *dest, const char *src)
{
    size_t idx_dest = my_strlen(dest);
    size_t idx_src = 0;

    while (src[idx_src] != '\0')
    {
        dest[idx_dest] = src[idx_src];
        idx_src++;
        idx_dest++;
    }
    return dest;
}
