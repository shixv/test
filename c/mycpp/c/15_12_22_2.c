#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int mrand(int n);
void mreverse(int *arr,int n);
void printarr(int *arr,int n);
int main(int argc,char *argv[])
{
	printf("随机1-100的整数，倒序打印\n");
	printf("可加参数-s指定seed，-n指定范围\n");
	int seed=(int)time(0);
	int n=100;
	int opt,i;
	while((opt=getopt(argc,argv,"s:n:"))!=-1){
		switch(opt){
			case 's':seed=(int)atoi(optarg);
			case 'n':n=(int)atoi(optarg);
		}
	}
	int *arr=malloc(sizeof(int)*n);
	srand(seed);
	for(i=0;i<n;i++)
		arr[i]=mrand(n);
	mreverse(arr,n);
	printarr(arr,n);
	free(arr);
	return 0;
}
int mrand(int n)
{
	return (int)((rand()%n)+1);
}
void mreverse(int *arr,int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=1;j<n-i;j++)
			if(arr[j]>arr[j-1])
			{
				int temp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
			}
}
void printarr(int *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(i%10==0)putchar('\n');
		printf("%d,",arr[i]);
	}
	putchar('\b');putchar('\n');
}
