#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//在堆上开辟一个二维数组
char **get_mem(int num)
{
	char **array = NULL;
	int i = 0;

	array = (char**)malloc(sizeof(char*)* num);
	if (array == NULL) {
		printf("malloc array error\n");
		return NULL;
	}
	memset(array, 0, sizeof(char*)*num);
	
	for (i = 0; i < num; i++)
	{
		array[i] = (char*)malloc(sizeof(char)* 64);
		if (array[i] == NULL) {
			printf("malloc array[%d] error\n", i);
			return NULL;
		}

		//赋值
		sprintf(array[i], "%d%d%d", 9 - i, 9 - i, 9 - i); //array[0]==>999
	}


	return array;

}

void print_array(char **array, int len)
{
	int i = 0;

	for (i = 0; i < len; i++)
	{
		printf("%s\n", array[i]);
	}
}

int sort_array(char **array, int len)
{
	int i = 0; 
	int j = 0;
	char *temp = NULL;

	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++) {
			if (strcmp(array[i], array[j]) > 0) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}

	return 0;
}

int free_array(char **array,int len)
{
	for(int i=0;i<len;i++)
		free(array[i]);
	free(array);
	return 0;
}

int main(void)
{
	char **my_array = NULL;
	
	my_array = get_mem(3);

//	printf("交换之前\n");
	print_array(my_array, 3);


	sort_array(my_array, 3);

//	printf("交换之后\n");
	print_array(my_array, 3);

	free_array(my_array,3);



	return 0;
}
