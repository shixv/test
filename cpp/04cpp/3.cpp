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

	//this ָ�� ����ʵ������ָ��ö���ĳ�ָ��
	// ���������thisָ��Ϊconst ֻ�����ͣ�thisָ����ָ��Ķ����ܹ����޸�
	//��Ҫ�ڳ�Ա�����ĺ����const
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
