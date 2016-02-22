#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//接收一个字符串的首地址，用const修饰，为了确保在func函数
//体内，不去修改p所指向的内存块内容。
void func(const char *p)
{
	//char *pp = (char*)p;//C语言通过()强制转换
	char *pp = const_cast<char*>(p); //此语句的含义就是讲一个const指针的const属性去掉
	*pp = 'X';
}
int main(void)
{
	const char *p = "1234567";
	char buf[] = "1234567";
	func(buf);
	//func(p);
	cout << "buf:" << buf << endl;
	cout << "p: " << p << endl;
	cout << "-----" << endl;
	const int a = 10; //a 就是一个常量
	const int *a_p = &a; //会临时开辟一个变量  让a_p 去指向这个临时的空间
	//把a_p的const 属性去掉
	int *a_p1 = const_cast<int*>(a_p);
	*a_p1 = 100;
	cout << "*a_p: " << *a_p << endl;
	cout << "a : " << a << endl;
	int *a_p2 = const_cast<int*>(&a);
	*a_p2 = 200; //修改的依然是一个临时的变量 并不是a本身
	cout << "*a_p2: " << *a_p2 << endl;
	cout << "a : " << a << endl;
	return 0;
}
