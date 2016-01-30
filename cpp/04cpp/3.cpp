#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

class Test
{
public:
	Test(int k)
	{
		m_k = k;
	}

	//this 指针 本质实际上是指向该对象的常指针
	// 如果想修饰this指针为const 只读类型，this指针所指向的对象不能够被修改
	//需要在成员函数的后面加const
	int getK() const 
	{
		//this->m_k = 100;
		//this->m_k = 100;
		return this->m_k;
	}

	/*
	int getK(Test *this) {
		return this->m_k;
	}
	*/
private:
	int m_k;
};

int main(void)
{
	Test t1(10);
	Test t2(20);

	t1.getK(); //getK(&t1);

	t2.getK(); //getK(&t2);
	
	return 0;
}
