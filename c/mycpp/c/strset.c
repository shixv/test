#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[6]="abcdc";
	strset(a,'c');
	printf("%s\n",a);
}
