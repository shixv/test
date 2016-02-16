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
	delete ap; //û�з�����̬ //delete ������������������ ����������������̬
	//���ap�������������麯����delete ap �ڵ������������� �ᷢ����̬�� delete ���ദ��
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
	//	delete bp; //ͨ��delete �������ָ�� ����ø���������������Լ�����������

	return 0;
}
