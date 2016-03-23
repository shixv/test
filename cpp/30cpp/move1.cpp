#include <iostream>
#include <vector>
using namespace std;

template <class T>
void Mswap(T& a,T& b)
{
	T temp(move(a));
	a=move(b);
	b=move(temp);
}
class A
{
	public:
		A(){cout<<"A()"<<endl;}
		~A(){cout<<"~A()"<<endl;}
		A(const A& a){cout<<"copy A()"<<endl;}
		A(A&& a){cout<<"move A()"<<endl;}
		A& operator=(A& a){cout<<"assign A"<<endl;return *this;}
		A& operator=(A&& a){cout<<"move assign A"<<endl;return *this;}
};
int main(void)
{
	//	vector<A> Va;
	//	for(int i=0;i<3;i++){
	//		Va.push_back(A());
	//	}
	A a;
	a	=A();
	A b(a);
	cout<<"-------"<<endl;
	Mswap<A>(a,b);
	return 0;
}
