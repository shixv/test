#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//void print_array(char **array, int len)
//void print_array(char (*array)[6], int len)//void print_array((char[6] )  *array, int len)
void print_array(char  array[][6], int len)
{
	int i = 0;

	for (i = 0; i < len; i++)
	{
		//printf("%s\n", array[i]);
		printf("%s\n", *(array + i));//array+1 ==>(unsigned int) array+ sizeof(char*)
												//array+1 ===>(unsigned int)array + sizeof(char[6])
	}
}

int sort_array(char(*array)[6], int len)
{
	int i = 0;
	int j = 0;
	char buf[6] = { 0 };

	for (i = 0; i < len; i++) {
		for (j = i + 1; j < len; j++)
		{
			if (strcmp(array[i], array[j]) > 0) {
				strcpy(buf, array[i]);
				strcpy(array[i], array[j]);
				strcpy(array[j], buf);
			}
		}
	}
	return 0;
}

int main(void)
{
	char my_array[4][6] = { "aaaaa", "ccccc", "bbb", "1111" };

	int len = 4;

	printf("排序之前\n");
	print_array(my_array, len);

	sort_array(my_array, len);


	printf("排序之后\n");
	print_array(my_array, len);
	return 0;
}

