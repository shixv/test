#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
int	replaceSubstr(char	*src,	char**	dst,   char	*sub,		  char	*new_sub)
*/
// "abcd23123213abcd13213abcd3213"
//  ↑
int replace_sub_str(char *src, char **dst, char *sub, char *new_sub)
{
	char *p = src;
	char *out = NULL;
	char *q = NULL;
	int new_sub_len = 0;
	int old_sub_len = 0;

	if (src == NULL || dst == NULL || sub == NULL || new_sub == NULL)
	{
		printf("%s:%d, src == NULL || dst == NULL || sub == NULL || new_sub == NULL\n",__FUNCTION__, __LINE__);
		return -1;
	}


	//先给传出的dst 开辟一块内存
	out = (char*)malloc(sizeof(char)* 4096);
	if (out == NULL)
	{
		printf("malloc out error\n");
		return -1;
	}
	memset(out, 0, 4096);

	p = src;
	q = p;
	new_sub_len = strlen(new_sub);
	old_sub_len = strlen(sub);

	while ((p = strstr(p, sub)) != NULL)
	{
		//找到了原子串
		strncat(out, q, p - q);
		strncat(out, new_sub, new_sub_len);

		p += old_sub_len;
		q = p;
		if (*q == '\0') {
			break;
		}
	}

	if (*q != '\0')
	{
		strncat(out, q, (src + strlen(src) )- q);
	}

	*dst = out;

	return 0;
}

void free_out(char *dst)
{
	if (dst != NULL)
	{
		free(dst);
	}
}

int main(void)
{
	char *str = "abcd23123213abcd13213abcd";
	char *dst = NULL;

	replace_sub_str(str, &dst, "abcd", "X");

	printf("dst:%s\n", dst);

	free_out(dst);
	dst = NULL;

	return 0;
}
