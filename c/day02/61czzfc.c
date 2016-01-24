#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//封装成一个接口。
//求出  一个母串中 子串出现的个数

//return -1 失败  其他 代表个数
int get_sub_str_cnt(char *str, char *sub_str)
{
	char *p = str;
	int cnt = 0;

	if (str == NULL || sub_str == NULL)
	{
		printf("str == NULL || sub_str == NULL\n");
		return -1;
	}

	while (  (p = strstr(p, sub_str) ) != NULL) {
		cnt++;
		p = p + strlen(sub_str);
		if (*p == '\0') {
			break;
		}
	}

	return cnt;
}

int get_sub_str_cnt2(char *str, char *sub_str, int *cnt_p)
{
	char *p = str;
	int ret = 0;
	int cnt = 0;

	if (str == NULL || sub_str == NULL || cnt_p == NULL) {
		fprintf(stderr, "str == NULL || sub_str == NULL || cnt_p == NULL\n");
		ret = -1;
		goto END;
	}

	while ((p = strstr(p, sub_str)) != NULL) {
		cnt++;
		p = p + strlen(sub_str);
		if (*p == '\0') {
			break;
		}
	}

	*cnt_p = cnt;//通过间接操作 来改变外部的cnt 的值。

END:
	return ret;
}


int main(void)
{
	char *str = "32132131232itcast2u1893u219itcast321893itcast";
	//                                                                                         ↑
	char *sub_str = "itcast";

	int cnt = 0;
	int ret = 0;

	cnt = get_sub_str_cnt(str, sub_str);
	if (cnt < 0) {
		printf("get_sub_str_cnt error\n");
		return 0;
	}

	printf("cnt = %d\n", cnt);

	printf("-------\n");

	cnt = 0;

	ret = get_sub_str_cnt2(str, sub_str, &cnt);
	if (ret < 0) {
		printf("get_sub_str_cnt2 error\n");
		return 0;
	}
	printf("cnt = %d\n", cnt);

	return 0;
}

#if 0
int main(void)
{
	char *str = "32132131232itcast2u1893u219itcast321893itcast";
	//                                                                                         ↑
	char *sub_str = "itcast";
	char *p = NULL;
	int cnt = 0;

	p = str;

	while (  (p = strstr(p, sub_str) )   != NULL )
	{
		cnt++;
		p = p + strlen(sub_str);
		if (*p == '\0') {
			break;
		}
	}

	printf("cnt = %d\n", cnt);
	return 0;
}
#endif

#if 0
int main(void)
{
	char *str = "32132131232itcast2u1893u219itcast321893itcast";
	//                                                                                 ↑
	char *sub_str = "itcast";
	char *p = NULL;

	int cnt = 0;
	p = str;

	//do-while
	do 
	{
		p = strstr(p, sub_str);
		if (p != NULL) {
			//找到了子串
			cnt++;
			p++;
		}
	} while (p != NULL);

	printf("itcast's cnt = %d\n", cnt);

	return 0;
}
#endif
