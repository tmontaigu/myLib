#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "fifo_q.h"


int main(int argc, char **argv) {

    struct fifo *fifo = malloc(sizeof * fifo);
    fifo->head = NULL;
    fifo->tail = NULL;

    struct fifo_element *e;

    for (int i = 0; i < 100; i++)
    {
        e = malloc(sizeof * e);
        e->next = NULL;
        e->a = i;


        FIFO_Q_ADD(fifo, e);
        assert(fifo->size == i+1);
    }


    for (int i = 0; i < 100; i++)
    {
        FIFO_Q_POP(fifo, e);
        assert(fifo->size == 100 - (i+1));
        assert(e->a == i);

        free(e);
    }

    free(fifo);
    return 0;
}