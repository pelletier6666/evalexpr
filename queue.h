#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
struct list
{
    struct token *elm;
    struct list *next;
};
struct queue
{
    struct list *head;
    struct list *tail;
    size_t size;
};
struct queue *queue_init(void);
size_t queue_size(struct queue *q);
int queue_push(struct queue *q, struct token *elm);
struct token *queue_peek(struct queue *q);
struct token *queue_pop(struct queue *q);
void queue_print(struct queue *q);
void queue_print_stream(struct queue *q, FILE *stream);
void queue_destroy(struct queue *q);

