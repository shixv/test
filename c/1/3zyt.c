#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
有一个字符串符合以下特征（“abcdef,acccd,eeee,aaaa,e3eeee,ssss,12312”）
写两个函数(API)，输出以下结果
第一个API
1)以逗号分隔字符串，形成二维数组，并把结果传出
2)把二维数组行数运算结果也传出
第二个API
1)以逗号分隔字符串，形成一个二级指针。
2)把一共拆分多少行字符串个数传出
要求：
1, 能正确表达功能的要求，定义出接口。
2, 正确实现接口和功能.
3, 编写正确的测试用例.
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

	//先计算出 原字符串 有多少个
	if (src == NULL || array_p == NULL || count_p == NULL) {
		printf("src == NULL || array_p == NULL || count_p == NULL\n");
		return -1;
	}

	while ((p = strchr(p, ch) )!= NULL) {
		//找到了一个子串 
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

	//此时的temp_count就是子字符串的个数，也是需要开辟指针的个数
	array = (char**)malloc(sizeof(char*)*temp_count);
	if (array == NULL) {
		printf("malloc array error\n");
		ret = -1;
		goto END;
	}
	memset(array, 0, sizeof(char*)*temp_count);


	//重新遍历原字符串， 找到一个子串就开辟一个空间
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
		//出现了问题
		//进行统一的垃圾回收
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
