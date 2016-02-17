#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*1.实现get getCountOfSimpleLine()函数
函数原型：int getCountOfSimpleLine(const char *filename,unsigned int *count);
函数相关需求如下：
a．getCountOfSimpleLine函数获取指定filename的文件中空行的行数
win下输入的空行为(\r \n),Linux下为 (\n)
	b．返回值的设定
	文件若不存在函数返回值返回-1;
	函数运行正常,返回0.
	如果有其他错误则返回-2;
	c．若函数正确获得文件的空行，通过count指针将数值写回   调用函数。
	d．提交的源码应当可运行，方可不扣分*/
int getCountOfSimpleLine(const char *filename,unsigned int *count);
int main(int argc,char *argv[])
{
	unsigned int count=0u;
	for(int i=1;i<argc;i++)
	{
		getCountOfSimpleLine(argv[i],&count);
		printf("%s : %u LINE.\n",argv[i],count);
	}
	return 0;
}
int getCountOfSimpleLine(const char *filename,unsigned int *count)
{
	FILE *fp=fopen(filename,"rb");
	if(!fp)
		return -1;
	int flag=1;
	char now;
	*count=0u;
	while(fread(&now,1,1,fp)!=0)
	{
		if(now!='\n')
		{
			if(now!=' ')
				flag=0;
			continue;
		}
		if(flag++)
			(*count)++;
	}
	fclose(fp);
	return 0;
}
