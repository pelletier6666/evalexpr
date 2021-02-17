#include "my_atoi_itoa_base.h"
#include "my_string.h"
#include <stdio.h>

char *my_strrev(char *str)
{
    size_t i = 0;
    size_t j = my_strlen(str);
    if (j <= 1)
        return str;
    j--;
    //ssize_t gap = j - i
    while (i < j)
    {
        char tmp_char = str[i];
        str[i] = str[j];
        str[j] = tmp_char;
        i++;
        j--;
    }
    return str;
}
unsigned n_power_of(int num, unsigned n)
{
    int res = 1;
    while (n > 0)
    {
        res *= num;
        n--;
    }
    return res;
}
int my_atoi_base(const char *str, const char *base)
{
    if (str[0] == '\0')
        return 0;

    int result = 0;
    int base_size = my_strlen(base);
    int power = 1;
    ssize_t str_idx = my_strlen(str) - 1;
    size_t num_idx = 0;

    while (str_idx >= 0 && str[str_idx] != '-')
    {
        num_idx = 0;
        while (base[num_idx] != '\0' && str[str_idx] != base[num_idx])
            num_idx++;
        result += num_idx * power;
        str_idx--;
        power *= base_size;
    }
    return (str[0] == '-') ? -1 * result : result;
}
unsigned my_itoa_base_string_len(unsigned i, unsigned n)
{
    unsigned power = n;
    unsigned result = 1;
    while (i > power)
    {
        power *= n;
        result += 1;
    }
    return result + 1;
}
int abs(int num)
{
    return (num < 0) ? -1 * num : num;
}

char *my_itoa_base(int i, const char *base)
{
    size_t base_len = my_strlen(base);
    size_t len_res = my_itoa_base_string_len(abs(i), my_strlen(base)) + (i < 0);
    char *s = calloc(len_res + 1, sizeof(char));
    int num = abs(i);
    if (s == NULL)
        return NULL;
    int idx_res = 0;
    while (num > 0)
    {
        int idx = 0;
        while (base[idx] != '\0' && (num - idx) % base_len != 0)
            idx++;
        num = (num - idx) / base_len;
        s[idx_res] = base[idx];
        idx_res++;
    }
    if (i < 0)
        s[idx_res] = '-';
    return my_strrev(s);
}



