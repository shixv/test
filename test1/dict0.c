﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#define MAX 111111 //最大记录数

struct dict
{
	char *key;
	char *content;
};


void format_string(char *str)//去掉字符串结尾的回车，空格字符
{
	size_t i;
	for(i = strlen(str) - 1; i >= 0; i--)
	{
		if (str[i] != '\n' && str[i] != ' ' && str[i] != '\r')
		{
			str[i + 1] = '\0';
			break;
		}
	}	
}

//打开字典文件，并读取文件内容
int open_dict(struct dict **p, const char *word)
{
	FILE *pfile = fopen("dict.txt", "r");
	if (pfile == NULL)
		return 0;//打开文件失败，函数返回

	*p = (struct dict *)malloc(sizeof(struct dict));//固定分配MAX大小内存
	memset(*p, 0, sizeof(struct dict));//将分配内存初始化为0

	char buf[1024] = { 0 };
	size_t len = 0;
//	int i = 0;//计数器
	while (!feof(pfile))//循环读取文件，直到文件末尾
	{
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), pfile);//读取文件一行
		len = strlen(buf);//得到读取到字符串长度
		if (len > 0)
		{
			(*p)->key = (char *)malloc(len);//根据字符串长度分配内存
//			memset(*p->key, 0, len);
			format_string(buf);//去掉字符串结尾的空格和回车
			strcpy((*p)->key, &buf[1]);//将读取到的内容拷贝到key中
		}

//		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), pfile);
		len = strlen(buf);
		if (len > 0)
		{
			(*p)->content = (char *)malloc(len);
//			memset((*p)->content, 0, len);
			strcpy((*p)->content, &buf[6]);
		}
		if(strcmp((*p)->key,word)==0)
		{
			fclose(pfile);
			printf("%s\n",(*p)->content);
			return 1;
		}
		else
		{
			continue;
		}


//		i++;//计数器加1
//		*p = (struct dict *)realloc(*p, sizeof(struct dict) * (i+1));
//		(*p)[i]={0,0};
	}
	fclose(pfile);//关闭字典文件
	free(*p);
	return 0;//返回读取到的字典词条数
}

//根据关键字key,在字典中查找内容
/*
int search_dict(const struct dict *p, int size, const char *key, char *content)
{
	int i = 0;
	for (i = 0; i < size; i++)//遍历字典
	{
		if ((p[i].key == NULL) || (p[i].content == NULL))
			continue;

		if (strcmp(p[i].key, key) == 0)
		{
			strcpy(content, p[i].content);
			return 1;//找到符合条件记录，返回1
		}
	}
	return 0;//没有找到符合条件记录，返回0
}
*/
//释放内存
/*
void free_dict(struct dict *p, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)//循环释放key与content成员内存
	{
		if (p[i].key)
			free(p[i].key);
		if (p[i].content)
			free(p[i].content);
	}
	free(p);//释放p内存
}
*/

int main(int argc, char *args[])
{
	if (argc < 2)
	{
		printf("usage: %s dict-filename\n", args[0]);
		return 0;//参数不足，程序退出
	}
	long start_ms = 0;//记录函数执行的开始时间
	long end_ms = 0;//记录函数执行的结束时间
	struct dict *p = NULL;
	start_ms = clock();
	int dict_size = open_dict(&p, args[1]);//根据命令行第一个参数做为字典文件名，打开字典文件
	end_ms = clock();
	if (dict_size == 0)
	{
		printf("no result.\n");
		return 0;
	}

//	end_ms = clock();
	printf("open_dict used %ld ms\n", end_ms - start_ms);//打印函数执行时间，单位：毫秒
/*
	char key[1024];
	char content[1024];
	while (1)
	{
		memset(key, 0, sizeof(key));
		memset(content, 0, sizeof(content));
		fgets(key, sizeof(key), stdin);//从键盘得到用户输入
		format_string(key);//去掉字符串结尾的空格和回车
		if (strncmp(key, "command=exit", 12) == 0)
			break;

		start_ms = clock();
		if (search_dict(p, dict_size, key, content))//根据用户输入，在字典中检索
		{
			printf("%s", content);
		} else
		{
			printf("not found\n");
		}
		end_ms = clock();
		printf("search_dict used %ld ms\n", end_ms - start_ms);//打印函数执行时间，单位：毫秒
	}

	start_ms = clock();
	free_dict(p, dict_size);
	end_ms = clock();
	printf("free_dict used %ld ms\n", end_ms - start_ms);//打印函数执行时间，单位：毫秒
*/
	return 0;
}
