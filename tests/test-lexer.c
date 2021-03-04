#include "token.h"
#include "queue.h"
#include "lexer.h"
#include <criterion/criterion.h>

Tests(is_belong_to, empty_collection)
{
    int result = is_belong_to('b', "", 0);
    int expected = 0;
    cr_assert_eq(result, expected);
}
Tests(is_belong_to, belong_to_1_char_collection)
{
    int result = is_belong_to('b', "b", 0);
    int expected = 0;
    cr_assert_eq(result, expected);
}

Tests(is_belong_to, null_terminating_byte_char)
{
    int result = is_belong_to('', "b", 0);
    int expected = 0;
    cr_assert_eq(result, expected);
}


Tests(get_num_value, )
{
    char *line = "f0";
    char *base = "0123456789abcdef";
    int result = get_num_value(line, base);
    int expected = 15;

    cr_assert_eq(result, expected); 
    cr_assert_eq(*line, '\0');
}
Tests(lexer, get_num_value_not_in_operator_range)
{
    char *line = "00000g";
    char *base = "01";

    int result = get_num_value(line, base);
    int expected = -1;

    cr_assert_eq(result, expected); 
    cr_assert_eq(*line, '\0');
}
Tests(lexer, get_num_value_long_in_operator_range)
{

    char *line = "1111";
    char *base = "01";

    int result = get_num_value(line, base);
    int expected = 15;

    cr_assert_eq(result, expected);
    cr_assert_eq(*line, '\0');

}
Tests(lexer, get_num_value_not

