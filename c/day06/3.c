#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_NAME "C:/test/test2.txt"

void test_write_char(void)
{
	char *str = "abcdefg";

	FILE *fp = NULL;
	int i = 0;
	int len = 0;

	fp = fopen(FILE_NAME, "w+");
	if (fp == NULL) {
		printf("fopen %s error\n", FILE_NAME);
		return;
	}

	len = strlen(str);

	
			printf("fputc %c error\n", str[i]);
			break;
		}
	}


	if (fp != NULL) {
		fclose(fp);
		fp = NULL;
	}

}

void test_read_char()
{
	FILE *fp = NULL;
	char buf[128] = { 0 };
	char ch = 0; //每次从文件中读取的字符
	int i = 0;

	fp = fopen(FILE_NAME, "r+");
	if (fp == NULL) {
		printf("fopen %s error\n", FILE_NAME);
		return;
	}

	while ((ch = fgetc(fp)) != EOF) {
		buf[i] = ch;
		i++;
	}

	printf("buf:%s\n", buf);


	if (fp != NULL) {
		fclose(fp);
		fp = NULL;
	}
}

int main(void)
{
	//test_write_char();
	test_read_char();

	return 0;
}
