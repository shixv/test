#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//普通函数
void myPrint(int a, int b)
{
	cout << "普通函数" << endl;
	cout << "a = " << a << ", b = " << b << endl;
}
//模板函数
template<class T>
void myPrint(T a, T b)
{
	cout << "模板函数" << endl;
	cout << "a = " << a << ", b = " << b << endl;
}
//1  如果没有普通函数 ，编译器找到一个能够匹配数据类型的模板函数调用
//2  如果 有 普通函数能够完全匹配， 优先调用普通函数
//3 当普通函数能够通过隐式转换匹配， 但是模板函数能够直接匹配，优先掉模板
//4 模板函数是按照T 进行严格匹配，不存在隐式转换
int main(void)
{
	int a = 10;
	int b = 20;
	myPrint(10, 20);
	char xChar = 'a';
	char yChar = 'b';
	cout << " -----" << endl;
	myPrint(xChar, yChar);
	cout << " ----- " << endl;
	myPrint(a, yChar);
	return 0;
}
