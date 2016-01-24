#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//C语言中没有字符串类型， 用一个字符数组+\0表示字符串。

// 0   '0'  NULL  0x0000000 , \0

int main(void)
{
	char str1[] = "abcd"; //char[5]
	char *str2 = "abcd";
	char str3[] = { 'a', 'b', 'c', 'd' }; //char [4]
	char str4[128] = { 'a', 'b', 'c' };//char[128] //后面没有初始化的默认都是  0 ===>\0
	int a = 10;
	unsigned int i = 0;

	//128:  'a' 'b' 'c' \0 0000000

	sizeof(str1); //求数据类型大小   5
	strlen(str1); //求字符串中字符的个数。不包括\0  4

	printf("sizeof(str1) :%d\n", sizeof(str1));
	printf("strlen(str1) :%d\n", strlen(str1));
	printf("sizeof(str3):%d\n", sizeof(str3));

	printf("sizeof(str4): %d\n", sizeof(str4));//128
	printf("strlen(str4):%d\n", strlen(str4)); //3


	for (i = 0; i < strlen(str1); i++)
	{
		printf("%c\n", str1[i]);
		//str1[i]
		//printf("%c\n", *(str1 + i));
	}

	char *p = NULL;

	for (p = str1; *p != '\0'; p++)
	{
		printf("%c\n", *p);
	}

#if 0
	for (; *str1 != '\0'; str1++)
	{
		printf("%c\n", *str1);
	}
#endif


	//指针和数组名的区别。
	// 1 数组名是一个常量的指针，他永远指向数组的元素的地址。
	//	  指针是可以改变的。
	//2  通过数组下标的直接索引 要比通过指针间接的索引的速度要快。
	//3  为什么数组名不能修改呢？
	//   之所以 数组名名不能够修改， 就是因为一般数组都是在栈上开辟空间的。
			//栈的空间都是由操作系统进行回收和管理的，如果数组名进行了偏移和修改
		  //操作系统就无法找到之前的 已经开辟的连续空间的首地址，

	// 4 一般如果是在栈上开辟内存就用数组，在堆上开辟内存就用指针。




	return 0;
}
