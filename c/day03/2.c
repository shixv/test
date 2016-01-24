#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// "1234567\0"
// "abcdefg\0"
//  1234567abcdefg\0

char	*my_stract(char	*x, char*	y)
{
	char	str[80];
	char	*z = str;											/*指针z指向数组str*/
	while (*z++ = *x++);
	z--;																				/*去掉串尾结束标志*/
	while (*z++ = *y++);
	z = str;																	/*将str地址赋给指针变量z*/
	return(z);
}

int main(void)
{


	return 0;
}
