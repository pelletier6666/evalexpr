#include "my_atoi_itoa_base.h"
#include <criterion/criterion.h>
Test(my_strrev, empty_string)
{
    char *str = strdup("");
    char *result = my_strrev(str);
    char *expected = "";
    cr_assert_str_eq(result, expected);
}

Test(my_strrev, 1_char_string)
{
    char *str = strdup("i");
    char *result = my_strrev(str);
    char *expected = "i";
    cr_assert_str_eq(result, expected);

}
Test(my_strrev, 2_char_string)
{
    char *str = strdup("uy");
    char *result = my_strrev(str);
    char *expected = "yu";
    cr_assert_str_eq(result, expected);

}
Test(my_strrev, 3_char_string)
{ 
    char *str = strdup("abc");
    char *result = my_strrev(str);
    char *expected = "cba";
    cr_assert_str_eq(result, expected);

}
Test(my_strrev, 7_char_string)
{
    char *str = strdup("abcdefg");
    char *result = my_strrev(str);
    char *expected = "gfedcba";
    cr_assert_str_eq(result, expected);
}
Test(my_strrev, 8_char_string)
{
    char *str = strdup("abcdefgh");
    char *result = my_strrev(str);
    char *expected = "hgfedcba";
    cr_assert_str_eq(result, expected);
}


Test(my_atoi_base, reg_test)
{
    int result = my_atoi_base("ff", "0123456789abcdef");
    int expected = 255;
    cr_assert_eq(result, expected, "Expected: %d Got %d", expected, result);
}
Test(my_atoi_base, reg_test_1)
{
    int result = my_atoi_base("-ff", "0123456789abcdef");
    int expected = -255;
    cr_assert_eq(result, expected, "Expected: %d Got %d", expected, result);
}
Test(my_atoi_base, reg_test_2)
{
    int result = my_atoi_base("77", "01234567");
    int expected = 63;
    cr_assert_eq(result, expected, "Expected: %d Got %d", expected, result);
}
Test(my_atoi_base, reg_test_3)
{
  int result = my_atoi_base("WQWW", "QW");
  int expected = 11;
  cr_assert_eq(result, expected, "Expected: %d Got %d", expected, result);
}
Test(my_atoi_base, reg_test_4)
{
  int result = my_atoi_base("-WQQWQWW", "QW");
  int expected = -75;
  cr_assert_eq(result, expected, "Expected: %d Got %d", expected, result);

}
Test(my_atoi_base, reg_test_6)
{
  int result = my_atoi_base("-QWXZH", "QWXZH");
  int expected = -194;
  cr_assert_eq(result, expected, "Expected: %d Got %d", expected, result);

}

Test(my_atoi_base, reg_test_7)
{
  int result = my_atoi_base("-QQQQ", "QWXZH");
  int expected = -0;
  cr_assert_eq(result, expected, "Expected: %d Got %d", expected, result);

}


Test(my_atoi_base, reg_test_8)
{
  int result = my_atoi_base("", "QWXZH");
  int expected = -0;
  cr_assert_eq(result, expected, "Expected: %d Got %d", expected, result);

}

Test(my_atoi_base, reg_test_9)
{
  int result = my_atoi_base("-QQQQ", "");
  int expected = -0;
  cr_assert_eq(result, expected, "Expected: %d Got %d", expected, result);

}

Test(my_atoi_base, reg_test_10)
{
  int result = my_atoi_base("Q", "Q");
  int expected = -0;
  cr_assert_eq(result, expected, "Expected: %d Got %d", expected, result);

}
Test(my_atoi_base, reg_test_11)
{
    int result = my_atoi_base("-Z", "AZERTY");
    int expected = -1;
    cr_assert_eq(result, expected, "Expected: %d Got %d", expected, result);
}

Test(my_itoa_base, reg_test)
{
    char *result = my_itoa_base(255, "0123456789");
    char *expected = "255";
    cr_assert_str_eq(result, expected);
}
Test(my_itoa_base, reg_test_1)
{
   char *result = my_itoa_base(255, "0123456789abcdef");
   char *expected = "ff";
   cr_assert_str_eq(result, expected);
}

Test(my_itoa_base, reg_test_2)
{
  char *result = my_itoa_base(11, "QW");
  char *expected = "WQWW";
  cr_assert_str_eq(result, expected);
}

Test(my_itoa_base, reg_test_3)
{
  char *result = my_itoa_base(255, "bhsaef");
  char *expected = "hhba";
  cr_assert_str_eq(result, expected);
}

Test(my_itoa_base, reg_test_4)
{
  char *result = my_itoa_base(255, "9876543210");
  char *expected = "744";
  cr_assert_str_eq(result, expected);
}

Test(my_itoa_base, reg_test_5)
{
  char *result = my_itoa_base(-1, "AZERTY");
  char *expected = "-Z";
  cr_assert_str_eq(result, expected);
}
