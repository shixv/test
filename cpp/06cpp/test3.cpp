#include <iostream>

using namespace std;

class base
{
	private:
		int m_i;
		int m_j;
	public:
		base(int i):m_j(i),m_i(m_j){
		}
		base():m_j(0),m_i(m_j){}
		int get_i(){return m_i;}
		int get_j(){return m_j;}
};

int main(void)
{
	base obj(1);
	return 0;
}
