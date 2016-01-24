#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
��һ���ַ�������������������abcdef,acccd,eeee,aaaa,e3eeee,ssss,12312����
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


void free_mem(char ***array_p, int count)
{
	char **array = *array_p;
	int i = 0;
	if (array_p == NULL) {
		return;
	}

	if (array != NULL) {
		for (i = 0; i < count; i++) {
			if (array[i] != NULL) {
				free(array[i]);
				array[i] = NULL;
			}
		}

		free(array);

		*array_p = NULL;
	}
}


int spit_string(char *src, char ch, char ***array_p, int *count_p)
{
	char **array = NULL;

	char *p = src;
	char *q = p;
	int temp_count = 0;
	int str_len = 0;
	int ret = 0;

	//�ȼ���� ԭ�ַ��� �ж��ٸ�
	if (src == NULL || array_p == NULL || count_p == NULL) {
		printf("src == NULL || array_p == NULL || count_p == NULL\n");
		return -1;
	}

	while ((p = strchr(p, ch) )!= NULL) {
		//�ҵ���һ���Ӵ� 
		temp_count++;
		p++;
		q = p;
		if (*q == '\0') {
			break;
		}
	}

	if (*q != '\0') {
		temp_count++;
	}

	//��ʱ��temp_count�������ַ����ĸ�����Ҳ����Ҫ����ָ��ĸ���
	array = (char**)malloc(sizeof(char*)*temp_count);
	if (array == NULL) {
		printf("malloc array error\n");
		ret = -1;
		goto END;
	}
	memset(array, 0, sizeof(char*)*temp_count);


	//���±���ԭ�ַ����� �ҵ�һ���Ӵ��Ϳ���һ���ռ�
	p = src;
	q = p;
	temp_count = 0;

	while ((p = strchr(p, ch)) != NULL) {
		str_len = p - q;
		array[temp_count] = (char*)malloc(str_len + 1);
		if (array[temp_count] == NULL) {
			printf("array[%d] malloc error\n", temp_count);
			ret = -1;
			goto END;
		}

		strncpy(array[temp_count], q, str_len);
		array[temp_count][str_len] = '\0';

		temp_count++;
		p++;
		q = p;

		if (*q == '\0') {
			break;
		}
	}

	if (*q != '\0') {
		//str_len = strlen(q);
		str_len = (src + strlen(src)) - q;
		array[temp_count] = (char*)malloc(str_len + 1);
		if (array[temp_count] == NULL) {
			printf("array[%d] malloc error\n", temp_count);
			ret = -1;
			goto END;
		}

		strncpy(array[temp_count], q, str_len);
		array[temp_count][str_len] = '\0';
		temp_count++;
	}

	if (array != NULL) {
		*array_p = array;
		*count_p = temp_count;
	}


END:
	if (ret != 0) {
		//����������
		//����ͳһ����������
		free_mem(&array, temp_count);
	}

	return ret;
}

int main(void)
{
	char *str = "abcdef321321321321322312,acccd,eeee,aaaa,e3eeee,ssss,abcde,312321,33213232,321321321,";
	int count = 0;
	int ret = 0;
	char **array = NULL;
	int i = 0;

	ret = spit_string(str, ',', &array, &count);
	if (ret < 0) {
		printf("spit_string error\n");
		return -1;
	}

	for (i = 0; i < count; i++) {
		printf("array[%d]:%s\n", i, array[i]);
	}


	free_mem(&array, count);

	if (array == NULL) {
		printf("kong\n");
	}

	return 0;
}
