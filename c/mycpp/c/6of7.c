#include <stdio.h>

void removua(char *,int);
void removre(char *,int);
void printarr(char *,int);
//void movearr(char *,int,int);

int main(int argc,char *argv[])
{
	if(argc==1){printf("双引号\n");return 0;}
	char *ps=argv[1];
	int n=0;
	while(ps[n]!='\0')n++;
	removua(ps,n);
//	n=0;
//	while(ps[n]!='\0')n++;
	removre(ps,n+1);
	printarr(ps,n+1);
	return 0;
}
void removua(char *ps,int n)
{
	int i;
	for(i=0;i<n;i++)
		if(ps[i]<((int)'a')||ps[i]>((int)'z'))ps[i]='\0';
}
void removre(char *ps,int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if((ps[i]==ps[j])&&i!=j)ps[i]='\0';
}
void printarr(char *ps,int n)
{
	int i;
	for(i=0;i<n;i++)if(ps[i]!='\0')printf("%c",ps[i]);
	putchar('\n');
}
/*void movearr(char *ps,int n,int i)
{
	int m=n;
	for(;i<n;i++){
		ps[i]=ps[i+1];
		m--;
	}
	ps[m]='\0';
}*/
