#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*3.字符串处理
找出指定字符串中出现次数最高的字符
若有多个相同的字符备选,返回其中最早出现的字符
  函数原型：
  char  getMostCharFromString(const char *str)*/

char getMostCharFromString(const char *str);

int main(int argc,char *argv[])
{
	printf("%c\n",getMostCharFromString(argv[1]));
	return 0;
}
char getMostCharFromString(const char *str)
{
	if(str==NULL)
		return 0;
	int max=0;
	char ret=0;
	int buk[127]={0};
	int len=strlen(str);
	for(int i=0;i<len;i++)
		buk[(int)str[i]]++;
	for(int i=0;i<128;i++)
		if(max<buk[i])
		{
			max=buk[i];
			ret=i;
		}
	return (char)ret;
}
