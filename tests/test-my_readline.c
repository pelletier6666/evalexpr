#include <criterion/criterion.h>
#include <string.h>
#include "my_readline.h"

FILE *generate_stream_from_string(char *string, char *filename)
{
    FILE *stream = fopen(filename, "w+");
    fputs(string, stream);
    fseek(stream, 0, SEEK_SET);
    return stream;
}
int close_and_erase_file_stream(FILE *stream, char *filename)
{
    fflush(stream);
    fclose(stream);
    return remove(filename); 
}

Test(my_readline, empty_file)
{
    char *string = "";
    FILE *stream = generate_stream_from_string(string, "empty_file");

    char *result = my_readline_from_stream(stream);
    char *expected = "";


    cr_assert_str_eq(result, expected);

    close_and_erase_file_stream(stream, "empty_file");
    free(result);
}
Test(my_readline, only_one_line_jump)
{
    char *string = "\n";
    FILE *stream = generate_stream_from_string(string, "one_line_file");

    char *result = my_readline_from_stream(stream);
    char *expected = "";

    close_and_erase_file_stream(stream, "one_line_file");
    cr_assert_str_eq(result, expected);
    free(result);
}

Test(my_readline, no_line_jump_long_line)
{
    char *string = "hhhhhhhhhh";
    FILE *stream = generate_stream_from_string(string, "long_line_file");

    char *result = my_readline_from_stream(stream);
    char *expected = "hhhhhhhhhh";

    close_and_erase_file_stream(stream, "long_line_file");
    cr_assert_str_eq(result, expected);
    free(result);
}
Test(my_readline, one_line_jump)
{
    char *string = "hhhhh\n";
    FILE *stream = generate_stream_from_string(string, "file1");

    char *result = my_readline_from_stream(stream);
    char *expected = "hhhhh";

    close_and_erase_file_stream(stream, "file1");
    cr_assert_str_eq(result, expected);
    free(result);
}
Test(my_readline, many_line_jumps)
{
    char *string = "iii\niii\niii\n\n";
    FILE *stream = generate_stream_from_string(string, "file2");

    char *result = my_readline_from_stream(stream);
    char *expected = "iiiiiiiii";

    close_and_erase_file_stream(stream, "file2");
    cr_assert_str_eq(result, expected);
    free(result);
}
