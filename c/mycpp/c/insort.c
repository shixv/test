#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARG argv[1],&fcur

long int fcur=0L;
unsigned int endflag=0u;
long int nlength(int n,char *name,long int *cur,unsigned int *endflag);
int flength(char *name);
int findn(int n,char *name,long int *cur,unsigned int *endflag);
void fdiv(char *name,long int *cur,unsigned int *endflag);
void fattend(int n,unsigned int *endflag);
void fopt(char *name,long int flag,unsigned int *endflag);
void setn(int i,int n,char *name,long int *cur,unsigned int *endflag);
int deln(int n,char *name,int long *cur,unsigned int *endflag);
void excn(int i,int j,char *name,long int *cur,unsigned int *endflag);
/*
int main9(int argc,char *argv[])
{
	if(argc<2)return 0;
	int n=flength(argv[1]);
	for(int i=1;i<=n;i++)
		for(int j=2;j<=n-i;j++)
		{
			int m=findn(j,ARG);
			int n=findn(j-1,ARG);
			if(m<n)
			{
				excn(i,j,ARG);
			}
		}
	return 0;
}*/
int main(int argc,char *argv[])
{
//	printf("%d\n",findn(1,"src.txt",&fcur));
//	printf("%ld\n",nlength(6,"src.txt",&fcur));
//	printf("%d\n",deln(4,"src.txt",&fcur));
//	setn(12,1,"src.txt",&fcur);
	int n;
	scanf("%d",&n);
	printf("%d\n",findn(n,ARG,&endflag));
	printf("%ld\n",fcur);
//	excn(1,9,ARG);
//	excn(6,3,ARG);
//	excn(3,6,argv[1],&fcur);
//	fdiv(ARG);
//	fattend(1286,&endflag);
//	fopt(argv[1],0L,&endflag);
	printf("%d\n",flength(argv[1]));
	return 0; 
}
int findn(int n,char *name,long int *cur,unsigned int *endflag)
{
	int len=flength(name);
	*cur=0L;
	if(n>=(len+1))
	{
		*endflag=1u;
		n=len;
		return 0;
	}
	*endflag=0u;
	FILE *fp=fopen(name,"r");
	int i=0,j=0;
	char ch;
	char arr[20];
	while(i<n)
	{
		ch=getc(fp);
		if(ch==';')
		{
			(*cur)++;
			arr[j]='\0';
			return atoi(arr);
		}
		if(ch==',')
		{
			arr[j]='\0';
			i++;
			j=0;
			if(i<(n-1))(*cur)++;
			continue;
		}
		arr[j]=ch;
		j++;
		if(i<(n-1))(*cur)++;
	}
	if(n!=1)(*cur)++;
	fclose(fp);
	return atoi(arr);
}
void fdiv(char *name,long int *cur,unsigned int *endflag)
{
	char ch;
	long int i=0L;
	FILE *src=fopen(name,"r");
	fseek(src,0L,SEEK_SET);
	FILE *tmp=fopen("tmp1.txt","w");
	while((ch=getc(src))!=';')
	{
		if(i<*cur)
		{
			i++;
			putc(ch,tmp);
		}
	}
	fclose(tmp);
	tmp=fopen("tmp2.txt","w");
	fseek(src,*cur,SEEK_SET);
	while((ch=getc(src))!=';')
	{
		putc(ch,tmp);
	}
	if(!(*endflag))
	{
		putc(';',tmp);
	}
	fclose(src);
	fclose(tmp);
}
void fattend(int n,unsigned int *endflag)
{
	FILE *fp=0;
	if(!(*endflag))
	{
		fp=fopen("tmp1.txt","a");
	}
	else
	{
		fp=fopen("tmp2.txt","a");
	}
	fprintf(fp,"%d,",n);
	fclose(fp);
}
void fopt(char *name,long int flag,unsigned int *endflag)
{
	FILE *src=fopen(name,"w");
	char ch;
	FILE *tmp=fopen("tmp1.txt","r");
	fseek(tmp,0L,SEEK_SET);
	while((ch=getc(tmp))!=EOF)putc(ch,src);
	fclose(tmp);
	tmp=fopen("tmp2.txt","r");
	if(*endflag)
	{
		fseek(src,0,SEEK_SET);
		flag=0;
	}
	fseek(tmp,flag,SEEK_SET);
	while((ch=getc(tmp))!=EOF)putc(ch,src);
	if(*endflag)putc(';',src);
	fclose(tmp);
	fclose(src);
}

void setn(int i,int n,char *name,long int *cur,unsigned int *endflag)     //把i插入到第n个位置
{
	findn(n,name,cur,endflag);
	fdiv(name,cur,endflag);
	fattend(i,endflag);
	fopt(name,0L,endflag);
	*cur=0L;
}
int flength(char *name)
{
	FILE *fp=fopen(name,"r");
	char ch;
	int l=0;
	while((ch=getc(fp))!=';')
	{
		if(ch==',')
			l++;
	}
	fclose(fp);
	return l+1;
}
long int nlength(int n,char *name,int long *cur,unsigned int *endflag)
{
	int m=findn(n,name,cur,endflag);
	long int i=0;
	while((m/=10)!=0)i++;
	return i+1;
}
int deln(int n,char *name,int long *cur,unsigned int *endflag)
{
	long int nlen=nlength(n,name,cur,endflag);
	int dn=findn(n,name,cur,endflag);
	fdiv(name,cur,endflag);
	fopt(name,nlen+1L,endflag);
	*cur=0L;
	return dn;
}
void excn(int i,int j,char *name,long int *cur,unsigned int *endflag)
{
	int m=findn(i,name,cur,endflag);
	int n=findn(j,name,cur,endflag);
	if(i<j)
	{
		deln(j,name,cur,endflag);
		setn(m,j,name,cur,endflag);
		deln(i,name,cur,endflag);
		setn(n,i,name,cur,endflag);
	}
	else
	{
		deln(i,name,cur,endflag);
		setn(n,i,name,cur,endflag);
		deln(j,name,cur,endflag);
		setn(m,j,name,cur,endflag);
	}
}
