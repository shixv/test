#include <iostream>
#include <cstring>

using namespace std;

class A
{
	public:
		A() {
			cout << "A()..." << endl;
			this->p = new char[64];
			memset(this->p, 0, 64);
			strcpy(this->p, "A string");
		}

		virtual void print()
		{
			cout << "A::print(): " << p << endl;
		}
		virtual ~A()
		{
			cout << "~A()..." << endl;
			if (this->p != NULL) {
				delete[] this->p;
				this->p = NULL;
			}
		}
	private:
		char *p;
};

class B :public A
{
	public:
		B()
		{
			cout << "B()..." << endl;
			this->p = new char[64];
			memset(this->p, 0, 64);
			strcpy(this->p, "B string");
		}

		virtual void print()
		{
			cout << "B::print(): " << p << endl;
		}

		virtual ~B()
		{
			cout << "~B().." << endl;
			if (this->p != NULL) {
				delete[] this->p;
				this->p = NULL;
			}
		}
	private:
		char *p;

};
class C:public B
{
	public:
		C()
		{
			cout << "C()..." << endl;
			this->p = new char[64];
			memset(this->p, 0, 64);
			strcpy(this->p, "C string");
		}

		virtual void print()
		{
			cout << "C::print(): " << p << endl;
		}

		virtual ~C()
		{
			cout << "~C().." << endl;
			if (this->p != NULL) {
				delete[] this->p;
				this->p = NULL;
			}
		}
	private:
		char *p;
};


void myFunc(A *ap)
{
	ap->print();

	//delete ap;
}

void deleteFunc(A* ap)
{ 
	delete ap; //没有发生多态 //delete 会调用类的析构函数， 让析构函数发生多态
	//如果ap的析构函数是虚函数，delete ap 在调用析构函数的 会发生多态， delete 子类处理
}

int main(void)
{
	A *ap = new A;
	B *bp = new B; //A(), B()
	C *cp = new C;

	myFunc(ap);
	cout << "----" << endl;
	myFunc(bp);

	cout << "------" << endl;

	deleteFunc(ap);

	cout << "=====" << endl;

	deleteFunc(bp);

	cout<<"---------"<<endl;

	deleteFunc(cp);

	//	delete ap;
	//	delete bp; //通过delete 子类对象指针 会调用父类的析构函数和自己的析构函数

	return 0;
}
