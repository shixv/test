#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

class Sqr
{
public:
	Sqr(int a)
	{
		this->a = a;
	}

	int operator()(int value, int value2)
	{
		return this->a *value;
	}

private:
	int a;
};

int main(void)
{
	Sqr s(10); 

	s(10, 20); //s.operator()(10);  //如果一个类重载了（）操作符，
			//就可以将这个对象，以一个函数的形式调用了
			//这种就叫 这个对象是一个 仿函数 伪函数
	
	return 0;
}
