#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0

int	getMem(/*out*/char	**myp1,	/*out*/int	*mylen1,
/*out*/char	**myp2,	/*out*/int	*mylen2);

int	getMem_Free(char	**myp1);

#endif

int get_mem(char **myp1, int *mylen1, char **myp2, int *mylen2)
{
	char *buf1 = NULL;
	char *buf2 = NULL;
	int len1 = 0;
	int len2 = 0;

	if (myp1 == NULL || mylen1 == NULL || myp2 == NULL || mylen2 == NULL)
	{
		return -1;
	}

	buf1 = (char*)malloc(4096);
	if (buf1 == NULL) {
		printf("malloc buf1 error\n");
		return -1;
	}
	memset(buf1, 0, 4096);
	len1 = 4096;


	buf2 = (char *)malloc(4096);
	if (buf2 == NULL) {
		printf("malloc buf2 error\n");
		return -1;
	}
	memset(buf2, 0, 4096);
	len2 = 4096;


	//通过间接赋值 将buf1 和buf2 传出去
	//想在行数的内部来修改main：：buf1 ， 用*myp1   ，，  myp1 = main::&buf1;
	*myp1 = buf1;
	*myp2 = buf2;
	*mylen1 = len1;
	*mylen2 = len2;

	return 0;
}

void free_mem(char **mem1, char **mem2, int *lenp1, int *lenp2)
{
	char *buf1 = *mem1;
	char *buf2 = *mem2;


	if (buf1 != NULL)
	{
		free(buf1);
	}
	if (buf2 != NULL)
	{
		free(buf2);
	}

	*mem1 = NULL;
	*mem2 = NULL;
	*lenp1 = 0;
	*lenp2 = 0;
}

int main(void)
{
	char *buf1 = NULL;
	char *buf2 = NULL;
	int len1 = 0;
	int len2 = 0;

	if (get_mem(&buf1, &len1, &buf2, &len2) < 0)
	{
		printf("getMem error\n");
		return -1;
	}

	strcpy(buf1, "1234567");
	strcpy(buf2, "abcdefg");

	printf("buf1 : %s\n", buf1);
	printf("buf2: %s\n", buf2);

	printf("buf1 ---len = %d\n", len1);
	printf("buf2 ---len = %d\n", len2);


	free_mem(&buf1, &buf2, &len1, &len2);

	if (buf1 == NULL)
	{
		printf("buf1 == NULL\n");
	}
	if (buf2 == NULL)
	{
		printf("buf2 == NULL\n");
	}

	return 0;
}
