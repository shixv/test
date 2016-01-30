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
			cout << "执行了+重载操作符" << endl;
			Test temp(this->value + another.value);
			return temp;
		}

		bool operator&&(Test another)
		{
			cout << "执行了&&操作符重载" << endl;
			if (this->value && another.value) {
				return true;
			}
			else {
				return false;
			}
		}

		bool operator||(Test another)
		{
			cout << " 执行了||操作符重载" << endl;
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

	//重载&&操作符 并不能发生短路现象， 不能够保证跟默认的&&一个含义。
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
