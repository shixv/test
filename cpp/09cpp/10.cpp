#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//��ͨ����
void myPrint(int a, int b)
{
	cout << "��ͨ����" << endl;
	cout << "a = " << a << ", b = " << b << endl;
}
//ģ�庯��
template<class T>
void myPrint(T a, T b)
{
	cout << "ģ�庯��" << endl;
	cout << "a = " << a << ", b = " << b << endl;
}
//1  ���û����ͨ���� ���������ҵ�һ���ܹ�ƥ���������͵�ģ�庯������
//2  ��� �� ��ͨ�����ܹ���ȫƥ�䣬 ���ȵ�����ͨ����
//3 ����ͨ�����ܹ�ͨ����ʽת��ƥ�䣬 ����ģ�庯���ܹ�ֱ��ƥ�䣬���ȵ�ģ��
//4 ģ�庯���ǰ���T �����ϸ�ƥ�䣬��������ʽת��
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
