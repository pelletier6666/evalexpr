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
Test(my_readline, line_with_several_jump_line)
{
    char *string = "iiiiiiiiiiii\nii";
    FILE *stream = generate_stream_from_string(string);

    char *result = my_readline_from_stream(stream);
    char *expected = "iiiiiiiiiiii";

    cr_assert_str_eq(result, expected);
    fclose(stream);
}
Test(my_readline, empty_line)
{
    char *string = "";
    FILE *stream = generate_stream_from_string(string);

    char *result = my_readline_from_stream(stream);
    char *expected = "";

    cr_assert_str_eq(result, expected);
    fclose(stream);
}
Test(my_readline, line_with_eof)
{
    char *string = "hhhhh\n";
    FILE *stream = generate_stream_from_string(string);

    char *result = my_readline_from_stream(stream);
    char *expected = "hhhhh";

    cr_assert_str_eq(result, expected);
    fclose(stream);
}

Test(my_readline, line_with_eof1)
{
    char *string = "\nhhhh";
    FILE *stream = generate_stream_from_string(string);

    char *result = my_readline_from_stream(stream);
    char *expected = "";

    cr_assert_str_eq(result, expected);
    fclose(stream);
}
