#include <criterion/criterion.h>
#include "token.h"

Test(token, token_create)
{
    struct token *tok = token_create(ADD, 0);
    if (tok == NULL)
        cr_skip_test();
    cr_assert_eq(tok->value, 0);
    cr_assert_eq(tok->type, ADD);
    free(tok);
}

Test(token, token_create_neg_number)
{
    struct token *tok = token_create(NUM, -56);
    if (tok == NULL)
        cr_skip_test();
    cr_assert_eq(tok->value, -56);
    cr_assert_eq(tok->type, NUM);
    free(tok);
}

Test(token, token_create_open_par)
{
    struct token *tok = token_create(OPEN_PAR, 0);
    if (tok == NULL)
        cr_skip_test();
    cr_assert_eq(tok->value, 0);
    cr_assert_eq(tok->type, OPEN_PAR);
    free(tok);
}


