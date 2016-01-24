#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
1����һ���ַ�����1a2b3d4z�� ��
Ҫ��дһ������ʵ�����¹��ܣ�
����1����ż��λ�ַ���ѡ���������һ���ַ���1��
����2��������λ�ַ���ѡ���������һ���ַ���2��
����3�����ַ���1���ַ���2��ͨ���������������͸�main������ӡ��
����4���������ܲ���ͨ����
int	getStr1Str2(char	*source,	char	*buf1,	char	*buf2);

*/
//1234\0
//       ��
//abcd\0
//       ��

//1a2b3d4d\0
//               ��
int get_str1_str2(char *source, char *buf1, char *buf2)
{
	char *p = source;
	char *temp_buf1 = buf1;
	char *temp_buf2 = buf2;

	if (source == NULL || buf1 == NULL || buf2 == NULL) {
		printf("source == NULL || buf1 == NULL || buf2 == NULL\n");
		return -1;
	}

	while (*p != '\0')
	{
		*temp_buf1 = *p;
		temp_buf1++;
		p++;

		*temp_buf2 = *p;
		temp_buf2++;
		p++;
	}

	*temp_buf1 = '\0';
	*temp_buf2 = '\0';

	return 0;
}

int main(void)
{
	char *str = "1a2b3d4z";
	char buf1[64] = { 0 };
	char buf2[64] = { 0 };
	
	if (get_str1_str2(str, buf1, buf2) < 0) {
		printf("get_str1_str2 error\n");
		return -1;
	}

	printf("buf1 : %s\n", buf1);
	printf("buf2 : %s\n", buf2);



	return 0;
}
