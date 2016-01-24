#include "queue.h"
#include "snake.h"


void enqueue(snake_t p)
{
     snake_q[tail++] = p;
}

snake_t dequeue(void)
{
    return snake_q[head++];
}

int is_empty(void)
{
    return head == tail;
}

int is_full(void)
{
    return tail == PAGE;
}
