#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define IN
#define OUT


void free_mem(char ***array_p, int num)
{
	char **array = *array_p;
	int i = 0;

	if (array_p == NULL) {
		return;
	}

	if (array != NULL) {
		for (i = 0; i < num; i++) {
			if (array[i] != NULL) {
				free(array[i]);
				array[i] = NULL;
			}
		}

		free(array);

		*array_p = NULL;
	}

}

int sort(IN char *array_1[], IN  int num1,
	IN char(*array_2)[30], IN int num2,
	OUT char ***array_3p, OUT int *num3_p)
{
	char **p = NULL;
	int ret = 0;
	int num3 = 0;
	int len = 0;
	int i = 0;
	int j = 0;
	char *temp = NULL;

	if (array_1 == NULL || array_2 == NULL || array_3p == NULL || num3_p == NULL) {
		printf("array_1 == NULL || array_2 == NULL || array_3p == NULL || num3_p == NULL\n");
		return -1;
	}

	num3 = num1 + num2;// 最终合并后，二维数组 指针的个数
	p = (char**)malloc(sizeof(char*)*num3);
	if (p == NULL) {
		printf(" malloc char **p error\n");
		ret = -1;
		goto END;
	}
	memset(p, 0, sizeof(char *)* num3);

	//将array_1 copy 到 p中
	for (i = 0; i < num1; i++) {
		len = strlen(array_1[i]);
		p[i] = (char*)malloc(sizeof(char)*(len + 1));
		if (p[i] == NULL) {
			printf("malloc p[%d] error\n", i);
			ret = 0;
			goto END;
		}
		memset(p[i], 0, len + 1);
		//copy

		strcpy(p[i], array_1[i]);
	}


	//将 array_2 copy 到 p中 
	for ( j = 0; j < num2; j++, i++) {
		len = strlen(array_2[j]);
		p[i] = (char*)malloc(sizeof(char)*(len + 1));
		if (p[i] == NULL) {
			printf("p[%d] malloc error\n", p[i]);
			ret = -1;
			goto END;
		}
		memset(p[i], 0, len + 1);

		//copy
		strcpy(p[i], array_2[j]);
	}

	//遍历
	printf("sort before\n");
	for (i = 0; i < num3; i++) {
		printf("p[%d]: %s\n", i, p[i]);
	}

	//排序
	for (i = 0; i < num3; i++) {
		for (j = i; j < num3; j++) {
			if (strcmp(p[i], p[j]) > 0) {
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}

	//遍历
	printf("sort after\n");
	for (i = 0; i < num3; i++) {
		printf("p[%d]: %s\n", i, p[i]);
	}



	*array_3p = p;
	*num3_p = num3;

END:
	return ret;
}


int main(void)
{
	int	ret = 0;

	char	*p1[] = { "aaa", "ccccc", "bbbb" };
	char	buf2[10][30] = { "111111", "3333", "2222" };
	char	**p3 = NULL;

	int	len1, len2, len3, i = 0;

	len1 = sizeof(p1) / sizeof(*p1);
	len2 = 3;

	ret = sort(p1, len1, buf2, len2, &p3, &len3);


	free_mem(&p3, len3);

	if (p3 == NULL) {
		printf("free succ!\n");
	}


	return 0;
}