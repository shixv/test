#include <stdio.h>
#include <stdlib.h>
int delline(char *filename)
{
	int len=0;
	FILE *fp=fopen(filename,"rb");
	if(fp==NULL)
		return 1;
	int ch;
	while(fread(&ch,sizeof(char),1,fp))
		len++;
	char *buf=(char *)malloc(sizeof(char)*len);
	fseek(fp,0,SEEK_SET);
	fread(buf,sizeof(char),len,fp);
	fclose(fp);
	fp=fopen(filename,"w");
	int flag=1;
	long int fpre=0L;
	long int fcur=0L;
	for(int i=0;i<len;i++)
	{
		if(buf[i]=='\r'&&buf[i+1]=='\n')
			continue;
		fwrite(buf+i,1,1,fp);
		if(buf[i]!='\n')
		{
			if(buf[i]!=' '&&buf[i]!='\t'&&buf[i]!='\r')
				flag=0;
			continue;
		}
		else
		{
			fpre=fcur;
			if(!flag)
				fcur=ftell(fp);
		}
		if(flag++)
			fseek(fp,fpre,SEEK_SET);
	}
	fclose(fp);
	free(buf);
	return 0;
}
int main(int argc,char *argv[])
{
	for(int i=1;i<argc;i++)
		if(delline(argv[i]))
			return 0;
	return 0;
}
