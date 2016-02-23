#include <iostream>
#include "sqqueue.h"
using namespace std;

class A
{
	public:
		int n;
		char ch;
		A(){};
		A(int a,char b):n(a),ch(b){}
};
int main(void)
{
	Queue<A> q(100);
	A a(0,'a');
	for(int i=0;i<100;i++)
	{
		a.n=i;
		a.ch='a'+i;
		q.enqueue(a);
	}
	for(int i=0;i<100;i++)
	{
		q.dequeue(a);
		cout<<a.n<<","<<a.ch<<endl;
	}
	return 0;
}
