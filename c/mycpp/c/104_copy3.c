#include <stdio.h>
#include <string.h>
#define SIZE 40
#define LIM 5
#define TARGSIZE 40

int main(void)
{
	char qwords[LIM][TARGSIZE];
	char temp[SIZE];
	int i = 0;
	
	printf("Enter %d words beginning with q: \n",LIM);
	while(i<LIM&&gets(temp))
	{
		if(temp[0]!='q')
			printf("%s does't bengin with q! \n",temp);
		else
		{
			strncpy(qwords[i],temp,TARGSIZE -1);
			i++;
		}
	}
	puts("Here are the words accept: \n");
	for(i=0;i<LIM;i++)
		puts(qwords[i]);
	return 0;
}
