#include <stdio.h>
#define ROWS 3
#define COLS 4

void show_2darr(double ar[][COLS],int rows);
void copy_2darr(double source[][COLS],double target[][COLS],int rows);
int main(void)
{
	double arr2d[ROWS][COLS]={
		{2.1,3.2,4.5,5.6},
		{1.2,2.3,4.7,1.8},
		{8.2,4.5,6.7,8.1}
	};
	double target2d[ROWS][COLS];
	copy_2darr(arr2d,target2d,ROWS);
	show_2darr(target2d,ROWS);
	return 0;
}
void show_2darr(double ar[][COLS],int rows)
{
	int r;
	int c;
	for(r=0;r<rows;r++)
	{
		for(c=0;c<COLS;c++)
		{
			printf("%1.1lf\t",ar[r][c]);
		}
		putchar('\n');
	}
}
void copy_2darr(double source[][COLS],double target[][COLS],int rows)
{
	int r;
	int c;
	for(r=0;r<rows;r++)
		for(c=0;c<COLS;c++)
			target[r][c]=source[r][c];
}
