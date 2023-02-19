#include "queue.hpp"

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
    myQueue->buffer = nullptr;
    myQueue->head = 0;
    myQueue->tail = 0;
}

void queue_push (struct queue* myQueue, type n) {
    if (myQueue->numOfQueue == QUEUE_LENGTH) {
        myQueue->errors += ERROR_QUEUE_IS_OVERFLOW;
        printf ("ERROR_CODE: %d ERROR_QUEUE_IS_OVERFLOW\n", myQueue->errors);
        queue_print (*myQueue);
        queue_dtor (myQueue);

        return;
    }

    myQueue->buffer[myQueue->tail] = n;
    myQueue->tail++;
    myQueue->numOfQueue++;

    myQueue->tail=myQueue->tail & QUEUE_MASK;
}

type queue_pop (struct queue* myQueue) {
    if (myQueue->numOfQueue == 0) {
        myQueue->errors += ERROR_QUEUE_IS_EMPTY;
        printf ("ERROR_CODE: %d ERROR_QUEUE_IS_EMPTY\n", myQueue->errors);
        queue_print (*myQueue);
        queue_dtor (myQueue);
        
        return POISON;
    }

    int n = 0;
    n = myQueue->buffer[myQueue->head];
    myQueue->buffer[myQueue->head] = POISON;
    myQueue->head++;
    myQueue->numOfQueue--;

    myQueue->head=myQueue->head & QUEUE_MASK;

    return n;
}

int queue_print (struct queue myQueue) {
    if (myQueue.buffer == nullptr) {
        return 0;
    }

    for (int i = 0; i < QUEUE_LENGTH; i++) {
        printf(TYPE_SPECIFIER, myQueue.buffer[i]);
        printf(" ");
    }
    printf("\n");
    return 1;
}

int scanf_check (int x) {
    if (x == 0) {
        printf ("Undefined command\n");
        while (getchar() != '\n');

        return 0;
    }

    return 1;
}
