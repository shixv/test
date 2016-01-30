#include <iostream>

using namespace std;

class Test
{
	public:
		explicit Test()
		{
			this->value = 0;
		}
		explicit Test(int value)
		{
			this->value = value;
		}

		Test operator+(Test &another)
		{
			cout << "ִ����+���ز�����" << endl;
			Test temp(this->value + another.value);
			return temp;
		}

		bool operator&&(Test another)
		{
			cout << "ִ����&&����������" << endl;
			if (this->value && another.value) {
				return true;
			}
			else {
				return false;
			}
		}

		bool operator||(Test another)
		{
			cout << " ִ����||����������" << endl;
			if (this->value || another.value) {
				return true;
			}
			else {
				return false;
			}
		}
//		operator Test&(Test t)
//		{
//			Test &rt=t;
//			return rt;
//		}

	private:
		int value;
};

int main(void)
{
	int a = 10;

	if (a && (a = 20))
	{

	}

	a = 10;

	if (a || (a = 30))
	{

	}


	cout << "a = " << a << endl;

	cout << " ----" << endl;

	Test t1(10);
	Test t2(20);

	//����&&������ �����ܷ�����·���� ���ܹ���֤��Ĭ�ϵ�&&һ�����塣
	if (t1 && (t1 +t2) ) //t1.operator&&(t2) // t1.operator&&(   t1.operator+(t2)   )
	{
		cout << " true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}


	cout << "-----" << endl;

	if (t1 || (t1 + t2))  //t1.operator||(   t1.opeator+(t2)   )
	{
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	return 0;
}
