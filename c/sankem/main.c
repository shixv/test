#include "snake.h"
#include "queue.h"
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>

#define Swap(x, y)  do{ \
	(x) ^= (y); \
	(y) ^= (x); \
	(x) ^= (y); \
}while(0)


#define ESCAPE 27
#define ENTER 10

#define MONEY_FQCY  4  //宝藏出现频率 值越小 频率越高 最小为1
#define MONEY_TIME  3  //宝藏持续时间
#define SPEED       2  //移动速度
#define GAME_WIN_XLEN ((LINES) - (20))
#define GAME_WIN_YLEN ((COLS) - (25))
#define GAME_WIN_X_START 10
#define GAME_WIN_Y_START 10    

#define SNAKE_COLOR 1
#define SCORE_COLOR 2
#define MSG_COLOR 3
#define MENU_COLOR 4
#define SHORT_KEY 5
#define ALERT_COLOR 6
#define _3D_COLOR 7

#define RECORD 5   //记录个数

void print_snake(WINDOW *game_bar, int head, int tail);
void change_xy(int head, int tail);
int is_hit(void);
int is_point_on_snake(int x, int y);
extern void init_keyboard(void);
extern void close_keyboard(void);
extern int readch(void);
extern int kbhit(void);
int fill_rectangle(WINDOW *wiin, int start_y, int start_x, int end_y, int end_x, int chtype);
int Box(WINDOW *win, int start_y, int start_x, int end_y, int end_x, int attrs);
int draw_3D_window(WINDOW *win, int start_y, int start_x, int end_y, int end_x, int attrs);


