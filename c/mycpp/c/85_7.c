#include <stdio.h>

void show_arr(int rows,int cols,double ar[rows][cols]);
void copy_arr(int rows,int cols,double source[rows][cols],double target[rows][cols]);
int main(void)
{
	double array[3][4]={
		{1.23,1.34,1.66,1.56},
		{2.23,2.11,2.36,2.88},
		{3.45,3.11,3.78,3.56}
	};
	double ar[3][4];
	copy_arr(3,4,array,ar);
	show_arr(3,4,ar);
	return 0;
}
void show_arr(int rows,int cols,double ar[rows][cols])
{
	int r;
	int c;
	for(r=0;r<rows;r++)
	{
		for(c=0;c<cols;c++)
			printf("%1.1lf\t",ar[r][c]);
		putchar('\n');
	}
}
void copy_arr(int rows,int cols,double source[rows][cols],double target[rows][cols])
{
	int r;
	int c;
	for(r=0;r<rows;r++)
		for(c=0;c<cols;c++)
			target[r][c]=source[r][c];
}		
