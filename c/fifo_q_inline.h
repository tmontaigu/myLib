#ifndef FIFO_Q_H
#define FIFO_Q_H

#include <stdlib.h>

#if defined(__cplusplus)
extern "C" {
#endif

#define FIFO_QUEUE_TYPE(name)             \
  struct fifo_q_ ## name *

#define DECL_FIFO_QUEUE(name, type)       \
    struct fifo_q_ ## name {              \
        unsigned int size;                \
        type *head;                       \
        type *tail;                       \
  };                                      \
    static struct fifo_q_ ## name *fifo_q_ ## name ## _new() { \
        struct fifo_q_ ## name *fifo = (struct fifo_q_ ## name*) malloc(sizeof(struct fifo_q_ ## name));\
        fifo->head = NULL;\
        fifo->tail = NULL;\
        fifo->size = 0;\
        return fifo;\
    }\
    static inline void fifo_q_ ## name ## _put(struct fifo_q_ ## name *fifo, type *elt) {\
        if (fifo->tail) {\
            elt->prev = NULL;\
            elt->next = NULL;\
            fifo->tail->prev = elt;\
            fifo->tail = elt;\
            fifo->size +=1;\
        }\
        else {\
            elt->next = NULL;\
            elt->prev = NULL; \
            fifo->head = elt;\
            fifo->tail = elt;\
            fifo->size = 1;\
        }\
    }\
    static inline type* fifo_q_ ## name  ## _pop(struct fifo_q_ ## name *fifo) {\
        if (fifo->head == NULL) {\
            return NULL;\
        }\
        else if (fifo->head == fifo->tail) {\
            type *e = fifo->head;\
            e->next = NULL;\
            e->prev = NULL;\
            fifo->tail = NULL;\
            fifo->head = NULL;\
            fifo->size = 0;\
        }\
        else {\
            type *e = fifo->head;\
            fifo->head = e->next;\
            fifo->head->next = NULL;\
            e->next = NULL;\
            e->prev = NULL;\
            fifo->size -= 1;\
        }\
    }


#define fifo_q_new(name) fifo_q_ ## name ## _new()
#define fifo_q_put(name, queue, item) fifo_q_ ## name ## _put(queue, item)
#define fifo_q_pop(name, queue) fifo_q_ ## name ##_pop(queue)

#if defined(__cplusplus)
}
#endif

#endif