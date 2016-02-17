//八皇后问题
#include <stdio.h>
#include <math.h>
#define N 8 //皇后数
int a[N]; //a[i]为第i行皇后所在列
void show() //打印 
{
	static int t=1;
	printf("%d:",t++);
	for(int i=0;i<N;i++)
		printf("(%d,%d)",i,a[i]);
	printf("\n");
}
int check(int n) //检查位置是否合法，满足条件返回1，否则返回0
{
	for(int i=0;i<n;i++)
		if(a[i]==a[n]||abs(n-i)==abs(a[i]-a[n])) 
			return 0;
	return 1;
}
void put(int n) //递归的在第n行放置第n个皇后
{
	if(n==N) //终止条件
		return;
	for(int i=0;i<N;i++)
	{
		a[n]=i;
		if(check(n)) //位置合法
			(n==N-1)?show():put(n+1); //是否到最后
	}
}
int main(void)
{
	put(0);
	return 0;
}
