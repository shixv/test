#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int myInt;

//typedef int[10]  array10;

typedef int(array10)[10];


void print_array(array10 *p, int len)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < len; i++) {
		for (j = 0; j < 10; j++) {
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	myInt a = 20;
	int i = 0;

	//int b[10]; 

	array10 b;

	array10 bb[3] = { 0 };

	array10* p = NULL;
	//int(*p)[10] = NULL;

	for (i = 0; i < 10; i++) {
		b[i] = i;
	}

	printf("-----\n");
	print_array(bb, 3);

	return 0;
}
