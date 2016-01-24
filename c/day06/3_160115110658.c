#include <stdio.h>

int main(void)
{
	FILE *p=frepen("out","w",p);
//	FILE *p = stdout;
	fprintf(p,"12346\n");
	return 0;
}
