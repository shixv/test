#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//����һ���ַ������׵�ַ����const���Σ�Ϊ��ȷ����func����
//���ڣ���ȥ�޸�p��ָ����ڴ�����ݡ�
void func(const char *p)
{
	//char *pp = (char*)p;//C����ͨ��()ǿ��ת��
	char *pp = const_cast<char*>(p); //�����ĺ�����ǽ�һ��constָ���const����ȥ��
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
	const int a = 10; //a ����һ������
	const int *a_p = &a; //����ʱ����һ������  ��a_p ȥָ�������ʱ�Ŀռ�
	//��a_p��const ����ȥ��
	int *a_p1 = const_cast<int*>(a_p);
	*a_p1 = 100;
	cout << "*a_p: " << *a_p << endl;
	cout << "a : " << a << endl;
	int *a_p2 = const_cast<int*>(&a);
	*a_p2 = 200; //�޸ĵ���Ȼ��һ����ʱ�ı��� ������a����
	cout << "*a_p2: " << *a_p2 << endl;
	cout << "a : " << a << endl;
	return 0;
}
