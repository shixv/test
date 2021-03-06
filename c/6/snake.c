#include <unistd.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <term.h>
#include <termios.h>

#define Shead 0
#define Sbody 1
#define Stail 2

#define N 0
#define W 1
#define S 2
#define E 3

static struct termios old,new;
static int peek_character=-1;
typedef struct snakenode
{
	int flag;      //0:head,1:body,2:tail;
	int xpos;
	int ypos;
	int direction;  //0:N,1:W,2:S,3:E;
	struct snakenode* next;
}SNode;

typedef struct randpoint
{
	int xpos;
	int ypos;
}RP;

int kbhit(void);
int readch(void);
void Printpoint(RP rp);
void Getborder(int *x,int *y);              //得到边界
void initkeyboard(void);       //初始化输入
void closekeyboard(void);      //回复输入
void Printscr(SNode *s);                    //打印一条蛇
void Convertborder(SNode *s,int x,int y);   //边界转换
void Randpoint(RP *p,SNode *s,int xmax,int ymax);//生成随机点
void Eatpoint(SNode **s,RP *p,int xmax,int ymax);//吃点 重写
void Freshsanke(SNode **s);//刷新这条蛇
void Freenode(SNode *s);//释放节点
void Printnode(SNode *s);//打印节点
void Initheadtail(SNode **s);//初始化头尾
void Addhead(SNode **s);//从头部增加长度
void Changedirection(SNode *s,int direction);//改变方向
int Checkhead(SNode *s,RP *p);//-1:end,0:continue,1:eat检查头部状态

int main(void)
{
	int XMax,YMax;
	Getborder(&XMax,&YMax);
	srand((unsigned int)time(0));
	RP r={0,0};
	RP *rp=&r;
	SNode *sp=NULL;
	Initheadtail(&sp);
	Randpoint(rp,sp,XMax,YMax);
	initscr();
	initkeyboard();
	//----------------------
	int ch=0;
	while(ch!='q')
	{
		ch=0;
		if(kbhit())
			ch=readch();
//		printf("%c\n",ch);
//		read(0,&ch,1);
		switch(ch){
			case 'w':
				sp->direction=N;
				break;
			case 's':
				sp->direction=S;
				break;
			case 'a':
				sp->direction=W;
				break;
			case 'd':
				sp->direction=E;
				break;
		}
//		printw("%d\n",sp->direction);
		switch(Checkhead(sp,rp)){
			case -1:
				goto END;
			case 0:
				break;
			case 1:
				Eatpoint(&sp,rp,XMax,YMax);
				break;
		}
		Freshsanke(&sp);
		Convertborder(sp,XMax,YMax);
		Printscr(sp);
		Printpoint(r);
		refresh();
		clear();
		usleep(200000);
	}
	//----------------------
END:closekeyboard();
	endwin();
	Freenode(sp);
	return 0;
}

void Initheadtail(SNode **s)
{
	SNode *re=(SNode *)malloc(sizeof(SNode));
	re->flag=Shead;
	re->xpos=1;
	re->ypos=0;
	re->direction=E;
	re->next=(SNode *)malloc(sizeof(SNode));
	re->next->flag=Stail;
	re->next->xpos=0;
	re->next->ypos=0;
	re->next->direction=E;
	re->next->next=NULL;
	*s=re;
}

void Addhead(SNode **s)
{
	SNode *tmp=(SNode *)malloc(sizeof(SNode));
	tmp->flag=Shead;
	tmp->direction=(*s)->direction;
	tmp->next=*s;
	switch((*s)->direction){
		case N :
			tmp->xpos=(*s)->xpos;
			tmp->ypos=(*s)->ypos-1;
			break;
		case W :
			tmp->xpos=(*s)->xpos-1;
			tmp->ypos=(*s)->ypos;
			break;
		case S :
			tmp->xpos=(*s)->xpos;
			tmp->ypos=(*s)->ypos+1;
			break;
		case E :
			tmp->xpos=(*s)->xpos+1;
			tmp->ypos=(*s)->ypos;
			break;
	}
	(*s)->flag=Shead;
	*s=tmp;
}

void Printnode(SNode *s)
{
	while(s->next!=NULL)
	{
		printf("flag=%d.x=%d,y=%d,direction=%d\n",s->flag,s->xpos,s->ypos,s->direction);
		s=s->next;
	}
	printf("flag=%d.x=%d,y=%d,direction=%d\n",s->flag,s->xpos,s->ypos,s->direction);
}

