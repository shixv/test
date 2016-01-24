#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 4

int Issame(int *ar,int i);
void randarr(int *ar);
int inputarr(int *ar);
int outputarr(int *src,int *ter,char *out);
int main(void)
{
	int randm[MAX];
	int input[MAX];
	char output[MAX];
	randarr(randm);
	while(1)
	{
		if(inputarr(input)==0){
			printf("wrong\n");
			continue;
		}
		if(outputarr(randm,input,output)==MAX)
		{
			printf("Done.\n");
			return 0;
		}
		for(int i=0;i<MAX;i++)
			printf("%c",output[i]);
		putchar('\n');
	}
	return 0;
}
void randarr(int *ar)
{
	srand((unsigned int)time(0));
	for(int i=0;i<MAX;i++)
	{
		ar[i]=rand()%10;
		if(Issame(ar,i))
			i--;
	}
}
int inputarr(int *ar)
{
	char ch;
	for(int i=0;i<MAX+1;i++)
	{
		ch=getchar();
		if(ch=='\n')
			break;
		ar[i]=(int)ch-48;
		if(ar[i]<0||ar[i]>9||Issame(ar,i))
		{
			while((ch=getchar())!='\n');
			return 0;
		}
	}
	return 1;
}
int Issame(int *ar,int i)
{
	if(i==0)
		return 0;
	for(int j=0;j<i;j++)
	{
		if(ar[j]==ar[i])
			return 1;
	}
	return 0;
}
int outputarr(int *src,int *ter,char *out)
{
	int flag=0;
	for(int i=0;i<MAX;i++)
	{
		out[i]='0';
		for(int j=0;j<MAX;j++)
		{
			if(ter[i]==src[j])
				out[i]='B';
			if(i==j&&ter[i]==src[j])
			{
				out[i]='A';
				flag++;
			}
		}
	}
	return flag;
}
