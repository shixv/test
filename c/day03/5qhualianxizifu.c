#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
1、有一个字符串“1a2b3d4z” ；
要求写一个函数实现如下功能：
功能1：把偶数位字符挑选出来，组成一个字符串1。
功能2：把奇数位字符挑选出来，组成一个字符串2。
功能3：把字符串1和字符串2，通过函数参数，传送给main，并打印。
功能4：主函数能测试通过。
int	getStr1Str2(char	*source,	char	*buf1,	char	*buf2);

*/
//1234\0
//       ↑
//abcd\0
//       ↑

//1a2b3d4d\0
//               ↑
int get_str1_str2(char *source, char *buf1, char *buf2)
{
	char *p = source;
	char *temp_buf1 = buf1;
	char *temp_buf2 = buf2;

	if (source == NULL || buf1 == NULL || buf2 == NULL) {
		printf("source == NULL || buf1 == NULL || buf2 == NULL\n");
		return -1;
	}

	while (*p != '\0')
	{
		*temp_buf1 = *p;
		temp_buf1++;
		p++;

		*temp_buf2 = *p;
		temp_buf2++;
		p++;
	}

	*temp_buf1 = '\0';
	*temp_buf2 = '\0';

	return 0;
}

int main(void)
{
	char *str = "1a2b3d4z";
	char buf1[64] = { 0 };
	char buf2[64] = { 0 };
	
	if (get_str1_str2(str, buf1, buf2) < 0) {
		printf("get_str1_str2 error\n");
		return -1;
	}

	printf("buf1 : %s\n", buf1);
	printf("buf2 : %s\n", buf2);



	return 0;
}