int main(void)
{
	//--------------------------------------------------变量-------------------------------------
	/*记录信息*/
	int SCORE[RECORD];

	/*记录文件信息*/
	FILE *load;
	FILE *save;

	/*主选项命令*/
	int host_option;

	/*键盘输入的方向命令*/
	int key; 
	/*上一次键盘的命令*/
	int pre_key;

	/*食物坐标*/
	int goal_x, goal_y;

	/*宝藏坐标*/
	int money_x, money_y;
	int last_money_x = 0, last_money_y = 0; //上次宝藏坐标

	/*尾巴节点坐标*/
	int last_x, last_y;

	/*键盘接收的字符*/
	int ch;

	/*控制闪烁变量*/
	int contrl_blink = 0;

	/*新加入的节点*/
	snake_t new;

	/*积分*/
	int score = 0;

	/*时间差*/
	time_t timer_money_start;
	time_t timer_money_end;
	struct tm* t_tm_start;
	struct tm* t_tm_end;
	int temp_time;

	/*宝藏指标*/
	int money_ok = 1;     //当 money_ok到达3 则宝藏出现
	int make_money = MONEY_FQCY;

	/*循环变量*/
	int i, j;

	//----------------------------------------------------------------------------------------------

	////////////////////////////////////////////////////////////////////////
	/*初始化标准窗口*/
	initscr();        //初始化窗口指针
	cbreak();         //无缓冲
	curs_set(0);      //屏蔽光标
	noecho();         //屏蔽字符打印到标准输出
	keypad(stdscr, TRUE);//激活按键
	start_color();

	/*颜色对*/
	init_pair(SCORE_COLOR, COLOR_GREEN, COLOR_BLACK);   //2. 绿字  黑底
	init_pair(SNAKE_COLOR, COLOR_YELLOW, COLOR_BLACK);  //1. 黄字  黑底
	init_pair(MSG_COLOR, COLOR_WHITE, COLOR_BLUE);      //3. 白字  蓝低
	init_pair(MENU_COLOR, COLOR_BLUE, COLOR_WHITE);     //4. 篮字  白底
	init_pair(SHORT_KEY, COLOR_RED, COLOR_WHITE);       //5. 红字  白底
	init_pair(ALERT_COLOR, COLOR_WHITE, COLOR_RED);     //6. 红低  白字
	init_pair(_3D_COLOR, COLOR_BLUE, COLOR_BLUE);     //7. 白自  黑低

	/* 读记录*/
	load = fopen("./hi_scores", "r");
	if(load == NULL) {
		perror("Open file <hi_socres>");
		printf("errno: %d\n", errno);
		exit(-1);
	}
	fread(SCORE, sizeof(int), RECORD, load);
	fclose(load);
	quick_sort_scores(&SCORE[0], &SCORE[RECORD - 1]);

	while(1) {

		/////////////////////////////初始化蛇/////////////////
		head = tail = 0;
		score = 0;

		/*默认起始方向为右*/
		pre_key = KEY_RIGHT;
		key = KEY_RIGHT;

		/*定义蛇头并加入蛇队列*/
		snake_t snake_head = {0, GAME_WIN_XLEN / 2, GAME_WIN_YLEN / 2};    
		enqueue(snake_head);
		/*插入蛇身4个节点*/
		for(i = 1; i < 5; i++) {
			new.id = tail;
			new.x = GAME_WIN_XLEN / 2;
			new.y = GAME_WIN_YLEN / 2 - i;
			enqueue(new);
		}
		///////////////////初始化蛇结束//////////////////////////


		////////////////////////////////////展示界面////////////////////////////////////////
		bkgd(COLOR_PAIR(MSG_COLOR));  

		/*积分栏*/
		WINDOW *integral_bar;
		integral_bar = newwin(3, 10, GAME_WIN_X_START - 3, (GAME_WIN_YLEN - GAME_WIN_Y_START) / 2 + 10);
		wbkgd(integral_bar, COLOR_PAIR(SCORE_COLOR));
		box(integral_bar,0 ,0);

		mvwprintw(integral_bar,1 ,3, "%03d", score);
		wrefresh(integral_bar);
		overwrite(integral_bar, stdscr);
		touchwin(stdscr);

		/*游戏栏*/
		WINDOW *game_bar;
		game_bar = newwin(GAME_WIN_XLEN, GAME_WIN_YLEN, GAME_WIN_X_START, GAME_WIN_Y_START);
		mvwprintw(game_bar, 0, 2, "GAME");
		wbkgd(game_bar, COLOR_PAIR(SNAKE_COLOR));
		box(game_bar, 0, 0);

		wrefresh(game_bar);
		overwrite(game_bar, stdscr);    
		touchwin(stdscr);

		/*消息栏*/
		WINDOW *massage_bar;
		massage_bar = newwin(LINES / 4, COLS / 2, LINES / 4 * 3 + 3, COLS / 4);
		wbkgd(massage_bar, COLOR_PAIR(MSG_COLOR));
		box(massage_bar, 0, 0);

		mvwprintw(massage_bar, 0, 27, "%s", "Message");
		mvwprintw(massage_bar, 1, 1, "--CONTROL--");
		mvwprintw(massage_bar, 3, 2, "'w' -> [UP], 's' -> [DOWN] , 'a' -> [LEFT] , 'd' -> [RIGHT]");
		mvwprintw(massage_bar, 5, 1, "--OPTION--");
		mvwprintw(massage_bar, 7, 2, "[SPEED]: %s   [MOENY]: %s    'q' -> [Restart game]", (SPEED > 100000)? "Slow": (SPEED > 10000 ? "Normal":"Fast"), (MONEY_FQCY > 6?"Little" :(MONEY_FQCY > 3 ?"Normal" : "So Much")));
		wrefresh(massage_bar);
		overwrite(massage_bar, stdscr);
		touchwin(stdscr);

		/*菜单栏*/
		WINDOW *menu_bar;
		menu_bar = newwin(1, COLS, 0, 0);
		wbkgd(menu_bar, COLOR_PAIR(MENU_COLOR));

		mvwprintw(menu_bar, 0, 2, "START");
		wattron(menu_bar, COLOR_PAIR(SHORT_KEY));
		mvwprintw(menu_bar, 0, 7, "[F2]");
		wattroff(menu_bar, COLOR_PAIR(SHORT_KEY));

		mvwprintw(menu_bar, 0, 15, "HIGH SCORE");
		wattron(menu_bar, COLOR_PAIR(SHORT_KEY));
		mvwprintw(menu_bar, 0, 25, "[F3]");
		wattroff(menu_bar, COLOR_PAIR(SHORT_KEY));
		mvwprintw(menu_bar, 0, 32, "QUIT");
		wattron(menu_bar, COLOR_PAIR(SHORT_KEY));
		mvwprintw(menu_bar, 0, 36, "[ESC]");
		wattroff(menu_bar, COLOR_PAIR(SHORT_KEY));

		wrefresh(menu_bar);
		overwrite(menu_bar, stdscr);
		touchwin(stdscr);

		/*提示栏*/

		WINDOW *alert_bar;

		alert_bar = newwin(15, 50, LINES / 2 - 7, COLS / 2 - 25);
		draw_3D_window(alert_bar, 0, 0, getmaxy(alert_bar) - 2, getmaxx(alert_bar) - 2, COLOR_PAIR(ALERT_COLOR));
		Box(alert_bar, 0, 0, getmaxy(alert_bar) -2, getmaxx(alert_bar) - 2, A_BOLD);

		mvwprintw(alert_bar, 0, 20, "  ALERT  ");
		wattron(alert_bar, A_BOLD|A_UNDERLINE|COLOR_PAIR(ALERT_COLOR));
		mvwprintw(alert_bar, 3, 15, "Welcome to Sanke game");
		wattroff(alert_bar,A_BOLD|A_UNDERLINE|COLOR_PAIR(ALERT_COLOR));
		wattron(alert_bar,COLOR_PAIR(ALERT_COLOR));
		mvwprintw(alert_bar, 5, 10, "F[2]------\"Start Game\"");
		mvwprintw(alert_bar, 7, 10, "F[3]------\"See the high score\"");
		mvwprintw(alert_bar, 9,10,  "[Esc]-----\"QUIT\"");
		wattroff(alert_bar, COLOR_PAIR(ALERT_COLOR));
		wrefresh(alert_bar);
		overwrite(alert_bar, stdscr);
		touchwin(stdscr);

		host_option = getch();
		///////////////////////////////////////////////展示界面结束/////////////////////////// 

		switch (host_option) {
			case KEY_F(2): {

							   ///////////////////开始游戏/////////////////////////////////////////////

							   /*初始化kbhit kbhit()为响应当键盘打击时的事件*/
							   init_keyboard(); 

							   /*打印蛇*/
							   print_snake(game_bar, head, tail);
							   wrefresh(game_bar);

							   /*随机生成食物坐标*/
							   srand(time(0));
							   do {
								   goal_x = rand() % (GAME_WIN_XLEN - 10) + 2;
								   goal_y = rand() % (GAME_WIN_YLEN - 10) + 2;
							   }while(is_point_on_snake(goal_x, goal_y));

							   do {

								   /*随机生成宝藏坐标，每间隔3秒，宝藏位置改变*/
								   if(make_money == money_ok) {
									   do {
										   money_x = rand() % (GAME_WIN_XLEN - 10) + 2;
										   money_y = rand() % (GAME_WIN_YLEN - 10) + 2;
									   } while(is_point_on_snake(money_x, money_y));

									   time(&timer_money_end);
									   t_tm_end = localtime(&timer_money_end);
									   temp_time = t_tm_end->tm_sec;
									   make_money += MONEY_FQCY;
								   }
								   if(money_ok % MONEY_FQCY == 0) {
									   if(t_tm_end->tm_sec < temp_time)
										   temp_time = 0;
									   time(&timer_money_end);
									   t_tm_end = localtime(&timer_money_end);
									   if((t_tm_end->tm_sec - temp_time) > MONEY_TIME) {
										   money_ok += 1;
										   money_x = 0;
										   money_y = 0;
									   }
								   }

								   /*显示积分窗口*/
								   mvwprintw(integral_bar,1 ,3, "%03d", score);
								   wrefresh(integral_bar);
								   overwrite(integral_bar, stdscr);
								   touchwin(stdscr);

								   /*显示游戏窗口*/
								   box(game_bar, 0, 0);
								   mvwprintw(game_bar, 0, GAME_WIN_YLEN / 2 - 6, "~~SNAKE GAME~~");
								   wbkgd(game_bar, COLOR_PAIR(1));

								   wrefresh(game_bar);
								   overwrite(game_bar, stdscr);
								   touchwin(stdscr);

								   /*打印闪烁宝藏目标*/
								   if(money_ok % MONEY_FQCY == 0) {
									   last_money_x = money_x;
									   last_money_y = money_y;
									   ++contrl_blink;
									   if(contrl_blink == 2)
										   contrl_blink = 0;
									   wmove(game_bar, money_x, money_y);
									   if(contrl_blink == 0)
										   waddch(game_bar, '$'| A_REVERSE);
									   else 
										   waddch(game_bar, '$');
								   }
								   else {
									   wmove(game_bar, last_money_x, last_money_y);
									   waddch(game_bar, ' ');
									   last_money_x = 0;
									   last_money_y = 0;
								   }
								   /*打印食物目标*/
								   wmove(game_bar, goal_x, goal_y);
								   waddch(game_bar, '@'|A_BOLD);
								   // wprintw(game_bar, "(%d,%d)", goal_x, goal_y);

								   print_snake(game_bar, head, tail);
								   /*
									  wmove(game_bar, 2,2);
									  for(i = 0 ; i < 10; i++) {
									  wprintw(game_bar, "(rub[%d].x = %d rub[%d].y = %d )\n" ,i, rub1[i].x, i, rub1[i].y);
									  }
									  wmove(game_bar, 1,1);
									  wprintw(game_bar, "GAME_WIN_LENx = %d GAME_WIN_LENy = %d", GAME_WIN_XLEN, GAME_WIN_YLEN);
									  */

								   wrefresh(game_bar);
								   /*备份蛇尾坐标*/
								   last_x = snake_q[tail - 1].x;
								   last_y = snake_q[tail - 1].y;

								   /*程序挂起1ms*/
								   usleep(SPEED);

								   /*键盘响应 并接收响应字符*/
								   if(kbhit()){
									   ch = 0;
									   ch = readch();
								   } 
								   /*按键[Q] 退出*/
								   if(ch == 'q'){
									   break;
								   }
								   /*判断接受的字符，并做出相对应移动*/
								   if(ch == 'w' || ch == 's' || ch == 'd' || ch == 'a') {
									   if(ch == 'w')
										   key = KEY_UP;
									   else if(ch == 's')
										   key = KEY_DOWN;
									   else if(ch == 'd')
										   key = KEY_RIGHT;
									   else if(ch == 'a')
										   key = KEY_LEFT;
									   if((key == KEY_RIGHT) && (pre_key != KEY_LEFT)) {
										   change_xy(head, tail);  //除头结点， 其他节点坐标相对蛇头前移
										   pre_key = key;          //记录上次命令
										   if(snake_q[head].y + 1 == GAME_WIN_YLEN - 1 || snake_q[head].y > GAME_WIN_YLEN - 1) 
											   snake_q[head].y = GAME_WIN_X_START - 9;
										   else
											   (snake_q[head].y)++;
									   }
									   else if((key == KEY_LEFT) && (pre_key != KEY_RIGHT)) {
										   change_xy(head, tail);
										   pre_key = key;
										   if(snake_q[head].y == GAME_WIN_X_START - 9 || snake_q[head].y - 1 < GAME_WIN_X_START - 9)
											   snake_q[head].y = GAME_WIN_YLEN - 2;
										   else
											   (snake_q[head].y)--;
									   }
									   else if((key == KEY_DOWN) && (pre_key != KEY_UP)) {
										   change_xy(head, tail);
										   pre_key = key;
										   if(snake_q[head].x + 1 == GAME_WIN_XLEN - 1 || snake_q[head].x + 1 > GAME_WIN_XLEN - 1)
											   snake_q[head].x = GAME_WIN_Y_START - 9;
										   else
											   (snake_q[head].x)++;
									   }
									   else if((key == KEY_UP) && (pre_key != KEY_DOWN)) {
										   change_xy(head, tail);
										   pre_key = key;
										   if(snake_q[head].x == GAME_WIN_Y_START - 9 || snake_q[head].x - 1 < GAME_WIN_Y_START - 9)
											   snake_q[head].x = GAME_WIN_XLEN - 2;
										   else
											   (snake_q[head].x)--;
									   }
								   }
								   /*当没接收到键盘响应，默认执行上次命令方向*/
								   else {
									   if(pre_key == KEY_RIGHT) {
										   change_xy(head, tail);
										   if(snake_q[head].y + 1 == GAME_WIN_YLEN - 1 || snake_q[head].y > GAME_WIN_YLEN - 1)
											   snake_q[head].y = GAME_WIN_X_START - 9;
										   else
											   (snake_q[head].y)++;
									   }
									   else if(pre_key == KEY_LEFT) {
										   change_xy(head, tail);
										   if(snake_q[head].y == GAME_WIN_X_START - 9 || snake_q[head].y - 1 < GAME_WIN_X_START - 9)
											   snake_q[head].y = GAME_WIN_YLEN - 2;
										   else
											   (snake_q[head].y)--;
									   }
									   else if(pre_key == KEY_DOWN) {
										   change_xy(head, tail);
										   if(snake_q[head].x + 1 == GAME_WIN_XLEN - 1 || snake_q[head].x + 1 > GAME_WIN_XLEN - 1)
											   snake_q[head].x = GAME_WIN_Y_START - 9;
										   else
											   (snake_q[head].x)++;
									   }
									   else if(pre_key == KEY_UP) {
										   change_xy(head, tail);
										   if(snake_q[head].x == GAME_WIN_Y_START - 9 || snake_q[head].x - 1 < GAME_WIN_Y_START - 9)
											   snake_q[head].x = GAME_WIN_XLEN - 2;
										   else
											   (snake_q[head].x)--;
									   }
								   }
								   wrefresh(game_bar);

								   /*判断是否撞击蛇身, 撞击则退出*/
								   if(is_hit()) {
									   wmove(game_bar, GAME_WIN_XLEN / 2, GAME_WIN_YLEN / 2 - 8);
									   wprintw(game_bar, "----YOU LOSE-----");
									   wrefresh(game_bar);
									   sleep(3);
									   wmove(game_bar, GAME_WIN_XLEN / 2, GAME_WIN_YLEN / 2);
									   wattron(game_bar, A_BOLD);
									   wprintw(game_bar, "BYE---- WELCOME TO PLAY AGAIN score = %d", score);
									   wattroff(game_bar, A_BOLD);
									   wrefresh(game_bar);
									   getch();
									   break;
								   }
								   /*判断是否吃到食物, 吃到则将新节点入队*/
								   if((snake_q[head].x == goal_x) && (snake_q[head].y == goal_y)) {
									   new.id = tail;
									   new.x = last_x;
									   new.y = last_y;
									   enqueue(new);
									   do {
										   goal_x = rand() % (GAME_WIN_XLEN - 10 ) + 2;
										   goal_y = rand() % (GAME_WIN_YLEN - 10 ) + 2;
									   } while(is_point_on_snake(goal_x, goal_y));
									   score += 1;
									   money_ok += 1;
								   }
								   /*判断是否吃到宝藏，吃到则加分，但不生成新节点*/
								   if((snake_q[head].x == money_x) && (snake_q[head].y == money_y)) {
									   do {
										   money_x = rand() % (GAME_WIN_XLEN - 10) + 2;
										   money_y = rand() % (GAME_WIN_XLEN - 10) + 2;
									   } while(is_point_on_snake(money_x, money_y));

									   score += 10;
									   time(&timer_money_start);
									   t_tm_start = localtime(&timer_money_start);
									   temp_time = t_tm_start->tm_sec;
								   }
								   //    wclear(game_bar);   
								   //   clear();
							   } while(1);

							   /*判断当前所得分数是否进去排行榜*/

							   for(i = 0; i < RECORD; i++) {
								   if(score >= SCORE[i]) {
									   for(j = RECORD - 1; j > i; j--) {
										   SCORE[j] = SCORE[j - 1];
									   }
									   SCORE[i] = score;
									   break;
								   }
							   }

							   /*存储记录*/
							   save = fopen("hi_scores", "w");
							   if(save == NULL) {
								   perror("Open the file <hi_scores>");
								   printf("errno is %d\n", errno);
							   }
							   ch = 0;
							   fwrite(SCORE, sizeof(int), RECORD, save);
							   fclose(save);

							   /*打印本局所得分数(未实现)*/ 
							   /*
								  wclear(game_bar);
								  draw_3D_window(game_bar, 0, 0, 6, getmaxx(game_bar) - 2, COLOR_PAIR(ALERT_COLOR));
								  Box(game_bar, 0, 0, 6, getmaxx(game_bar) - 2, A_BOLD);
								  mvwprintw(game_bar, 0, 20, "   Your Score  ");
								  wattron(game_bar, COLOR_PAIR(ALERT_COLOR)|A_BOLD);
								  mvwprintw(game_bar, 3, 13, "You get %d scores", score);
								  wattroff(game_bar, COLOR_PAIR(ALERT_COLOR|A_BOLD));
								  wrefresh(game_bar);
								  endwin();
								  getch();
								  */

							   delwin(game_bar);
							   ///////////////////////////////////结束游戏////////////////////////////////////////////
						   }
						   break;
			case KEY_F(3): {
							   //high scores

							   load = fopen("hi_scores", "r");
							   if(load == NULL) {
								   perror("Open file <hi_socres>");
								   printf("errno: %d\n", errno);
								   exit(-1);
							   }
							   fread(SCORE, sizeof(int), RECORD, load);
							   fclose(load);
							   quick_sort_scores(&SCORE[0], &SCORE[RECORD - 1]);
							   wclear(alert_bar);
							   draw_3D_window(alert_bar, 0, 0, getmaxy(alert_bar) - 2, getmaxx(alert_bar) - 2, COLOR_PAIR(ALERT_COLOR));
							   Box(alert_bar, 0, 0, getmaxy(alert_bar) -2, getmaxx(alert_bar) - 2, A_BOLD);
							   mvwprintw(alert_bar, 0, 18, " HIGH SCORES ");
							   wattron(alert_bar, COLOR_PAIR(ALERT_COLOR));
							   for(i = 0; i < RECORD; i++) {
								   mvwprintw(alert_bar, (i + 1) * 2, 15, "[%d]Score:     %d", i + 1, SCORE[i]);
							   }
							   mvwprintw(alert_bar, 12, 12, "PRESS [ANY-KEY] to continue");
							   wattron(alert_bar, COLOR_PAIR(ALERT_COLOR));
							   wrefresh(alert_bar);
							   getch();
						   }
						   break;
			case KEY_F(12): {
								/*清零记录*/
								for(i = 0; i < RECORD; i++) {
									SCORE[i] = 0;
								}
								save = fopen("hi_scores", "w");
								if(save == NULL) {
									perror("Open the file <hi_scores>");
									printf("errno is %d\n", errno);
								}

								fwrite(SCORE, sizeof(int), RECORD, save);
								fclose(save);
								wclear(alert_bar);
								draw_3D_window(alert_bar, 0, 0, 6, getmaxx(alert_bar) - 2, COLOR_PAIR(ALERT_COLOR));
								Box(alert_bar, 0, 0, 6, getmaxx(alert_bar) - 2, A_BOLD);
								mvwprintw(alert_bar, 0, 20, "   CLEAR  ");
								wattron(alert_bar, COLOR_PAIR(ALERT_COLOR)|A_BOLD);
								mvwprintw(alert_bar, 3, 13, "All scores to CLEAR!!!!");
								wattroff(alert_bar, COLOR_PAIR(ALERT_COLOR|A_BOLD));
								wrefresh(alert_bar);
								getch();
							}
							break;
			case ESCAPE: {
							 endwin();
							 exit(0);
						 }
						 break;
			default: {
						 wclear(alert_bar);
						 draw_3D_window(alert_bar, 0, 0, 6, getmaxx(alert_bar) - 2, COLOR_PAIR(ALERT_COLOR));
						 Box(alert_bar, 0, 0, 6, getmaxx(alert_bar) - 2, A_BOLD);
						 mvwprintw(alert_bar, 0, 20, "   WRONG  ");
						 wattron(alert_bar, COLOR_PAIR(ALERT_COLOR)|A_BOLD);
						 mvwprintw(alert_bar, 3, 10, "Please ENTER [F2],[F3] or [ESC].");
						 wattroff(alert_bar, COLOR_PAIR(ALERT_COLOR|A_BOLD));
						 wrefresh(alert_bar);
						 getch();
					 }
					 break;
		}
	}

	//	close_keyboard();
	//	delwin(game_bar);
	//	delwin(integral_bar);
	endwin();

	return 0;
}

