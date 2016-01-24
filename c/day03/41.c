#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//c 中的const 是一个假货，不是真正的常量。
void const_test(const int *p)
{
	*((int*)p) = 30; //可以通过强制转换来修改一个在栈上开辟的const 变量
	                       //因为本质上 栈上开辟的内存就是可以修改。
}

void const_test2( const int *const p)
{
	//*p = 30; 
	//p++;
}


int main(void)
{
	const int a = 10;//变量a不是在常量区开辟的内存，而是依然在栈区开辟的。
	                         //只不过给这块内存，加了一个只读的属性。
	int b = 20;
	const_test(&a);

	const_test2(&b);

	return 0;
}
