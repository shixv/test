#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//封装成一个接口。
//求出  一个母串中 子串出现的个数
int strnstr(char *str,char *sub)
{
	int cnt=0;
	if(!*sub)return 0;
	for(char *p=str;p=strstr(p,sub);cnt++,p=p+strlen(sub));
	return cnt;
}
int main(void)
{
	char *str="castdskj23432cast4032cast9239847cast23479cast";
	char *sub="cast";
	printf("%d\n",strnstr(str,sub));
	return 0;
}
int main1(void)
{
	char *str = "32132131232itcast2u1893u219itcast321893itcast\0";
	//                                                                                         ↑
	char *sub_str = "itcast";
	char *p = NULL;
	int cnt = 0;

	p = str;

	while (  (p = strstr(p, sub_str) )   != NULL )
	{
		cnt++;
		p = p + strlen(sub_str);
		if (*p == '0') {
			break;
		}
	}

	printf("cnt = %d\n", cnt);
	return 0;
}

int main2(void)
{
	char *str = "32132131232itcast2u1893u219itcast321893itcast";
	//                                                                                 ↑
	char *sub_str = "itcast";
	char *p = NULL;

	int cnt = 0;
	p = str;

	//do-while
	do 
	{
		p = strstr(p, sub_str);
		if (p != NULL) {
			//找到了子串
			cnt++;
			p++;
		}
	} while (p != NULL);

	printf("itcast's cnt = %d\n", cnt);

	return 0;
}
