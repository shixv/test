#include <stdio.h>
int Max(int *,int);
int main(int argc,char *argv[])
{
	if(argc==1)
		return 0;
	FILE *fp=fopen(argv[1],"r");
	char ch;
	int bukkit[128]={0};
	while((ch=getc(fp))!=EOF)
		bukkit[(int)ch]++;
	fclose(fp);
	printf("%c\n",Max(bukkit,128));
	return 0;
}
int Max(int *c,int n)
{
	int maxi=0;
	int max=c[0];
	for(int i=1;i<n;i++)
	{
		if(c[i]>max)
		{
			max=c[i];
			maxi=i;
		}
	}
	return maxi;
}