void print_snake(WINDOW *game_bar, int head, int tail)
{
	int i;
	for(i = head; i < tail; i++) {
		wmove(game_bar, snake_q[i].x, snake_q[i].y);
		// printw("%c", i == head ? '+': '.');

		if(i == head)
			waddch(game_bar,'+'|A_REVERSE);
		else if (i + 1 == tail)
			waddch(game_bar,' ');
		else if (i + 2 == tail)
			waddch(game_bar, '*'|A_BOLD);
		else
			waddch(game_bar,' '|A_REVERSE);

		/*
		   if(i == head) {
		   attron(COLOR_PAIR(1));
		   printw("%2s ","○");
		   attroff(COLOR_PAIR(1));
		   }
		   else if(i + 1 == tail) {
		   attron(COLOR_PAIR(2));
		   printw("★");
		   attroff(COLOR_PAIR(2));
		   }
		   else {
		   attron(A_REVERSE);
		   printw("☼");
		   attroff(A_REVERSE);
		   }
		   */
	}
}

void change_xy(int head, int tail)
{
	int i;

	for(i = tail - 1; i > head; i--) {
		snake_q[i].x = snake_q[i - 1].x;
		snake_q[i].y = snake_q[i - 1].y;
	}
}

int is_hit(void)
{
	int i;
	for(i = head + 1; i < tail; i++) {
		if((snake_q[i].x == snake_q[head].x) && (snake_q[i].y == snake_q[head].y))
			return 1;
	}

	return 0;
}

