#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OUT		 //代表传出参数
#define IN		//代表传入参数

//提供一个接口，
//给main函数 提供两块内存，和这两块内存的大小，供main使用
//第一块内存的大小固定为300， 第二块内存的大小固定为400，
//第一块内存的内容为1234567字符串
//第二块内存的内容是abcdefg字符串

//返回值为0代表此函数运行正常。返回值小于1 代表出现错误。

/*
//给main函数 提供两块内存，和这两块内存的大小，供main使用
//第一块内存的大小固定为300， 第二块内存的大小固定为400，
//第一块内存的内容为1234567字符串
//第二块内存的内容是abcdefg字符串

pp1 (传出) ===> 需要开辟第一块的内存传出的地址   

pp2（传出）====>需要开辟第二块的内存传出的地址 

lenp_1（传出）===>第一块内存传出的长度

lenp_2（传出）====>第二块内存传出的长度

返回值的含义：
 0  ----- succ
 -1 代表失败

*/
int get_mem(OUT char **pp1 , OUT char **pp2,  OUT int *lenp_1, OUT int *lenp_2)
{
	char *p1 = NULL;
	char *p2 = NULL;
	int len1 = 0;
	int len2 = 0;

	//1 对所有的形参进行安全性合法性校验
	if (pp1 == NULL || pp2 == NULL || lenp_1 == NULL || lenp_2 == NULL) {
		printf("pp1 == NULL || pp2 == NULL || lenp_1 == NULL || lenp_2 == NULL \n");
		return -1;
	}

	//开辟第一块内存
	p1 = (char*)malloc(300);
	if (p1 == NULL) {
		printf("malloc p1 error\n");
		return -1;
	}

	memset(p1, 0, 300);
	len1 = 300;
	

	//开辟第二块内存
	p2 = (char*)malloc(400);
	if (p2 == NULL) {
		printf("malloc p2 error\n");
		return -1;
	}
	memset(p2, 0, 400);
	len2 = 400;


	//最终再向外部赋值
	*pp1 = p1;
	*pp2 = p2;
	*lenp_1 = len1;
	*lenp_2 = len2;

	return 0;
}

int free_mem(char *p1, char *p2)
{
	if (p1 != NULL) {
		free(p1);
		
	}
	if (p2 != NULL)
	{
		free(p2);
	}

	return 0;
}

int free_mem2(OUT char **pp1, OUT char **pp2)
{
	char *p1 = *pp1;
	char *p2 = *pp2;

	if (p1 != NULL) {
		free(p1);
	}
	if (p2 != NULL) {
		free(p2);
	}

	*pp1 = NULL;
	*pp2 = NULL;

	return 0;
}


int main(void)
{
	char *p1 = NULL;
	char *p2 = NULL; 
	int len1 = 0;
	int len2 = 0;

	int ret = 0;

	ret = get_mem(&p1, &p2, &len1, &len2);
	if (ret < 0) {
		printf("get_mem error\n");
		return 0;
	}


	
	printf("get_mem succc!\n");

	strcpy(p1, "1234557");
	strcpy(p2, "abcdefg");

	printf("p1 = %s\n", p1);
	printf("p2 = %s\n", p2);

	free_mem2(&p1, &p2);


	if (p1 == NULL) {
		printf("p1 == NULL\n");
	}

	if (p2 == NULL) {
		printf("p2 == NULL\n");
	}


	
#if 0
	free_mem(p1, p2);
	p1 = NULL;
	p2 = NULL;
#endif

#if 0
	if (p1 != NULL) {
		free(p1);
		p1 = NULL;
	}
	if (p2 != NULL) {
		free(p2);
		p2 = NULL;
	}
#endif

	return 0;
}
