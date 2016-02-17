#include <iostream>
using namespace std;
class Parent
{
	public:
		virtual void func(int a,int b)
		{
			cout<<"Parent::func(int ,int)..."<<endl;
		}
		virtual void func(int a,int b,int c)
		{
			cout<<"Parent::func(int ,int ,int )...."<<endl;
		}
	private:
		int b;
};
class Child:public Parent
{
	public:
		virtual void func(int a,int b)
		{
			cout<<"Child::func(int ,int).."<<endl;
		}
	private:
		int b;
};
int main(void)
{
	Parent *p = new Child;
	p->func(10,20,30);
	p->func(10,20);
	return 0;
}
