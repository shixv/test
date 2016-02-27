#include <iostream>
#include <list>
using namespace std;

void test01(){
	list<int> l;
	list<int> l1(l);
	list<int> l2;
	list<int> l3(l.begin(),l.end());
	l2=l1;
	list<int> l4(10,5);
}
void test02(){
	list<int> l1;
	l1.push_back(100);
	l1.push_back(200);
	l1.push_back(300);
	l1.push_front(400);
	l1.push_front(500);
	l1.push_front(600);

	for(auto it=l1.begin();it!=l1.end();it++)
		cout<<*it<<endl;
}
int main(void)
{
	test01();
	test02();
	return 0;
}
