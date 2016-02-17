#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *badd(char *s1,char *s2)
{
	char *t1=strlen(s1)>strlen(s2)?s1:s2;
	char *t2=strlen(s1)<=strlen(s2)?s1:s2;
	char *temp=(char *)malloc(strlen(t1)+1);
	int flag=0;
	for(int i=strlen(t2)-1,j=strlen(t1)-1,k=strlen(t1);i>-1;i--,j--,k--)
	{
		temp[k]=(flag+t2[i]+t1[j]-2*'0')%10+'0';
		flag=(flag+t2[i]+t1[j]-2*'0')/10;
	}
	for(int i=strlen(t1)-strlen(t2)-1;i>-1;i--)
	{
		temp[i+1]=(t1[i]+flag-'0')%10+'0';
		flag=(flag+t1[i]-'0')/10;
	}
	temp[0]=flag+'0';
	if(flag)
		return temp;
	return temp+1;
}
int main(int argc,char *argv[])
{
	printf("%s\n",badd(argv[1],argv[2]));
	return 0;
}
