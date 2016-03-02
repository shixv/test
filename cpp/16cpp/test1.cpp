#include <iostream>
using namespace std;
class A
{
	public:
		A(){cout<<"A().."<<endl;}
		~A(){cout<<"~A().."<<endl;}
		friend ostream& operator<<(ostream &os,A &a);
};
ostream& operator<<(ostream &os,const A& a){
	os<<"print";
	return os;
}
A test1()
{
	A a;
	return a;
}
int main(void)
{
	cout<<test1()<<endl;	
	return 0;
}
