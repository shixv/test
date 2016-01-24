#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//遍历my_array

//void print_array(char *   *my_array, int len)
void print_array(char*my_array[], int len)
{
	int i = 0;

	for (i = 0; i < len; i++)
	{
		printf("%s\n", my_array[i]);
		//printf("%s\n", *(my_array + i));
	}
}

int sort_array(char *my_array[], int len)
{
	int i = 0;
	int j = 0;

	char *temp_p = NULL;

	for (i = 0; i < len; i++) {
		for (j = i; j < len; j++) {
			if (strcmp(my_array[i], my_array[j]) > 0) {
				temp_p = my_array[i];
				my_array[i] = my_array[j];
				my_array[j] = temp_p;
			}
		}
	}


	return 0;
}

// a[i] ===> a[0+i] ===> *(a + i)

int main(void)
{
	char* my_array[] = { "aaaaa", "cccc", "bbbb", "11111" };

	int len = sizeof(my_array) / sizeof(my_array[0]);

	printf("排序之前\n");
	print_array(my_array, len);



	sort_array(my_array, len);


	printf("排序之后\n");
	print_array(my_array, len);

	return 0;
}
