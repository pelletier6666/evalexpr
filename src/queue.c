#include "queue.h"
#include "token.h"

struct queue *queue_init(void)
{
    struct queue *q = calloc(1, sizeof(struct queue));
    if (q == NULL)
        return NULL;
    return q;

}
size_t queue_size(struct queue *q)
{
    return q->size;
}
int queue_push(struct queue *q, struct token *elm)
{
    if (q == NULL || elm == NULL)
        return 0;
    struct list *new_head = calloc(1, sizeof(struct list));
    if (new_head == NULL)
        return 0;
    new_head->elm = elm;
    new_head->next = q->head;
    if (q->head == NULL)
        q->tail = new_head;
    q->head = new_head;
    q->size += 1;
    return 1;
}

struct token *queue_pop(struct queue *q)
{
    struct list *to_remove = q->head;
    if (to_remove == NULL)
        return NULL;
    struct token *to_return = to_remove->elm;
    q->head = to_remove->next;
    if (q->size == 1)
        q->tail = NULL;
    q->size -= 1;
    free(to_remove);
    return to_return;
}

struct token *queue_peek(struct queue *q)
{
    if (q->head != NULL)
        return q->head->elm;
    else
        return NULL;
}
void queue_print(struct queue *q)
{
    queue_print_stream(q, stdin);

}
void queue_print_stream(struct queue *q, FILE *stream)
{
    if (q == NULL || q->head == NULL)
        return;
    struct list *list_elt = q->head;
    while (list_elt->next != NULL)
    {
        token_print_stream(stream, list_elt->elm);
        fprintf(stream, " -> ");
        list_elt = list_elt->next;
    }
    token_print_stream(stream, list_elt->elm);
    fprintf(stream, "\n");
}

void free_list_elt(struct list *elt)
{
    if (elt == NULL)
        return;
    free_list_elt(elt->next);
    free(elt->elm);
    free(elt);
}

void queue_destroy(struct queue *q)
{
    if (q == NULL)
        return;
    free_list_elt(q->head);
    free(q);
}


