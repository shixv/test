#ifndef SNAKE_H_
#define SNAKE_H_

typedef struct snake {
	int id;
	int x;
	int y;
} snake_t;

typedef struct rub rub_t; 

struct rub {
	int y;
	int x;
};

int head;
int tail;
#define PAGE 4096

snake_t snake_q[PAGE];
void quick_sort_scores(int*, int*);
#if 0
struct termios initial_settings, new_settings;
int peek_character = -1;
void init_keyboard();
void close_keyboard();
int kbhit();
int readch();
#endif


#endif
