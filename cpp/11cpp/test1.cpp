#include <iostream>
using namespace std;
class A
{
	public:
		A(){cout<<"A()"<<endl;}
		~A(){cout<<"~A()"<<endl;}
		A(const A &a){cout<<"A(const A &)"<<endl;}
		void print(void){cout<<"wo shi yi ge yi chang"<<endl;}
};
void test(int i)throw(A,A *)
{
	if(i==1)
		throw new A;
//	if(i==2)
//		throw &(A());
	throw 666;
}
#if 1
int main(void)
{
	try{
		test(1);
	}
	catch(A *a)
	{
		a->print();
		delete a;
	}
	catch(A &a)
	{
		a.print();
	}
	catch(int a)
	{
		cout<<a<<endl;
	}
//	abort();
	return 0;
}
#endif
