#include <iostream>
using namespace std;
class Parent
{
public:
	Parent(int a)
	{
		this->a = a;
	}
	virtual void print()
	{
		cout << "Parent :: a = " << a << endl;
	}
	int a;
};
class Child : public Parent
{
public:
	Child(int a) :Parent(a)
	{
	}
	virtual void print()
	{
		cout << "Child :: a = " << a << endl;
	}
	int b;
};
int main(void)
{
	Child array[] = { Child(0), Child(1), Child(2) };
	//						array[0]    array[1]  array[2]
	Child *cp = &array[0];
	Parent *pp = &array[0];
	cp->print(); // 子类
	pp->print(); // 子类
	//父类指针 指向子类对象的时候， 如果想发生多态，不要给父类指针累加， 
	cp++; //指针的++ cp+= sizeof(Child)
//	pp++;//               cp += sizeof(Parent)
//	cp->print(); // 子类
//	pp->print(); // 子类
	cout << "-----" << endl;
	int i = 0;
	for (i = 0, cp = &array[0], pp = cp; i < 3; i++, cp++, pp = cp) {
		cp->print();
		pp->print();
	}
	return 0;
}
