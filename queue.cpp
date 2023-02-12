#ifndef QUEUEARMOR
#include "queue.hpp"
#define QUEUEARMOR
#endif

void queue_ctor (struct queue* myQueue) {
    myQueue->buffer = (type*) calloc (QUEUE_LENGTH, sizeof(type));
    myQueue->head = 1;
    myQueue->tail = 1;
    for (int i = 0; i < QUEUE_LENGTH; i++) {
        myQueue->buffer[i] = POISON;
    }
}//мб залить все Poison, а потом проверять при добавление элемента 

void queue_dtor (struct queue* myQueue) {
    for (int i = 0; i < QUEUE_LENGTH; i++) {
        myQueue->buffer[i] = POISON;
    }
    free (myQueue->buffer);
    myQueue->head = 0;
    myQueue->tail = 0;
}

void queue_push (struct queue* myQueue, type n) {
    if (myQueue->numOfQueue == QUEUE_LENGTH) {
        myQueue->errors += ERRORQUEUEISOVERFLOW;
        printf ("ERRORCODE: %d ERRORQUEUEISOVERFLOW\n", myQueue->errors);
        queue_print (*myQueue);
        exit (0);
    }

    myQueue->buffer[myQueue->tail] = n;
    myQueue->tail++;
    myQueue->numOfQueue++;

    myQueue->tail=myQueue->tail & QUEUE_MASK;
}

type queue_pop (struct queue* myQueue) {
    if (myQueue->numOfQueue == 0) {
        myQueue->errors += ERRORQUEUEISEMPTY;
        printf ("ERRORCODE: %d ERRORQUEUEISEMPTY\n", myQueue->errors);
        queue_print (*myQueue);
        exit (0);
    }

    int n = 0;
    n = myQueue->buffer[myQueue->head];
    myQueue->buffer[myQueue->head] = POISON;
    myQueue->head++;
    myQueue->numOfQueue--;

    myQueue->head=myQueue->head & QUEUE_MASK;

    return n;
}

void queue_print (struct queue myQueue) {
    for (int i = 0; i < QUEUE_LENGTH; i++) {
        printf(TYPE_SPECIFIER, myQueue.buffer[i]);
        printf(" ");
    }
    printf("\n");
}

int scanf_check (int x) {
    if (x == 0) {
        printf ("Undefined command\n");
        while (getchar() != '\n');

        return 0;
    }

    return 1;
}