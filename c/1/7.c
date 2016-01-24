#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int(array_int_5_6)[5][6];
typedef int(*array_int_5_6_p)[5][6];

typedef int(array_int_5)[5];
typedef int(*array_int_5_p)[5];

void make_array(array_int_5_6_p a,int row,int col,int height);
void make_array(array_int_5_6 *a,int row,int col,int height);
void make_array(int (*a)[5][6],int row,int col,int height);
void make_array(int a[][5][6],int row,int col,int height);
void make_array(int a[3][5][6],int row,int col,int height);
{
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			for(int k=0;k<height;k++)
				a[height][row][col]=height*row*col;
}


void make_array(array_int_5_p a, int row , int col)
//void make_array(array_int_5 *a, int row, int col)
//void make_array(int(*a)[5], int row, int col)
//void make_array(int a[][5])
//void make_array(int a[3][5], int row, int col) 
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			//a[i][j] = i + j;
			//a-->int[5]
			* (*(a + i) + j) = i + j;
		}
	}
}

void print_array(int a[][5], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("a[%d][%d]: %d  ", i, j, a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void)
{

	int a[3][5];

	make_array(a, 3, 5);

	print_array(a, 3, 5);

	return 0;
}
