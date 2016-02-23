#include <iostream>
#include "mystackpp.h"

using namespace std;

class B
{
	public:
		int data;
		char ch;
		B()
		{
			data=0;
			ch='a';
		}
		B(int n,char c)
		{
			data=n;
			ch=c;
		}
		~B()
		{
		}
};
int main(void)
{
	B b;	
	Stack<B> A;
	for(int i=0;i<10;i++)
	{
		b.data=i;
		b.ch='a'+i;
		A.push(b);
	}
	for(int i=0;i<10;i++)
	{
		A.gettop(&b);
		A.pop();
		cout<<b.data<<","<<b.ch<<endl;
	}

	return 0;
}
