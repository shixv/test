#include <iostream>
using namespace std;
class Parent
{
	public:
		virtual void func(int a)
		{
			cout << "Parent Func a =" << a << endl;
		}
	private:
		int a;
};
class Parent2
{
	public:
		void func(int a)
		{
			cout << "Parent2  Func a =" << a << endl;
		}
	private:
		int a;
};
int main(void)
{
	Parent p1;
	Parent2 p2;
	cout << "sizeof(p1) " << sizeof(p1) << endl;
	cout << "sizeof(p2) " << sizeof(p2) << endl;
	return 0;
}
