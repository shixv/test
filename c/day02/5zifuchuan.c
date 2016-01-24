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

	//����һ������־�Ĺ���
	//��ӡ��������dst�ַ���


	return 0;
}

int my_strcopy5( char *dst,  const char *src) //���ָ����Ϊ������������Լ�const�������Ρ�
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

	//��ӡ��־
	printf("dst = %s\n", dst);
	printf("src = %s\n", src);

END:
	//��goto �ؼ����ܹ���֤�����ĳ�����Ψһ�ġ�
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
