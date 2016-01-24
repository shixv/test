#ifndef QUEUE_H_
#define QUEUE_H_

#include "snake.h"

void enqueue(snake_t p);
snake_t dequeue(void);
int is_empty(void);
int is_full(void);

#endif
