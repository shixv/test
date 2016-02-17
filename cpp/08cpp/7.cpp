#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//抽象类1
class Interface1
{
	public:
		//纯虚函数
		virtual void func1(int a, int b) = 0;
		virtual void func2(int a) = 0;
};
//抽象类2
class Interface2
{
	public:
		//纯虚函数
		virtual void func3(int a, int b) = 0;
		virtual void func4(int a) = 0;
};
class Child :public Interface1, public Interface2
{
	public:
		virtual void func1(int a, int b) {
			cout << "func1" << endl;
		}
		virtual void func2(int a) {
			cout << "func2" << endl;
		}
		virtual void func3(int a, int b) {
			cout << "func3" << endl;
		}
		virtual void func4(int a)
		{
			cout << "func4" << endl;
		}
};
int main(void)
{
	Interface1 *if1 = new Child;
	Interface2 *if2 = new Child;
	if1->func1(10, 20);
	if1->func2(10);
	if2->func3(100, 200);
	if2->func4(100);
	return 0;
}
