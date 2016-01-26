#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COUNT 100
#define COL 20
#define ROW 20

int **Initarray(int col,int row,int count);
void randout(int n,int **p,int col,int row);
void fillarray(int **p,int col,int row);
int rebomb(int **p,int col,int row);
void printarr(int **p,int col,int row);
void free_arr(int **p,int col,int row);
int main(int argc,char *argv[])
{
	srand((unsigned int)time(0));
	int **arr=Initarray(COL,ROW,COUNT);
	printarr(arr,COL,ROW);
	free_arr(arr,COL,ROW);
	return 0;
}
int **Initarray(int col,int row,int count)
{
	int **p=(int **)malloc(sizeof(int *)*(col+2));
	for(int i=0;i<(col+2);i++){
		p[i]=(int *)malloc(sizeof(int)*(row+2));
		memset(p[i],0,sizeof(int)*(row+2));
	}
	randout(count,p,col,row);
	fillarray(p,col,row);
	return p;
}
void randout(int n,int **p,int col,int row)
{
	int rcol,rrow;
	while(n!=0)
	{
		rcol=rand()%col+1;
		rrow=rand()%row+1;
		if(p[rcol][rrow]==9)
			continue;
		else
		{
			p[rcol][rrow]=9;
			n--;
		}
	}
}
void fillarray(int **p,int col,int row)
{
	for(int c=1;c<col+1;c++)
		for(int r=1;r<row+1;r++)
			if(p[c][r]!=9)
				p[c][r]=rebomb(p,c,r);
}
int rebomb(int **p,int col,int row)
{
	int re=0;
	for(int i=col-1;i<col+2;i++)
		for(int j=row-1;j<row+2;j++)
			if(p[i][j]==9)
				re++;
	return re;
}
void printarr(int **p,int col,int row)
{
	for(int i=1;i<col+1;i++){
		for(int j=1;j<row+1;j++)
			printf("%d ",p[i][j]);
		printf("\n");
	}
}
void free_arr(int **p,int col,int row)
{
	for(int i=0;i<col+2;i++)
		free(p[i]);
	free(p);
}
