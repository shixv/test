#include <stdlib.h>
#include <stdio.h>

struct index
{
	char c;
	long begin;
	long end;
};
int main(void)
{
	FILE *fp = fopen("dict.txt","r");
	FILE *fip = fopen("dict.index","w");
	if(!fp)return 0;
	fseek(fp,3L,SEEK_SET);
	char buf;
//	char c;
//	char rb[1024];
//	struct index id={'a',0,0};
	while(1)
	{
		fread(&buf,sizeof(char),1,fp);
//		fgets(buf,sizeof(buf),fp);
//		c=getc(fp);
//		printf("%c\n",buf);
//		break;
/*		if(buf==id.c)
		{
			id.end++;
			continue;
		}
		if(buf==(id.c+1))
		{
			id.end--;
			fwrite(&id,sizeof(struct index),1,fip);
			id.c++;
			id.begin=++id.end;
			++id.end;
			continue;
		}
		if(buf<0)
		{
			id.end--;
			fwrite(&id,sizeof(struct index),1,fip);
			break;
		}
			
	}
	fclose(fp);
	fclose(fip);
	fip=fopen("dict.index","r");
	int rc=0;
	while(1)
	{
		rc=fread(&id,sizeof(struct index),1,fip);
		if(rc==0)break;
		printf("%c,%d,%d\n",id.c,id.begin,id.end);
	}
*/
	fclose(fip);
	return 0;
}
