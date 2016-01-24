#include <stdio.h>

int main(void)
{
	const float MIN=0.0f;
	const float MAX=100.0f;
	
	float score;
	float total=0.0f;
	int n=0;
	float min = MIN;
	float max = MAX;
	
	printf("Enter the first score (q to quit): ");
	while(scanf("%f",&score)==1)
	{
		if(score<MIN||score>MAX)
		{
			printf("%0.1f is invalid value, try again.",score);
			continue;
		}
		printf("Accepting %0.1f: \n",score);
		min=(score
