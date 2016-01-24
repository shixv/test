#ifndef MY_KBHIT_H_
#define MY_KBHIT_H_


#include <stdio.h>
#include <termios.h>
#include <term.h>
#include <curses.h>
#include <unistd.h>
#include <stdlib.h>

struct termios initial_settings, new_settings;
int peek_character = -1;
void init_keyboard(void);
void close_keyboard(void);
int kbhit(void);
int readch(void);

#endif
