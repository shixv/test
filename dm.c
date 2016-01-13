#include <unistd.h>
#include <locale.h>
#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define TOTALNUM 65

void randout(char **s,char **ret,int n);
int main(void)
{
	setlocale(LC_ALL,"");
	FILE *p=fopen("name","r");
	char **s=(char **)malloc(sizeof(char *)*TOTALNUM);
	for(int i=0;i<TOTALNUM;i++)
	{
		s[i]=(char *)malloc(sizeof(char )*20);
		fscanf(p,"%s",s[i]);
	}
	fclose(p);
	srand((unsigned int)time(0));
	char *re=(char *)malloc(sizeof(char)*20);
	initscr();
	move(0,0);
	for(int i=0;i<TOTALNUM-1;i++)
	{
		randout(s,&re,TOTALNUM);
		move(rand()%27,rand()%90);
		switch(rand()%6){
			case 0:
				printw("%s正在傻笑",re);
				break;
			case 1:
				printw("%s正在写代码",re);
				break;
			case 2:
				printw("%s正在说梦话",re);
				break;
			case 3:
				printw("%s正在磨牙",re);
				break;
			case 4:
				printw("%s正在打呼噜",re);
				break;
			case 5:
				printw("%s正在翻滚中",re);
				break;
		}
		refresh();
		usleep(90000);
	}
	randout(s,&re,TOTALNUM);
	move(rand()%20,rand()%80);
	printw("->%s被老师抓住了!!!!!!<-",re);
	refresh();
	for(int i=0;i<TOTALNUM;i++)
	{
		free(s[i]);
	}
	free(s);
	getchar();
	return 0;
}
void randout(char **s,char **ret,int n)
{
	int i=0;
	int ran;
R:	ran=rand()%TOTALNUM;
	if(s[ran]!=NULL)
	{
		if(i==n)
		{
			*ret=NULL;
			return;
		}
		strcpy(*ret,s[ran]);
		s[ran]=NULL;
		i++;
	}
	else
	{
		goto R;
	}
}
