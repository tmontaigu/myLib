#include <stdio.h>
#include <assert.h>

#include "fifo_q_inline.h"

struct fifo_element {
    int a;

    struct fifo_element *next;
    struct fifo_element *prev;
};


DECL_FIFO_QUEUE(integers, struct fifo_element)



int main(int argc, char **argv) {

    struct fifo_element *e =  malloc(sizeof * e), *popped = NULL;
    e->next = NULL;
    e->prev = NULL;
    e->a = 0;

    struct fifo_q_integers *q = fifo_q_new(integers);
    printf("Size: %d\n", q->size);
    fifo_q_put(integers, q, e);
    printf("Size: %d\n", q->size);

    popped = fifo_q_pop(integers, q);
    assert(popped = e);
    assert(q->size == 0);
    printf("Size: %d\n", q->size);

    free(q);
    return 0;
}