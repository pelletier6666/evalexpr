#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>

#include "queue.h"
#include "token.h"

static struct queue *q = NULL;
static void setup(void)
{
    q = queue_init();
}
static void teardown(void)
{
    queue_destroy(q);
}

int push_n_operators(struct queue *q, unsigned n)
{
    for (unsigned i = 0; i < n; i++)
    {
        struct token *token = token_create(i % 9, 0);
        if (token->type == NUM)
            token->value = -7;
        if (queue_push(q, token) == 0)
        {
            free(token);
            return 0;
        }
    }
    return 1;
}
int push_n_num(struct queue *q, unsigned n)
{
    for (unsigned i = 0; i < n; i++)
    {
        struct token *token = token_create(NUM, i);
        if (queue_push(q, token) == 0)
        {
            free(token);
            return 0;
        }
    }
    return 1;
}
TestSuite(queue, .init = setup, .fini = teardown);

Test(queue, push)
{
    char *result = NULL;

    size_t result_len = 0;
    FILE *stream = open_memstream(&result, &result_len);
    if (push_n_operators(q, 5) == 0)
        cr_skip_test();
    char *expected = "MOD -> DIV -> MUL -> MIN -> ADD\n";
    queue_print_stream(q, stream);

    fclose(stream);
    cr_expect_str_eq(result, expected);
    free(result);
}
Test(queue, push_1)
{
    char *result = NULL;

    size_t result_len = 0;
    FILE *stream = open_memstream(&result, &result_len);

    if (push_n_num(q, 4) == 0)
        cr_skip_test();

    char *expected = "3 -> 2 -> 1 -> 0\n";
    queue_print_stream(q, stream);

    fclose(stream);
    cr_expect_str_eq(result, expected);

    free(result);
}


Test(queue, peek_and_pop_with_many_token_types)
{
    if (push_n_operators(q, 5) == 0)
    {
        queue_destroy(q);
        cr_skip_test();
    }
    for (int i = 0; i < 5; i++)
    {
        struct token *token = queue_peek(q);

        cr_expect_eq(token, queue_pop(q));
        cr_expect_eq(token->type, 4 - i);
        cr_expect_eq(token->value, 0);
        cr_expect_eq(queue_size(q), 4 - i);
        if (queue_size(q) >= 1)
            cr_expect_eq(queue_peek(q)->type, 4 - (i + 1));
        else
            cr_expect_null(queue_peek(q));
        free(token);
    }
}
Test(queue, peek_and_pop_1)
{
    if (push_n_num(q, 5) == 0)
        cr_skip_test();
    for (int i = 0; i < 5; i++)
    {
        struct token *token = queue_peek(q);

        cr_expect_eq(token, queue_pop(q));
        cr_expect_eq(token->type, NUM);
        cr_expect_eq(token->value, 4 - i);
        cr_expect_eq(queue_size(q), 4 - i);
        if (queue_size(q) >= 1)
            cr_expect_eq(queue_peek(q)->type, NUM);
        else
            cr_expect_null(queue_peek(q));
        free(token);
    }
}
