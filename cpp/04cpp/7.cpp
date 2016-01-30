#include <iostream>

using namespace std;

class B;

class A
{
public:

	//������B ���ҵ���Ԫ��
	friend class B;

	A(int a)
	{
		this->a = a;
	}

	void print()
	{
		cout << a << endl;
		B bObj(1000);
		cout << bObj.b << endl;
	}
private:
	int a;
};

class B
{
public:
	B(int b)
	{
		this->b = b;
	}
	void print()
	{
		cout << b << endl;
	}
private:
	int b;
};

int main(void)
{
	B bb(100);

	bb.print();
	
	return 0;
}
