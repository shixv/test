#include <iostream>

using namespace std;

class Test
{
public:
	Test()
	{
		this->a = 0;
		this->b = 0;
	}
	Test(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	void printT()
	{
		cout << "a = " << this->a << "  b =  " << this->b << endl;
	}

	int getA()
	{
		return this->a;
	}
	int getB()
	{
		return this->b;
	}

	Test TestAdd(Test &t1, Test &t2)
	{
		Test temp(t1.getA() + t2.getA(), t1.getB() + t2.getB());
		return temp;
	}

	Test TestAdd2(Test &another)
	{
		Test temp(this->a +another.a, this->b + another.b);
		return temp;
	}
	
	// �����ʵ��+= ��ʽ
	void TestAdd3(Test &another)
	{
		this->a += another.a;
		this->b += another.b;
	}

	//���һ����Ա�����뷵�ض�����
	//����ֵ ��  ���������
	//return *this;
	Test & TestAdd4(Test &another)
	{
		this->a += another.a;
		this->b += another.b;

		//this ---- &t2

		return *this;
	}

private:
	int a;
	int b;
};

//��ȫ��дһ�����������������Test��������
/*
Test TestAdd(Test &t1, Test &t2)
{
	Test temp(t1.getA() + t2.getA(), t1.getB() + t2.getB());
	return temp;
}


*/

int main(void)
{
	Test t1(10, 20);
	Test t2(100, 200);

	Test t3 = t2.TestAdd2(t1);

	t3.printT();


	cout << " ----- " << endl;


	t2.TestAdd3(t1);

	t2.printT();

	cout << " -----" << endl;

	t2.TestAdd4(t1).TestAdd4(t1).printT();

	
	
	return 0;
}
