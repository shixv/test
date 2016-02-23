#include <iostream>
using namespace std;

template<class T>
class A
{
	private:
		T data;
	public:
		friend ostream &operator<<(ostream &os,A<T> &a)
		{
			return os;
		}
};
/*
template<class T>
ostream &operator<<(ostream &os,A<T> &a)
{
	return os;
}
*/
int main(void)
{
	A<int> a;
	return 0;
}
		
