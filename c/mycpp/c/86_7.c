#include <stdio.h>

void arr_show(int rows,int cols,int ar[rows][cols]);
void arr_add(int rows,int cols,int arrop1[rows][cols],int arrop2[rows][cols],int ansarr[rows][cols]);
int main(void)
{
	int arr1[2][2]={
		{2,3},
		{3,4}
	};
	int arr2[2][2]={
		{3,4},
		{4,5}
	};
	int arr[2][2];
	arr_add(2,2,arr1,arr2,arr);
	arr_show(2,2,arr);
	return 0;
}
void arr_show(int rows,int cols,int ar[rows][cols])
{
	int r;
	int c;
	for(r=0;r<rows;r++)
	{
		for(c=0;c<cols;c++)
			printf("%d\t",ar[r][c]);
		putchar('\n');
	}
}
void arr_add(int rows,int cols,int arrop1[rows][cols],int arrop2[rows][cols],int ansarr[rows][cols])
{
	int r;
	int c;
	for(r=0;r<rows;r++)
		for(c=0;c<cols;c++)
			ansarr[r][c]=arrop1[r][c]+arrop2[r][c];
} 
