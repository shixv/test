#include <stdio.h>

int weishu(char *p);
int main()
{
	char p[100];
	scanf("%s",p);
//	printf("%s",p);
	printf("wei shu shi: %d\n",weishu(p));
	return 0;
}
int weishu(char *p)
{
	int i=0;
	while(i<100&&(p[i]=='0'||p[i]=='1'||p[i]=='2'||p[i]=='3'||p[i]=='4'||p[i]=='5'||p[i]=='6'||p[i]=='7'||p[i]=='8'||p[i]=='9'))i++;
	return i;
}
