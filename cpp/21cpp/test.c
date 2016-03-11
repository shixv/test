#include "stack.h"
#include <stdio.h>
int main(void)
{
	Queue* q=initQueue();
	enque(q,1);
	enque(q,2);
	printf("%d,",head(q));
	deque(q);
	printf("%d,",head(q));
	freeQueue(q);
	return 0;
}
