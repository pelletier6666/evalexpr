#include <criterion/criterion.h>
#include <string.h>
#include "my_readline.h"

FILE *generate_stream_from_string(char *string)
{
    FILE *stream = fopen("tmp_test-file", "w+");
    fputs(string, stream);
    fseek(stream, 0, SEEK_SET);
    return stream;
}
/*
Test(my_readline, empty_file)
{
    char *string = "";
    FILE *stream = generate_stream_from_string(string);

    char *result = my_readline_from_stream(stream);
    char *expected = "";

    cr_assert_str_eq(result, expected);
    fclose(stream);
    free(result);
}
Test(my_readline, only_one_line_jump)
{
    char *string = "\n";
    FILE *stream = generate_stream_from_string(string);

    char *result = my_readline_from_stream(stream);
    char *expected = "";

    cr_assert_str_eq(result, expected);
    fclose(stream);
    free(result);
}

Test(my_readline, no_line_jump_long_line)
{
    char *string = "hhhhhhhhhh";
    FILE *stream = generate_stream_from_string(string);

    char *result = my_readline_from_stream(stream);
    char *expected = "hhhhhhhhhh";

    cr_assert_str_eq(result, expected);
    fclose(stream);
    free(result);
}

Test(my_readline, one_line_jump)
{
    char *string = "hhhhh\n";
    FILE *stream = generate_stream_from_string(string);

    char *result = my_readline_from_stream(stream);
    char *expected = "hhhhh";

    cr_assert_str_eq(result, expected);
    fclose(stream);
    free(result);
}
*/
Test(my_readline, many_line_jumps)
{
    char *string = "iii\niii\niii\n\n";
    FILE *stream = generate_stream_from_string(string);

    char *result = my_readline_from_stream(stream);
    char *expected = "iiiiiiiii";

    cr_assert_str_eq(result, expected);
    fclose(stream);
    free(result);
}