void Freenode(SNode *s)
{
	SNode *tmp=NULL;
	while(s->next!=NULL)
	{
		tmp=s;
		s=s->next;
		free(tmp);
	}
	free(s);
}

void Freshsanke(SNode **s)
{
	SNode *tmp=*s;
	while(tmp->next->next!=NULL)
		tmp=tmp->next;
	tmp->next->next=*s;
	tmp->next->flag=Shead;
	tmp->next->direction=(*s)->direction;
	switch((*s)->direction){
		case N:
			tmp->next->xpos=(*s)->xpos;
			tmp->next->ypos=(*s)->ypos-1;
			break;
		case W:
			tmp->next->xpos=(*s)->xpos-1;
			tmp->next->ypos=(*s)->ypos;
			break;
		case S:
			tmp->next->xpos=(*s)->xpos;
			tmp->next->ypos=(*s)->ypos+1;
			break;
		case E:
			tmp->next->xpos=(*s)->xpos+1;
			tmp->next->ypos=(*s)->ypos;
			break;
	}
	(*s)->flag=Sbody;
	*s=tmp->next;
	tmp->next=NULL;
	tmp->flag=Stail;
}

void Changedirection(SNode *s,int direction)
{
	s->direction=direction;
}

int Checkhead(SNode *s,RP *p)
{
	int xtmp=s->xpos;
	int ytmp=s->ypos;
	while(s->next!=NULL)
	{
		s=s->next;
		if(s->xpos==xtmp&&s->ypos==ytmp)
			return -1;
	}
	if(p->xpos==ytmp&&p->ypos==xtmp)
		return 1;
	return 0;
}

void Eatpoint(SNode **s,RP *p,int xmax,int ymax)
{
	Addhead(s);
	Randpoint(p,*s,xmax,ymax);
}

void Randpoint(RP *p,SNode *s,int xmax,int ymax)
{
	int xtmp,ytmp,flag;
	SNode *stmp=NULL;
	while(1)
	{
		flag=0;
		xtmp=rand()%ymax;
		ytmp=rand()%xmax;
		stmp=s;
		do
		{
			if(xtmp==s->xpos&&ytmp==s->ypos)
			{
				flag=1;
				break;
			}
			stmp=stmp->next;
		}while(stmp==NULL);
		if(flag)
			continue;
		else
			break;
	}
	p->xpos=xtmp;
	p->ypos=ytmp;
}
void Convertborder(SNode *s,int x,int y)
{
	if(s->xpos>x)
		s->xpos-=x+1;
	if(s->xpos<0)
		s->xpos+=x+1;
	if(s->ypos>y)
		s->ypos-=y;
	if(s->ypos<0)
		s->ypos+=y;
}
void Printscr(SNode *s)
{
	move(s->ypos,s->xpos);
	switch(s->direction){
		case N:
			printw("^");
			break;
		case W:
			printw("<");
			break;
		case S:
			printw("v");
			break;
		case E:
			printw(">");
			break;
	}
	s=s->next;
	do
	{
		move(s->ypos,s->xpos);
		printw("o");
		s=s->next;
	}while(s!=NULL);
}
void initkeyboard()
{
	tcgetattr(0,&old);
	new=old;
	new.c_lflag&=~ICANON;
	new.c_lflag&=~ECHO;
	new.c_lflag&=~ISIG;
	new.c_cc[VMIN]=1;
	new.c_cc[VTIME]=0;
	tcsetattr(0,TCSANOW,&new);
}
void closekeyboard()
{
	tcsetattr(0,TCSANOW,&old);
}
void Getborder(int *x,int *y)
{
	setupterm(NULL,fileno(stdout),NULL);
	*x=tigetnum("cols");
	*y=tigetnum("lines");
}
void Printpoint(RP rp)
{
	move(rp.xpos,rp.ypos);
}
int kbhit()
{
	char ch;
	int nread;

	if(peek_character!=-1)
		return 1;
	new.c_cc[VMIN]=0;
	tcsetattr(0,TCSANOW,&new);
	nread=read(0,&ch,1);
	new.c_cc[VMIN]=1;
	tcsetattr(0,TCSANOW,&new);
	if(nread==1){
		peek_character=ch;
		return 1;
	}
	return 0;
}
int readch()
{
	char ch;
	if(peek_character!=-1){
		ch=peek_character;
		peek_character=-1;
		return ch;
	}
	read(0,&ch,1);
	return ch;
}
