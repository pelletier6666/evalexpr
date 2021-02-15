#include <criterion/criterion.h>
#include "my_readline.h"

Test(my_readline, line_with_several_jump_line)
{
    char *expected = "iiiiiiiiiiii\niiiiiiiiiiiiii\niiiiiiiiiiiiiiiii\niiiiiiiiiiiiiiiiiiiii\n";
    size_t expected_size = strlen(expected);
    FILE *stream = open_memstream(&expected, &expected_size);
    if (stream == NULL)
        cr_skip_test();
    char *result = my_readline_with_stream(stream);
    cr_assert_str_eq(result, expected);
}
Test(my_readline, empty_line)
{
    char *expected = "";
    size_t expected_size = strlen(expected);
    FILE *stream = open_memstream(&expected, &expected_size);
    if (stream == NULL)
        cr_skip_test();
    char *result = my_readline_with_stream(stream);
    cr_assert_str_eq(result, expected);
}
Test(my_readline, line_with_eof)
{
    char *expected = "hhhhhhhhhhhhhhhhhhhhhh";
    size_t expected_size = strlen(expected);
    FILE *stream = open_memstream(&expected, &expected_size);
    if (stream == NULL)
        cr_skip_test();
    char *result = my_readline_with_stream(stream);
    cr_assert_str_eq(result, expected);

}
