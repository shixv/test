#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
template<class T>
class A
{
public:
	T value;
	static T s_value; //静态成员变量
};
template<class T>
T A<T>::s_value = 0; //静态成员变量
int main(void)
{
	A<int> a1, a2, a3;
	A<char> b1, b2, b3;
	A<char>::s_value = 'X';
	A<int>::s_value =200; //改变的是A<int>类的静态成员变量s_value;
	cout << "a1:" << a1.s_value << endl;
	cout << "a2:" << a2.s_value << endl;
	cout << "a3:" << a3.s_value << endl;
	cout << b1.s_value << endl; //A<char>的静态成员s_value跟 A<int>不是一个
	cout << "b1:" << b1.s_value << endl;
	cout << "b2:" << b2.s_value << endl;
	cout << "b3:" << b3.s_value << endl;
	return 0;
}
