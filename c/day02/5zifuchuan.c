#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strcpy_m(char *,const char *);
int  my_strcopy1(char *dst, char *src)
{
	for (; *src != '\0';dst++, src++)
	{
		*dst = *src;
	}

	*dst = '\0';

	return 0;
}

int my_strcopy2(char *dst, char *src)
{
	for (; *src != '\0';) {
		*dst++ = *src++;//*dst = *src; dst++, src++;
	}
	*dst = '\0';
	return 0;
}

int my_strcopy3(char *dst, char *src)
{
	for (; (*dst = *src) != '\0';) {
		dst++;
		src++;
	}

	return 0;
}

int my_strcopy4(char *dst, char *src)
{
	while ((*dst++ = *src++))
	{
		;
	}

	//加入一个打日志的功能
	//打印被拷贝的dst字符串


	return 0;
}

int my_strcopy5( char *dst,  const char *src) //如果指针作为传入参数，可以加const进行修饰。
{
	char *temp_dst = NULL;
	char *temp_src = NULL;
	int ret = 0;

	if (dst == NULL || src == NULL) {
		printf("dst == NULL || src == NULL\n");
		ret = -1;
		goto END;
	}

	for (temp_dst = dst, temp_src = (char*)src; (*temp_dst++ = *temp_src++); )
	{
		;
	}

	//打印日志
	printf("dst = %s\n", dst);
	printf("src = %s\n", src);

END:
	//用goto 关键字能够保证函数的出口是唯一的。
	return ret;
}

int main(void)
{
	char s1[6]={
		0
	};
	char *s="abcdf";
	strcpy_m(s1,s);
	printf("%s\n",s);
	return 0;
}

int main1(void)
{
	char *str = "123456";
	char buf[128] = { 0 };


	my_strcopy5(buf, str);

	printf("buf=%s\n", buf);

	return 0;
}

int strcpy_m(char *src,const char *dest)
{
	while(*src++=*dest++);
	return 0;
}
