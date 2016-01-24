#include <iostream>
#include <cmath>

using namespace std;
//int gval;
//int gval=10;
struct student
{
	int id;
	char name[64];
};
void print_student(student st);
void test()
{
//	cout<<f<<endl;
}
int f()
{
	return 10;
}
enum season
{
	spr,
	sum,
	aut,
	win
};
int g(int a)
{
	return 100;
}

int main(void)
{
//	int a;
//	int b;
	for(int i=0;i<10;i++)
	{

	}
//	bool a=true;
//	bool b=false;
//	cout<<sizeof(a)<<endl;
	const int a=10;
	const int b=20;
//	g(9);
//	struct student s1;
//	student s2;
//  (a<b?a:b)=5;
	cout<<a<<endl;
	cout<<b<<endl;
	const int c=10;
	cout<<&c<<endl;
	int *p=(int *)&c;
	cout<<p<<endl;
	*p=30;
	cout<<c<<endl;
	int array[a+b]={0};
	const int f=10;
	enum season s=spr;
	s=spr;
	int k=3477;
	cout<<sqrt(k)<<endl;
	return 0;
}
