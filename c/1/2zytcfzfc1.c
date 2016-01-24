#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
有一个字符串符合以下特征（“abcdef,acccd,eeee,aaaa,e3eeee,ssss,”）
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
		//找到了 ‘，’
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
		//还有一个字符串需要处理
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
