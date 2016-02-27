#include <iostream>
using std::cout;
using std::endl;
class A
{
	public:
		A(){cout<<"A()..."<<endl;}
		A(const A& a){cout<<"copy A.."<<endl;}
		A(A&& a){cout<<"move A.."<<endl;}
		A& operator=(A& a){
			if(this==&a)return *this;
			cout<<"assign..."<<endl;
			return *this;
		}
		A& operator=(A&& a){
			if(this==&a)return *this;
			cout<<"move assign..."<<endl;
			return *this;
		}
};

A CO()
{
	return A();
}
template<class T>
void swapm(T& a,T& b)
{
	T temp(std::move(a));
	a=std::move(b);
	b=std::move(temp);
}
int main(void)
{
	auto a=A();
	auto b=A(a);
	A c;
	c=A(b);
	A d=CO();
	swapm(a,b);
	return 0;
}
