#include <iostream>

using namespace std;

class Test
{
	private:
		int m_x;
		int m_y;
	public:
		void printT()
		{
			cout<<"x="<<m_x<<",y="<<m_y<<endl;
		}
		Test(int x,int y)
		{
			cout<<"Test() birth"<<endl;
			m_x=x;
			m_y=y;
		}
		~Test()
		{
			cout<<"Test() die"<<endl;
		}
};
void test1()
{
	Test t(10,20);
}
int main(void)
{
	Test a(10,20);
	a.printT();
	test1();
	return 0;
}
