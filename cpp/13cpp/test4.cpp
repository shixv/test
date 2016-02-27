#include <iostream> using namespace std;
class B
{
	public:
	int data;
	B():data(1){}
	B(int n):data(n){}
};
class A
{
	public:
		int data;
		B b;
	public:
	A():data(0){}
	A(int a):data(a),b(3){}
	A(const A& a){data=a.data;}
	~A(){}
	B& operator*(A* a){return a->b;}
	A operator*(A& a){A temp;temp.data=(a.data)*(this->data);return temp;}
	
};

int main(void)
{
	A a(3);
	A c(2);
	A d=a*c;
	A* b=new A(2);
	cout<<d.data<<endl;
	cout<<(*b).data<<endl;
	return 0;
}
