#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//c �е�const ��һ���ٻ������������ĳ�����
void const_test(const int *p)
{
	*((int*)p) = 30; //����ͨ��ǿ��ת�����޸�һ����ջ�Ͽ��ٵ�const ����
	                       //��Ϊ������ ջ�Ͽ��ٵ��ڴ���ǿ����޸ġ�
}

void const_test2( const int *const p)
{
	//*p = 30; 
	//p++;
}


int main(void)
{
	const int a = 10;//����a�����ڳ��������ٵ��ڴ棬������Ȼ��ջ�����ٵġ�
	                         //ֻ����������ڴ棬����һ��ֻ�������ԡ�
	int b = 20;
	const_test(&a);

	const_test2(&b);

	return 0;
}
