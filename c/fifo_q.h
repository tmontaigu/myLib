#ifndef FIFO_Q_H
#define FIFO_Q_H

#define FIFO_Q_ADD(fifo, elt) \
    do {                        \
        if ((fifo)->tail) {    \
            (elt)->prev = NULL;\
            (elt)->next = ((fifo)->tail);\
            ((fifo)->tail)->prev = (elt);\
            (fifo)->tail = (elt);\
            (fifo)->size += 1;\
        }\
        else {\
            (elt)->next = NULL;\
            (elt)->prev = NULL; \
            (fifo)->head = (elt);\
            (fifo)->tail = (elt);\
            (fifo)->size = 1;\
        }\
    } while (0)


#define FIFO_Q_POP(fifo, out) \
    do {\
        if ((fifo)->head == NULL) {\
            (out) = NULL;\
        }\
        else if ((fifo)->head == (fifo)->tail) { \
            (out) = ((fifo)->head);\
            (out)->next = NULL;\
            (out)->prev = NULL;\
            (fifo)->tail = NULL;\
            (fifo)->head = NULL;\
            (fifo)->size = 0; \
        } \
        else {\
            (out) = ((fifo)->head);\
            (fifo)->head = (((fifo)->head)->prev);\
            ((fifo)->head)->next = NULL; \
            (out)->prev = NULL;\
            (out)->next = NULL;\
            (fifo)->size -= 1; \
        }\
    } while (0)


#define FIFO_Q_SIZE(fifo, iter,counter)  \
    do { \
        (counter) = 0;\
        (iter) = ((fifo)->tail);\
        while(iter != NULL) {\
            (++counter);\
            (iter) = ((iter)->next);\
        }\
    } while (0)


struct fifo_element {
    int a;
    struct fifo_element *next;
    struct fifo_element *prev;
};

struct fifo {
    struct fifo_element *head;
    struct fifo_element *tail;
    unsigned int size;
};

#endif