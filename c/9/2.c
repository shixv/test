#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*每一行为一个人的信息,请自行设计一个结构体并且读每个人的信息到内存中,name为姓名,height为身高,weight为体重
1) 求出一共几个人 
2) 实现readFileToMem函数,将所有的信息存入内存
3) 按照身高体重比(身高/体重)排序 实现sortMan()函数
4) 将最丰满的人写入文档Mostfat.cfg 格式为:
name=xxxx,height=xxxx,weight=xxx*/
struct man
{
	char name[20];
	float height;
	float weight;
};
void readFileToMem(FILE *fp,struct man *sp,int count);
void sortMan(struct man *sp,int count);
void writeFile(FILE *fp,struct man *sp,int count);
int main(int argc,char *argv[])
{
	int count=0;
	char ch;
	FILE *fp1=fopen(argv[1],"r");
	FILE *fp2=fopen(argv[2],"w");
	while(fread(&ch,1,1,fp1)!=0)
	{
		if(ch=='\n')
			count++;
	}
	struct man *st=(struct man *)malloc(sizeof(struct man)*count);
	readFileToMem(fp1,st,count);
	sortMan(st,count);
	writeFile(fp2,st,count);
	printf("success!!!!!");
	fclose(fp1);
	fclose(fp2);
	return 0;
}
void readFileToMem(FILE *fp,struct man *sp,int count)
{
	char tname[20];
	float theight;
	float tweight;
	for(int i=0;i<count;i++)
	{
		fscanf(fp,"name=%s,height=%f,weight=%f",tname,&theight,&tweight);
		strcpy(sp->name,tname);
		sp->height=theight;
		sp->weight=tweight;
	}
}

void sortMan(struct man *sp,int count)
{
	for(int i=0;i<count;i++)
		for(int j=0;j<count-i;j++)
			if(((sp+j)->height/(sp+j)->weight)>((sp+j+1)->height/(sp+j+1)->weight))
			{
				char tmp[20];
				strcpy(tmp,(sp+j)->name);
				strcpy((sp+j)->name,(sp+j+1)->name);
				strcpy((sp+j+1)->name,tmp);
				int ctmp=(sp+j)->height;
				(sp+j)->height=(sp+j+1)->height;
				(sp+j+1)->height=ctmp;
				ctmp=(sp+j)->weight;
				(sp+j)->weight=(sp+j+1)->weight;
				(sp+j+1)->weight=ctmp;
			}
}
void writeFile(FILE *fp,struct man *sp,int count)
{
	for(int i=0;i<count;i++)
		fprintf(fp,"name=%s ,height=%f,weight=%f\n",sp[i].name,sp[i].height,sp[i].weight);
}