int is_point_on_snake(int x, int y)
{
	int i;

	for(i = head; i < tail; i++) {
		if(x == snake_q[i].x && y == snake_q[i].y)
			return 1;
	}
	return 0;
}

int fill_rectangle(WINDOW *win, int start_y, int start_x, int end_y, int end_x, int chtype)
{
	int i;

	if(NULL == win ||
			start_y < 0 || start_y >= getmaxy(win) ||
			start_x < 0 || start_x >= getmaxx(win) ||
			end_y   < 0 || end_y   >= getmaxy(win) ||
			end_x   < 0 || end_x   >= getmaxx(win))
		return ERR;
	else {
		if(end_y < start_y) Swap(end_y, start_y);       
		if(end_x < start_x) Swap(end_x, start_x);

		for(i = start_y; i <= end_y; i++) {
			mvwhline(win, i, start_x, chtype, end_x - start_x + 1);
		}
		return OK;
	}
}


int Box(WINDOW *win, int start_y, int start_x, int end_y, int end_x, int attrs)
{
	if(NULL == win ||
			start_y < 0 || start_y >= getmaxy(win) ||
			start_x < 0 || start_x >= getmaxx(win) ||
			end_y   < 0 || end_y   >= getmaxy(win) ||
			end_x   < 0 || end_x   >= getmaxx(win) ||
			abs(start_x - end_x) < 2 || abs(start_y - end_y) < 2 )
		return ERR;
	else {
		mvwhline(win, start_y, start_x + 1, ACS_HLINE|attrs, end_x - start_x - 1);
		mvwhline(win, end_y, start_x + 1, ACS_HLINE|attrs, end_x - start_x - 1);
		mvwvline(win, start_y + 1, start_x, ACS_VLINE|attrs, end_y - start_y - 1);
		mvwvline(win, start_y + 1, end_x, ACS_VLINE|attrs, end_y - start_y - 1);
		mvwaddch(win, start_y, start_x, ACS_ULCORNER|attrs);
		mvwaddch(win, start_y, end_x, ACS_URCORNER|attrs);
		mvwaddch(win, end_y, start_x, ACS_LLCORNER|attrs);
		mvwaddch(win, end_y, end_x, ACS_LRCORNER|attrs);
		return OK;
	}
}


int draw_3D_window(WINDOW *win, int start_y, int start_x, int end_y, int end_x, int attrs)
{
	if(NULL == win || 
			start_y < 0 || start_y >= getmaxy(win) - 1 ||
			end_y < 0 || end_y >= getmaxy(win) - 1 ||
			start_x < 0 || start_x >= getmaxx(win) - 1 ||
			end_x < 0 || end_y >= getmaxx(win) - 1)
		return ERR;
	else {
		init_pair(_3D_COLOR, COLOR_BLUE, COLOR_BLUE);
		fill_rectangle(win, start_y + 1, start_x + 1, end_y + 1, end_x + 1, ' '|COLOR_PAIR(_3D_COLOR));
		fill_rectangle(win, start_y, start_x, end_y, end_x, ' '|attrs);
		return OK;
	}
}

