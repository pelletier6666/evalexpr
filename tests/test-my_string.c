#include <signal.h>
#include <stddef.h>
#include <criterion/criterion.h>
#include <string.h>

#include "my_string.h"

Test(my_string, my_strlen_empty_str)
{
    size_t result = my_strlen("");
    size_t expected = strlen("");
    cr_assert_eq(result, expected);
}
Test(my_string, my_strlen_null_str, .signal = SIGSEGV)
{
    my_strlen(NULL);
}
Test(my_string, my_strlen_short_str)
{
    size_t result = my_strlen("1");
    size_t expected = strlen("1");
    cr_assert_eq(result, expected);

}

Test(my_string, my_strlen_short_str_1)
{
    size_t result = my_strlen("ab");
    size_t expected = strlen("ab");
    cr_assert_eq(result, expected);

}
Test(my_string, my_strlen_long_str)
{
    size_t result = my_strlen("Bonjour tous le monde je m'appelle Nicolas.");
    size_t expected = strlen("Bonjour tous le monde je m'appelle Nicolas.");
    cr_assert_eq(result, expected);
}
Test(my_string, my_strcmp_with_1_empty_str)
{
    
    int result = my_strcmp("", "bonjour");
    int expected = strcmp("", "bonjour");
    cr_assert_eq(result, expected);
}
Test(my_string, my_strcmp_with_2_empty_str)
{
    
    int result = my_strcmp("", "");
    int expected = strcmp("", "");
    cr_assert_eq(result, expected);
}
Test(my_string, my_strcmp_with_1_null_str, .signal = SIGSEGV)
{
    int result = my_strcmp(NULL, NULL);
    cr_assert_eq(result, 1);

}


Test(my_string, my_strcmp_with_2_null_str, .signal = SIGSEGV)
{
    int result = my_strcmp(NULL, NULL);
    cr_assert_eq(result, 1);

}
Test(my_string, my_strcmp_str_less_than_1_byte_length)
{
    
    int result = my_strcmp("a", "b");
    int expected = strcmp("a", "b");
    cr_assert_eq(result, expected);
}

Test(my_string, my_strcmp_eq_strings_but_last_byte_less)
{
    
    int result = my_strcmp("aaaab", "aaaaa");
    int expected = strcmp("aaaab", "aaaaa");
    cr_assert_eq(result, expected);
}

Test(my_string, my_strcmp_eq_strings_but_shorter_than)
{
    
    int result = my_strcmp("aa", "aaaaa");
    int expected = strcmp("aa", "aaaaa");
    cr_assert_eq(result, expected);
}

Test(my_string, my_strcmp_eq_strings_only_at_the_beginning_and_shorter)
{
    
    int result = my_strcmp("cd", "cdaaa");
    int expected = strcmp("cd", "cdaaa");
    cr_assert_eq(result, expected);
}

Test(my_string, my_strcmp_eq_short_strings)
{
    
    int result = my_strcmp("c", "c");
    int expected = strcmp("c", "c");
    cr_assert_eq(result, expected);
}
Test(my_string, my_strcmp_eq_long_strings)
{
    
    int result = my_strcmp("hello tous le Monde.", "hello tous le Monde.");
    int expected = strcmp("hello tous le Monde.", "hello tous le Monde.");
    cr_assert_eq(result, expected);
}

Test(my_string, my_strcmp_eq_short_str)
{
    
    int result = my_strcmp("ab", "ab");
    int expected = strcmp("ab", "ab");
    cr_assert_eq(result, expected);
}

Test(my_string, my_strcmp_eq_str_but_shorter)
{
    int result = my_strcmp("aaaaaa", "aaaaa");
    int expected = strcmp("aaaaaa", "aaaaa");
    cr_assert_eq(result, expected);
}
Test(my_string, my_strcmp_neq_one_char_differ)
{
    int result = my_strcmp("aaaaaz", "aaaaax");
    int expected = strcmp("aaaaaz", "aaaaax");
    cr_assert_eq(result, expected);

}

Test(my_string, my_strdup_empty_str)
{
    char *result = my_strdup("");
    char *expected = strdup("");
    cr_assert_str_eq(result, expected);
    free(result);
    free(expected);
}
/*Test(my_string, my_strdup_null_str)
{
    char *s1 = NULL;
    char *result = my_strdup(NULL);
    char *expected = strdup(s1);
    cr_assert_str_eq(result, expected);
    free(result);
    free(expected);
}*/
Test(my_string, my_strdup_short_str)
{
    char *result = my_strdup("hdjhdjh");
    char *expected = strdup("hdjhdjh");
    cr_assert_str_eq(result, expected);
    free(result);
    free(expected);
}
Test(my_string, my_strdup_long_str)
{
    char *result = my_strdup("hdjhdhsjhdjhdhdj dhjdh jdhjhd hjhdhjzh    ");
    char *expected = strdup("hdjhdhsjhdjhdhdj dhjdh jdhjhd hjhdhjzh    ");
    cr_assert_str_eq(result, expected);
    free(result);
    free(expected);
}


