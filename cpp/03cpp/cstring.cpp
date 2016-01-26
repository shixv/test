#include <iostream>

using namespace std;

class cs
{
	public:
		int a;
		cs()
		{
			a=1;
			cout<<"construct"<<a<<endl;
		}
		cs(int n)
		{
			a=n;
			cout<<"construct"<<a<<endl;
		}
		cs(const cs &c)
		{
			a=c.a;
			cout<<"construct"<<a<<endl;
		}
};
int main(void)
{
	cs i();
	cout<<i.a<<endl;
	cs b(2);
	cs c[3];
	cs &ra=b;
	cs d=b;
	cs *pA=c;
	cs *p=new cs(4);
	return 0;
}
