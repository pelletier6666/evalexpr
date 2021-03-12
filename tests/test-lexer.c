#include "lexer.h"

#include <criterion/criterion.h>
#include <stdlib.h>

Test(is_belong_to, empty_set)
{
    int result = is_belong_to('b', "");
    int expected = 0;
    cr_assert_eq(result, expected);
}
Test(is_belong_to, set_with_only_1_char)
{
    int result = is_belong_to('b', "b");
    int expected = 1;
    cr_assert_eq(result, expected);
}

Test(is_belong_to, is_null_terminating_byte_belong_to)
{
    int result = is_belong_to('\0', "b");
    int expected = 1;
    cr_assert_eq(result, expected);
}

Test(is_belong_to, sample_out_of_collection)
{
    int result = is_belong_to('h', "abcdefg");
    int expected = 0;
    cr_assert_eq(result, expected); 
}

Test(get_token_type, valid_num_type)
{
    const char *line = "f0";
    struct opt *option = build_opt("0123456789abcdef", "+-*/%^()", none, 1, 1);

    if (option == NULL)
        cr_skip_test();
                                  
    int result = get_token_type(line, option);
    int expected = NUM;

    cr_assert_eq(result, expected); 
    free(option);
}

Test(get_token_type, valid_operator_type)
{
    const char *line = "( -";
    struct opt *option = build_opt("0123456789abcdef", "+-*/%^()", none, 1, 1);

    if (option == NULL)
        cr_skip_test();
                                  
    int result = get_token_type(line, option);
    int expected = OPEN_PAR;

    cr_assert_eq(result, expected); 
    free(option);
}

Test(get_token_type, invalid_operator_type)
{
    const char *line = " ";
    struct opt *option = build_opt("0123456789abcdef", "+-*/%^()", none, 1, 1);

    if (option == NULL)
        cr_skip_test();
                                  
    int result = get_token_type(line, option);
    int expected = -1;

    cr_assert_eq(result, expected); 
    free(option);
}

Test(skip_token, skip_num_token)
{
    const char *line = "9fff";
    enum type token_type = NUM;
    char *base = "0123456789abcdef";
    int result = skip_and_get_token_value(&line, token_type, base);
    int expected = atoi(line);
    cr_assert_eq(result, expected); 
    cr_assert_eq(*line, '\0'); 
}
Test(skip_token, skip_num_token_1)
{
    const char *line = "00236j";
    enum type token_type = NUM;
    char *base = "0123456789abcdef";
    int result = skip_and_get_token_value(&line, token_type, base);
    int expected = atoi("00236");
    cr_assert_eq(result, expected); 
    cr_assert_eq(*line, 'j'); 
}
Test(skip_token, skip_op_token)
{
    const char *line = "(";
    enum type token_type = OPEN_PAR;
    char *base = "0123456789abcdef";
    int result = skip_and_get_token_value(&line, token_type, base);
    int expected = 0;
    cr_assert_eq(result, expected); 
    cr_assert_eq(*line, '\0'); 
}

void check_queue_output(struct queue *q, char *expected)
{
    size_t read_bytes = 0;
    char *result;
    FILE *stream = open_memstream(&result, &read_bytes);
    if (stream == NULL)
        cr_skip_test();
    queue_print_stream(q, stream);
    fclose(stream);

    cr_assert_eq(result, expected);
}
struct opt *option_init(char *base)
{
    struct opt *option = build_opt(base, "+-*/%^()", none, 1, 1);
    if (option == NULL)
        cr_skip_test();
    return option;
}
void test_lexer_with(char *expr, char *opt_base, char *expected)
{
    int error_code = 0;
    struct opt *options = option_init(opt_base);
    struct queue *q = lexer(expr, options, &error_code);
    check_queue_output(q, expected);
    cr_expect_eq(*expr, '\0');
    cr_expect_eq(error_code, error_code);

}

Test(lexer, simple_expression)
{
    char *expr = "4 + 4";
    char *base = "012345678";
    char *expected = "NUM -> + -> NUM";
    test_lexer_with(expr, base, expected);
}

Test(lexer, simple_expression_1)
{
    char *expr = "4 /(2 --4)";
    char *base = "01234";
    char *expected = "VAL: 4 -> DIV -> ( -> VAL: 2 -> MIN -> MIN -> )";
    test_lexer_with(expr, base, expected);
 
}
Test(lexer, simple_expression_2)
{
    char *expr = "01001010 + ( ( ) + - 11111 0011001";
    char *base = "01";
    char *expected = "VAL: 9 -> ADD -> ( -> ( -> ) -> ADD -> MIN -> VAL: 15 -> VAL: 15";
    test_lexer_with(expr, base, expected);
}
Test(lexer, simple_expression_3)
{
    char *expr = "aff / 5 + + -- f 5";
    char *base = "0123456789abcdef";
    char *expected= "VAL: 2815 -> DIV -> VAl: 5 -> ADD -> ADD -> MIN -> MIN -> VAL: 15 -> VAl: 5";
    test_lexer_with(expr, base, expected);
}
Test(lexer, simple_expression_4)
{
    char *expr = "";
    char *base = "0123456789abcdef";
    char *expected= "";
    test_lexer_with(expr, base, expected);
}
Test(lexer, simple_expression_5)
{
    char *expr = "f";
    char *base = "0123456789abcdef";
    char *expected= "VAL: 15";
    test_lexer_with(expr, base, expected);
}





