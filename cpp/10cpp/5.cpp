#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
template<class T>
class A
{
public:
	T value;
	static T s_value; //��̬��Ա����
};
template<class T>
T A<T>::s_value = 0; //��̬��Ա����
int main(void)
{
	A<int> a1, a2, a3;
	A<char> b1, b2, b3;
	A<char>::s_value = 'X';
	A<int>::s_value =200; //�ı����A<int>��ľ�̬��Ա����s_value;
	cout << "a1:" << a1.s_value << endl;
	cout << "a2:" << a2.s_value << endl;
	cout << "a3:" << a3.s_value << endl;
	cout << b1.s_value << endl; //A<char>�ľ�̬��Աs_value�� A<int>����һ��
	cout << "b1:" << b1.s_value << endl;
	cout << "b2:" << b2.s_value << endl;
	cout << "b3:" << b3.s_value << endl;
	return 0;
}
