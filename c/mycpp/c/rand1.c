#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randm(int i,int j);
int main(void)
{
	srand((unsigned int)time(0));
	for(int i=0;i<100;i++)
		printf("%d,",randm(1,100));
	putchar('\n');
	return 0;
}
int randm(int i,int j)
{
	return rand()%j+i;
}
{
:wq}
{

}

{

}

{
}
{



}
