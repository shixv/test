#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
��һ���ַ�������������������abcdef,acccd,eeee,aaaa,e3eeee,ssss,����
д��������(API)��������½��
��һ��API
1)�Զ��ŷָ��ַ������γɶ�ά���飬���ѽ������
2)�Ѷ�ά��������������Ҳ����
�ڶ���API
1)�Զ��ŷָ��ַ������γ�һ������ָ�롣
2)��һ����ֶ������ַ�����������
Ҫ��
1, ����ȷ��﹦�ܵ�Ҫ�󣬶�����ӿڡ�
2, ��ȷʵ�ֽӿں͹���.
3, ��д��ȷ�Ĳ�������.
*/

//char  array[10][30], char array[][30]
int spit_string(char *src, char ch, char(*array)[30], int *count_p)
{
	char *p = src;
	char *q = p;
	int temp_count = 0;
	int len = 0;

	if (src == NULL || array == NULL || count_p == NULL) {
		printf("%s:%d: src == NULL || array == NULL || count_p == NULL", __FUNCTION__, __LINE__);
		return -1;
	}

	
	temp_count = 0;

	while ((p = strchr(p, ch)) != NULL) {
		//�ҵ��� ������
		strncpy(array[temp_count], q, p - q);
		array[temp_count][p - q] = '\0';

		temp_count++;
		p++;
		q = p;
		if (*q == '\0') {
			break;
		}
	}

	if (*q != '\0') {
		//����һ���ַ�����Ҫ����
		len = (src + strlen(src)) - q;
		strncpy(array[temp_count], q, len);
		array[temp_count][len] = '\0';
		temp_count++;
	}


	*count_p = temp_count;

	return 0;
}

int main(void)
{
	char *str = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,abcde,";
	char array[10][30];
	int count = 0;
	int ret = 0;
	int i = 0;

	ret = spit_string(str, ',', array, &count);
	if (ret < 0) {
		printf("spit_string error\n");
		return -1;
	}

	for (i = 0; i < count; i++)
	{
		printf("array[%d]:%s\n", i, array[i]);
	}

	return 0;
}
