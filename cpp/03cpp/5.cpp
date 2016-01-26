#include <iostream>

using namespace std;

class Teacher
{
	private:
		int m_a;
	public:
		Teacher(int a)
		{
			cout<<"structer 1"<<endl;
			m_a=a;
		}
		Teacher(const Teacher &t)
		{
			cout<<"structer 2"<<endl;
			m_a=t.m_a;
		}
		~Teacher()
		{
			cout<<"end"<<m_a<<endl;
		}
};
int main(void)
{
	Teacher t1(12);
	Teacher t2=t1;
	return 0;
}
