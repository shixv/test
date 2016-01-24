#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc,char *argv[])
{
	printf("%2.3lf\n",atof("2.039"));
	printf("%2d\n",atoi("123"));
	printf("%ld\n",atol("1233"));
	printf("%d,%d\n",isalnum('1'),isalnum('\n'));
	printf("%d,%d\n",isalpha('w'),isalpha('2'));
	printf("%d,%d\n",iscntrl('\n'),iscntrl('2'));
	printf("%d,%d\n",isdigit('3'),isdigit('i'));
	printf("%d,%d\n",isgraph('e'),isgraph(' '));
	printf("%d,%d\n",islower('e'),islower('E'));
	printf("%d,%d\n",isprint('3'),isprint('\0'));
	printf("%d,%d\n",ispunct('\n'),ispunct(' '));
	printf("%s\n",strpbrk("1213424532","34"));
	return 0;
}
