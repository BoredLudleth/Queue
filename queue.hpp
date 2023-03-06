#ifndef QUEUE_ARMOR
#define QUEUE_ARMOR

#include <stdio.h>
#include <stdlib.h>

typedef int type;
#define TYPE_SPECIFIER "%d"

#define QUEUE_LENGTH 128  //it must be a power of 2
#define QUEUE_MASK 127
#define POISON 0xDEAD

#define DBG printf("FILE:%s FUNC:%s LINE:%d\n", __FILE__, __FUNCTION__, __LINE__);

struct queue {
    type* buffer = nullptr;
    size_t head = 0;
    size_t tail = 0;
    int numOfQueue = 0;
    char errors = 0;
    //выбрать счетчик элементов или запоминание последней операции?
};

enum Errors {
    ERROR_QUEUE_IS_OVERFLOW = 1,
    ERROR_QUEUE_IS_EMPTY    = 2,
};

void queue_ctor (struct queue* myQueue);

void queue_dtor (struct queue* myQueue);

void queue_push (struct queue* myQueue, type n);

type queue_pop (struct queue* myQueue);

int queue_print (struct queue myQueue);

void queue_check (struct queue myQueue);

int scanf_check (int x);

#endif