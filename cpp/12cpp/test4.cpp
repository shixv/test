#include <iostream>
using namespace std;

template<class T>
class MyClass{
	public:
		MyClass(){}
		MyClass(const MyClass<T>& x)
		{
			cout<<"bulit-in constructor"<<endl;
		}
		template<class U>
			MyClass(const MyClass<U>& x)
			{
				cout<<"template copy constructor"<<endl;
			}
};
void f()
{
	MyClass<double> xd;
	MyClass<double> xd2(xd);
	MyClass<int> xi(xd);
}
int main(void)
{
	f();
	cout<<char(102)<<endl;
	return 0;
}
