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
	char	*z = str;											/*ָ��zָ������str*/
	while (*z++ = *x++);
	z--;																				/*ȥ����β������־*/
	while (*z++ = *y++);
	z = str;																	/*��str��ַ����ָ�����z*/
	return(z);
}

int main(void)
{


	return 0;
}
