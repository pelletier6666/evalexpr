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

TestSuite(queue, .init = setup, .fini = teardown);

Test(queue, push_one_token)
{
    struct token *token = token_create(NUM, 8);
    if (queue_push(q, token) == 0)
        cr_skip_test();
    cr_expect_eq(q->head->elm, token);
    cr_expect_eq(q->tail->elm, token);
    cr_expect_eq(queue_size(q), 1);
}

Test(queue, push_two_tokens)
{
    struct token *token_head = token_create(NUM, 7);
    struct token *token_tail = token_create(NUM, 8);

    if (queue_push(q, token_tail) == 0 || queue_push(q, token_head) == 0)
        cr_skip_test();
    cr_expect_eq(token_head, q->head->elm);
    cr_expect_eq(token_tail, q->tail->elm);
    cr_expect_eq(queue_size(q), 2);
}
Test(queue, push_three_tokens)
{
    struct token *token_head = token_create(NUM, 6);
    struct token *token_between = token_create(NUM, 7);
    struct token *token_tail = token_create(NUM, 8);

    if (queue_push(q, token_tail) == 0 
        || queue_push(q, token_between) == 0
        || queue_push(q, token_head) == 0)
        cr_skip_test();
    cr_expect_eq(token_tail, q->tail->elm);
    cr_expect_eq(token_head, q->head->elm);
    cr_expect_eq(queue_size(q), 3);
}

Test(queue, peek_in_empty_queue)
{
    cr_assert_null(queue_peek(q));
}

Test(queue, peek_in_1_tokens_queue)
{
    struct token *token = token_create(NUM, 7);

    if (queue_push(q, token) == 0)
        cr_skip_test();
    cr_expect_eq(token, queue_peek(q));
}


Test(queue, pop_empty_queue)
{
    cr_assert_null(queue_pop(q));
}
Test(queue, pop_in_1_token_queue_size)
{
    struct token *token = token_create(NUM, 7);

    if (queue_push(q, token) == 0)
        cr_skip_test();
    cr_expect_eq(token, queue_pop(q));
    cr_expect_eq(0, queue_size(q));
    free(token);
}

Test(queue, push_push_pop_pop)
{
    struct token *token0 = token_create(NUM, 7);
    struct token *token1 = token_create(NUM, 7);

    if (queue_push(q, token0) == 0 || queue_push(q, token1) == 0)
        cr_skip_test();
    cr_expect_eq(token1, queue_pop(q));
    cr_expect_eq(1, queue_size(q));
    cr_expect_eq(token0, queue_pop(q));
    cr_expect_eq(0, queue_size(q));
    free(token0);
    free(token1);
}


Test(queue, print_stream_signed_num_tokens)
{
    //GIVEN
    struct token *token = NULL;

    for (int i = 0; i < 5; i++)
    {
        int num_value = (i % 2 == 0) ? -1 * i : i;
        token = token_create(NUM, num_value);
        queue_push(q, token);
    }
    char *result;
    size_t len_res; 
    FILE *stream = open_memstream(&result, &len_res);
    //WHEN
    queue_print_stream(q, stream);
    fclose(stream);
    //THEN
    char *expected = "-4 -> 3 -> -2 -> 1 -> 0\n";
    cr_assert_str_eq(result, expected);
    free(result);
}

Test(queue, queue_print_stream_operators_tokens)
{
    //GIVEN 
    struct token *token = NULL;

    for (int i = 0; i < 8; i++)
    {
        int token_type = i;
        int token_value = 0;
        token = token_create(token_type, token_value);
        queue_push(q, token);
    }
    char *result;
    size_t len_res; 
    FILE *stream = open_memstream(&result, &len_res);
    //WHEN
    queue_print_stream(q, stream);
    fclose(stream);
    //THEN
    char *expected = ") -> ( -> POW -> MOD -> DIV -> MUL -> MIN -> ADD\n";
    cr_assert_str_eq(result, expected);
    free(result);
}
