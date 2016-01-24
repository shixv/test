#include <stdio.h>

int main(void)
{
	int sec = 0;
	printf("input second:\n");
	scanf("%d",&sec);
	printf("%d hours %d minints %d seconds\n",(sec-sec%3600)/3600,((sec-sec%60)/60)%60,sec%60);
	return 0;
}
