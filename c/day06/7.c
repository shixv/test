#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_NAME  "C:/test/test7.txt"

struct teacher
{
	int id;
	int age;
	char *name;
	int name_len;
};

int main(void)
{
	struct teacher tp;
	int ret = 0;

#if 0
	tp.id = 10;
	tp.age = 20;
	tp.name = malloc(sizeof(char)* 64);
	memset(tp.name, 0, 64);
	strcpy(tp.name, "zhang3");
	tp.name_len = strlen(tp.name);

	FILE *fp = NULL;

	fp = fopen(FILE_NAME, "wb+");
	if (fp == NULL) {
		printf("fopen errorn\n");
		return -1;
	}

	//先将老师结构体存到文件中
	ret = fwrite(&tp, sizeof(struct teacher), 1, fp);
	if (ret < 0) {
		printf("fwrite error\n");
		return -1;
	}

	//再将 name所关联的字符串存到文件中
	ret = fwrite(tp.name, tp.name_len, 1, fp);
	if (ret < 0) {
		printf("fwrite name error\n");
		return -1;
	}



#endif

	FILE*fp = fopen(FILE_NAME, "rb+");
	if (fp == NULL) {
		printf("fopen error\n");
		return -1;
	}


	//先读一个结构体
	ret = fread(&tp, sizeof(struct teacher), 1, fp);
	if (ret < 0) {
		printf("fread error\n");
		return -1;
	}

	//再读字符串
	tp.name = (char*)malloc(sizeof(char)*(tp.name_len +1) );
	memset(tp.name, 0, tp.name_len + 1);

	ret = fread(tp.name, tp.name_len, 1, fp);
	if (ret < 0) {
		printf("fread name error\n");
		return -1;
	}


	printf("id = %d, age = %d, name = %s, name_len = %d\n", tp.id, tp.age, tp.name, tp.name_len);



	
	if (fp != NULL) {
		fclose(fp);
		fp = NULL;
	}

	return 0;
}
