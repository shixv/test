#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

/*
cin.get() //һ��ֻ�ܶ�ȡһ���ַ�
cin.get(һ������) //��һ���ַ�
cin.get(��������) //���Զ��ַ���
cin.getline()
cin.ignore()
cin.putback()
*/

//��׼cin>>Ĭ�ϵ��� ���ݿո�������ÿһ������
void test1()
{
	int myInt;
	long myLong;
	char buf[128] = { 0 };

	cin >> myInt;
	cin >> myLong;
	cin >> buf;

	cout << "myInt :" << myInt << endl;
	cout << "myLong :" << myLong << endl;
	cout << "buf :" << buf << endl;

}

void test2()
{
	char ch;

	while ((ch = cin.get()) != EOF) {
		cout << ch << endl;
	}
}

void test3()
{
	char a, b, c;

	char buf[10] = { 0 };

	cout << "���������ݵ��������� ����cin.get(a)ȥ�����ȴ����������ݣ������������û�����ݣ�������" << endl;
	//cin.get(a); //�ӻ������ж�һ���ֽڣ� �浽a��
	//cin.get(b);
	//cin.get(c);



	//cout << "a = " << a << endl;
	//cout << "b = " << b << endl;
	//cout << "c = " << c << endl;
	cin.get(buf, 10, ' ');

	cout << "buf :" << buf << endl;

}

int main(void)
{
	//test1();

	//test2();

	test3();
	
	return 0;
}
