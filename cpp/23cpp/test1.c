#include <stdio.h>
int main(void)
{
	int a;
	char b;
	int c;
	FILE* p=fopen("txt","r");
	fscanf(p,"%d.%c.%d",&a,&b,&c);
	return 0;
}
