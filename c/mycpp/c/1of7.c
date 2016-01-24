#include <stdio.h>
//不好意思没用指针

int main(int argc,char *argv[])
{
	if(argc==1||argc==2)return 0;
	int year=(int)atoi(argv[1]);
	int day=(int)atoi(argv[2]);
	int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	((year%4==0&&year%100!=0)||year%400==0)?month[1]=29:1;
	int i=0;
	while(day>month[i])day-=month[i++];
	printf("%d days of %d month of %d year\n",day,i,year);
	return 0;
}