Test(my_string, my_strndup_0_bytes_copied_from_empty_str)
{
    char *result = my_strndup("", 0);
    char *expected = strndup("", 0);
    cr_assert_str_eq(result, expected);
    free(result);
    free(expected);
}

Test(my_string, my_strndup_0_bytes_copied_from_str)
{
    char *result = my_strndup("shsh", 0);
    char *expected = strndup("shsh", 0);
    cr_assert_str_eq(result, expected);
    free(result);
    free(expected);
}
/*Test(my_string, my_strndup_null_str)
{
    char *s1 = NULL;
    char *result = my_strndup(NULL);
    char *expected = strndup(s1);
    cr_assert_str_eq(result, expected);
    free(result);
    free(expected);
}*/
Test(my_string, my_strndup_few_bytes_copied_from_reg_str)
{
    char *result = my_strndup("hdjhdjh", 2);
    char *expected = strndup("hdjhdjh", 2);
    cr_assert_str_eq(result, expected);
    free(result);
    free(expected);
}
Test(my_string, my_strndup_copy_full_str)
{   
    char *result = my_strndup("hdjhdhsjhd", 10);
    char *expected = strndup("hdjhdhsjhd", 10);
    cr_assert_str_eq(result, expected);
    free(result);
    free(expected);
}
Test(my_string, my_strndup_bytes_copied_from_empty_str)
{   
    char *result = my_strndup("", 10);
    char *expected = strndup("", 10);
    cr_assert_str_eq(result, expected);
    free(result);
    free(expected);
}

Test(my_string, my_strndup_exceeds_the_amount_of_byte_availaible)
{
   
    char *result = my_strndup("hdjhdhs", 10);
    char *expected = strndup("hdjhdhs", 10);
    cr_assert_str_eq(result, expected);
    free(result);
    free(expected);

}
void test_strcat(char *dest, size_t alloc_size, const char *src)
{
    char *dest_res = calloc(alloc_size + 1, sizeof(char));
    char *dest_exp = calloc(alloc_size + 1, sizeof(char));

    cr_assert(dest_res != NULL && dest_exp != NULL);
    size_t len_dest = my_strlen(dest);
    for (size_t i = 0; i < len_dest; i++)
    {
        dest_res[i] = dest[i];
        dest_exp[i] = dest[i];
    }

    char *result = my_strcat(dest_res, src);
    char *expected = strcat(dest_exp, src);

    cr_assert_str_eq(result, expected);
}
Test(my_string, my_strcat_with_both_empty)
{   
    test_strcat("", 0, "");
}
Test(my_string, my_strcat_with_NULL_dest, .signal = SIGSEGV)
{
    char *result = my_strcat(NULL, "hello");
    cr_assert_str_eq(result, result);

}
Test(my_string, my_strcat_with_NULL_src, .signal = SIGSEGV)
{
    char *dest = calloc(6, sizeof(char));
    strncpy(dest, "hello", 5);
    char *result = my_strcat(dest, NULL);
    cr_assert_str_eq(result, result);
}
Test(my_string, my_strcat_with_both_NULL, .signal = SIGSEGV)
{
    char *result = my_strcat(NULL, NULL);
    cr_assert_str_eq(result, result);
}
Test(my_string, my_strcat_dest_not_large_enough)
{
    test_strcat("hello", 5, "helloworld");
}
Test(my_string, my_strcat_dest_without_terminating_null_byte)
{
    test_strcat("hello", 4, "helloworld");
}
Test(my_string, my_strcat_strings_overlap)
{
    char *dest = strdup("Hello World!");
    char *dest_exp = strdup("Hello World!");
    char *result = my_strcat(dest, dest + 5);
    char *expected = strcat(dest_exp, dest_exp + 5);

    cr_assert_str_eq(result, expected);
}

Test(my_string, my_strcat_strings_overlap1)
{
    char *dest = strdup("Hello World!");
    char *dest_exp = strdup("Hello World!");
    char *result = my_strcat(dest + 5, dest);
    char *expected = strcat(dest_exp + 5, dest_exp);

    cr_assert_str_eq(result, expected);
}
Test(my_string, my_strcat_regular_str)
{
    test_strcat("hello world", 22, "hello w");
}
