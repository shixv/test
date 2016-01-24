#include	<stdio.h>


void	copy_str(char	*from, char	*to)
{
	if (from == NULL || to == NULL)
	//if (*from == '\0' || *to == '\0') //代表校验的是指针所指向的内存块是否为0
	{
		printf("func	copy_str()	err\n");
		return;
	}
	for (; *from != '\0'; from++, to++)
	{
		*to = *from;
	}
	*to = '\0';
}

void copy_str_err(char *from, char *to)
{
	char *temp_from = from;
	char *temp_to = to;

	for (; *temp_from != '\0'; temp_from++, temp_to++)
	{
		*temp_to = *temp_from;
	}
	*temp_to = '\0';


	printf("to:%s", to);
	printf("from:%s", from);
}

int	main()
{
	char	*p = "aabbccdd";
	char	to[100] = { 0 }; //?
	copy_str(p, to);
	printf("to	:	%s\n", to);
	return 0;
}