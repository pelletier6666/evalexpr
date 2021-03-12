#include <criterion/criterion.h>
#include "my_getopt.h"


TestSuite(my_getopt_valid_options, .exit_code = 0); 
TestSuite(my_getopt_invalid_options, .exit_code = 0); 

struct opt *build_opt(char *base, char *op_string, enum traversal_type type, char l, char h)
{
    struct opt *option = calloc(1, sizeof(struct opt));
    if (option == NULL)
        cr_skip_test("Allocation fail");
    option->b = base;
    option->o = op_string;
    option->p = type;
    option->l = l;
    option->h = h;
    return option;
}

void compare_options_struct(struct opt *opt1, struct opt *opt2)
{
    cr_expect_str_eq(opt1->b, opt2->b);
    cr_expect_str_eq(opt1->o, opt2->o);
    cr_expect_eq(opt1->p, opt2->p);
    cr_expect_eq(opt1->l, opt2->l);
    cr_expect_eq(opt1->h, opt2->h);
}

Test(my_getopt_valid_options, many_option_with_repetition)
{
    int argc = 18;

    char *argv[18] = 
    { 
        "-p", "prefix", "-b", "012",
        "-h", "-o", "hijklmno", "-p", "infix", 
        "-b", "0123456", "-l", "-o", "12345678",
        "-b", "0123", "-p", "suffix"
    };

    int error = 0;

    struct opt *result = my_getopt(argc, argv, &error);
    struct opt *expected = build_opt("0123", "12345678", suffix, 1, 1);

    compare_options_struct(result, expected);

    free(result);
    free(expected);
}


Test(my_getopt_valid_options, default_options_arg)
{
    int argc = 1;
    char *argv[1] = 
    {
        "-h" 
    };
    int error = 0;

    struct opt *result = my_getopt(argc, argv, &error);
    struct opt *expected = build_opt("0123456789", "+-*/%^()", none, 0, 1);
    
    compare_options_struct(result, expected);

    free(result);
    free(expected);
}


Test(my_getopt_invalid_options, bad_lenght_of_operator_list)
{
    int argc = 4;
    char *argv[4] = 
    {
        "-o",
        "1234567",
        "-o",
        "12345"
    };
    int error = 0;

    struct opt *result = my_getopt(argc, argv, &error);
    cr_expect_null(result);
    cr_expect_eq(error, 4);
}
Test(my_getopt_invalid_options, missing_base_string)
{
    int argc = 1;
    char *argv[1] = 
    {
        "-b"
    };
    int error = 0;

    struct opt *result = my_getopt(argc, argv, &error);
    cr_expect_null(result);
    cr_expect_eq(error, 4);


}

Test(my_getopt_invalid_options, empty_base_string)
{
    int argc = 2;
    char *argv[2] = 
    {
        "-b",
        ""
    };
    int error = 0;

    struct opt *result = my_getopt(argc, argv, &error);
    cr_expect_null(result);
    cr_expect_eq(error, 4);
}

Test(my_getopt_invalid_options, invalid_base_opt)
{
    int argc = 3;
    char *argv[3] =
    {
        "-bhdj",
        "0123456"
        "-l"
    };

    int error = 0;

    struct opt *result = my_getopt(argc, argv, &error);
    cr_expect_null(result);
    cr_expect_eq(error, 4);
}



Test(my_getopt_invalid_options, too_many_dash)
{
    int argc = 6;
    char *argv[6] =
    {
        "-b",
        "012345",
        "--",
        "-h",
        "-l"
    };

    int error = 0;

    struct opt *result = my_getopt(argc, argv, &error);
    cr_expect_null(result);
    cr_expect_eq(error, 4);
}


Test(my_getopt_invalid_options, missing_dash)
{
    int argc = 2;
    char *argv[2] =
    {
        "b",
        "012345",
    };

    int error = 0;

    struct opt *result = my_getopt(argc, argv, &error);
    cr_expect_null(result);
    cr_expect_eq(error, 4);
}


Test(my_getopt_invalid_options, invalid_lexer_printer_arg)
{
    int argc = 2;
    char *argv[2] =
    {
        "-p",
        "sufix",
    };

    int error = 0;

    struct opt *result = my_getopt(argc, argv, &error);
    cr_expect_null(result);
    cr_expect_eq(error, 4);
}

Test(my_getopt_invalid_options, invalid_length_base_string)
{
    int argc = 4;
    char *argv[4] =
    {
        "-b",
        "ab",
        "-b",
        "b"
    };

    int error = 0;

    struct opt *result = my_getopt(argc, argv, &error);
    cr_expect_null(result);
    cr_expect_eq(error, 4);
}
Test(my_getopt_invalid_options, unknown_operator)
{
    int argc = 7;
    char *argv[7] =
    {
        "-b",
        "ab",
        "-b",
        "abc",
        "-h",
        "-l",
        "-t"
    };

    int error = 0;

    struct opt *result = my_getopt(argc, argv, &error);
    cr_expect_null(result);
    cr_expect_eq(error, 4);
}

Test(my_getopt_invalid_options, common_symbol_in_operator_and_base_string)
{
    int argc = 7;
    char *argv[7] =
    {
        "-b",
        "01234567",
        "-o"
        "abcdefgh"
        "-o"
        "abcde5gh",
    };

    int error = 0;

    struct opt *result = my_getopt(argc, argv, &error);
    cr_expect_null(result);
    cr_expect_eq(error, 4);
}
