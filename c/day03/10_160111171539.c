#include <stdio.h>
#include <stdlib.h>


int get_mem(char ***array_p,int num)
{
	char **array=NULL;
	array=(char **)malloc(sizeof(char **)*num);
	*array_p=array;
	return 0;
}
int main(void)
{
	char ***p=NULL;
	get_mem(p,10);
	return 0;
}				
