#include <stdio.h>
#include <stdlib.h>

int mystrlen(const char *p)//得到字符串长度
{
	int len = 0;
	while(p[len])
	{
		len++;
	}
	return len;
}


int pow_10(int n)//得到10的n次方
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 10;
	int base = 10;
	int i;
	for(i = 1; i < n; i++)
	{
		base *= 10;
	}
	return base;
}

int myatoi(const char *p)
{
	const char *tmp = NULL;
	int status = 0;//0代表正数，1代表负数
	if (*p == '-')
	{
		status = 1;
		tmp = p + 1;//会从第二个字符开始转化
	}
	else if (*p == '+')
	{
		tmp = p + 1;
	}
	else
	{
		tmp = p;
	}

	int len = mystrlen(tmp);
	int value = 0;
	int i;
	for(i = 0; i < len; i++)
	{
		value += (tmp[i] - '0') * pow_10(len - i - 1);
	}
	if (status == 0)
		return value;
	else
		return -value;


}

int main()
{
	char a[100] = { 0 };
	scanf("%s", a);
	printf("%d\n", myatoi(a));
	return 0;
}



