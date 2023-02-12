#ifndef QUEUEARMOR
#include "queue.hpp"
#define QUEUEARMOR
#endif

int main () {
    struct queue numbers;
    int command = -1;
    type push_value = 0;
    type pop_value = 0;

    queue_ctor (&numbers); 
    printf ("henlo, it's menu for queue\n");
    printf ("1 num - push number\n");
    printf ("2 - pop number\n");
    printf ("3 - print queue\n");
    printf ("4 - menu\n");
    printf ("5 - quit\n");

    while (!scanf_check(scanf("%d", &command)));

    while (command != 0) {
        switch (command) {
            case 0:
                break;
            case 1:
                if (!scanf_check(scanf (TYPE_SPECIFIER, &push_value))) {
                    break;
                }
                queue_push (&numbers, push_value);
                break;
            case 2:
                pop_value = queue_pop (&numbers);
                printf ("POP VALUE: %d\n", pop_value);
                break;
            case 3:
                queue_print(numbers);
                break;
            case 4:
                printf ("1 num - push number\n");
                printf ("2 - pop number\n");
                printf ("3 - print queue");
                printf ("4 - menu\n");
                printf ("5 - quit\n");
                break;
            case 5:
            default:
                printf ("Undefined command\n");
                break;
        }
        queue_print(numbers);
        while (!scanf_check(scanf("%d", &command)));
    }
    queue_dtor (&numbers);

    return 0;
}
