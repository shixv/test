//.........
#include <stdio.h>

int main()
{
	int m,n;
	printf("qing shu ru M he N: \n");
	scanf("%d %d",&n,&m);
	if(!(n<5&&n<31&&(7*n+m)<=31))return 0;
	printf("shi zhe ge yue de di %d tian.\n",7*n+m);
	return 0;
}
/* 
#include <time.h>
#include <stdio.h>

int main()
{
	struct tm *tm_ptr;
	time_t the_time;

	(void)time(&the_time);
	tm_ptr=gmtime(&the_time);
	int mday=tm_ptr->tm_mday;
	int wday=tm_ptr->tm_wday;
	int d=mday%7;
	(wday+1>d)?(wday-=d):(wday=7-d+wday);
	int m,n;

	printf("shu ru M N\n");
	scanf("%d %d",&m,&n);
	int i=0,j=0;
	while(i<n)
	{
		wday++;
		if(wday==7){wday=0;i++;}
		j++;
	}
	for(i=0;i<m;i++)
	{
		wday++;i++;
		if(wday==7)wday=0;
	}
	printf("shi zhe ge yue de di %d tian\n",j);
	return 0;
}*/
