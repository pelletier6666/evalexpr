#include "my_atoi_itoa_base.h"
#include <criterion/criterion.h>

Test(my_atoi_base, reg_test)
{
    int result = my_atoi_base("ff", "0123456789abcdef");
    int expected = 255;
    cr_assert_eq(result, expected);
}
Test(my_atoi_base, reg_test_1)
{
    int result = my_atoi_base("-ff", "0123456789abcdef");
    int expected = -255;
    cr_assert_eq(result, expected);
}
Test(my_atoi_base, reg_test_2)
{
    int result = my_atoi_base("77", "01234567");
    int expected = 63;
    cr_assert_eq(result, expected);
}
Test(my_atoi_base, reg_test_3)
{
  int result = my_atoi_base("WQWW", "QW");
  int expected = 11;
  cr_assert_eq(result, expected);
}
Test(my_atoi_base, reg_test_4)
{
    int result = my_atoi_base("-Z", "AZERTY");
    int expected = -1;
    cr_assert_eq(result, expected);
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


