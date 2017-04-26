#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "fifo_q.h"


int main(int argc, char **argv) {
    int count = 0;
    struct fifo_element *iter;


    struct fifo *my_fifo = (struct fifo*) malloc(sizeof(struct fifo));
    my_fifo->head = NULL;
    my_fifo->tail = NULL;
    my_fifo->size = 0;

    struct fifo_element *e = (struct fifo_element*) malloc(sizeof(struct fifo));
    e->a = 1;
    struct fifo_element *e2 = (struct fifo_element*) malloc(sizeof(struct fifo));
    e2->a = 2;
    struct fifo_element *e3 = (struct fifo_element*) malloc(sizeof(struct fifo));
    e3->a = 3;


    FIFO_Q_SIZE(my_fifo, iter, count);
    assert(count == 0);
    assert(my_fifo->size == 0);


    FIFO_Q_ADD(my_fifo, e);
    FIFO_Q_SIZE(my_fifo, iter, count);
    assert(count == 1);
    assert(my_fifo->size == 1);

    struct fifo_element *elt;
    FIFO_Q_POP(my_fifo, elt);
    assert(elt != NULL);
    assert(elt == e);

    FIFO_Q_SIZE(my_fifo, iter, count);
    assert(count == 0);
    assert(my_fifo->size == 0);

    FIFO_Q_SIZE(my_fifo, iter, count);
    assert(count == 0);
    assert(my_fifo->size == 0);

    FIFO_Q_POP(my_fifo, elt);
    assert(elt == NULL);

    FIFO_Q_SIZE(my_fifo, iter, count);
    assert(count == 0);
    assert(my_fifo->size == 0);


    // Queue is empty, add e2, then e, ten e3

    FIFO_Q_ADD(my_fifo, e2);
    FIFO_Q_SIZE(my_fifo, iter, count);
    assert(count == 1);
    assert(my_fifo->size == 1);

    FIFO_Q_ADD(my_fifo, e);
    FIFO_Q_SIZE(my_fifo, iter, count);
    assert(count == 2);
    assert(my_fifo->size == 2);

    FIFO_Q_ADD(my_fifo, e3);
    FIFO_Q_SIZE(my_fifo, iter, count);
    assert(count == 3);
    assert(my_fifo->size == 3);

    // Pop elements :

    FIFO_Q_POP(my_fifo, elt);
    FIFO_Q_SIZE(my_fifo, iter, count);

    assert(elt == e2);
    assert(count == 2);
    assert(my_fifo->size == 2);

    FIFO_Q_POP(my_fifo, elt);
    FIFO_Q_SIZE(my_fifo, iter, count);
    assert(elt == e);
    assert(count == 1);
    assert(my_fifo->size == 1);

    FIFO_Q_POP(my_fifo, elt);
    FIFO_Q_SIZE(my_fifo, iter, count);
    assert(elt == e3);
    assert(count == 0);
    assert(my_fifo->size == 0);

    FIFO_Q_POP(my_fifo, elt);
    FIFO_Q_SIZE(my_fifo, iter, count);
    assert(elt == NULL);
    assert(count == 0);
    assert(my_fifo->size == 0);

    FIFO_Q_POP(my_fifo, elt);
    FIFO_Q_SIZE(my_fifo, iter, count);
    assert(elt == NULL);
    assert(count == 0);
    assert(my_fifo->size == 0);

    free(e);
    free(e2);
    free(e3);
    return 0;
}