#include <iostream>
#include <string>
#include <stack>
using namespace std;
void test01(){
	stack<int> s1;
	stack<int> s2(s1);
	stack<int> s3=s2;
	stack<int> s4;
	s4=s2;
}
void test02(){
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout<<"Top :"<<s.top()<<endl;
	while(s.size()>0){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
}
class Player{
	public:
		Player(string name, int age):m_name(name),m_age(age){}
	public:
		string m_name;
		int m_age;
};
void test03(){
	stack<Player> s;
	Player p1("aaa",10);
	Player p2("bbb",20);
	Player p3("ccc",30);
	s.push(p1);
	s.push(p2);
	s.push(p3);
	while(s.size()>0){
		Player p=s.top();
		cout<<"Name : "<<p.m_name<<"Age: "<<p.m_age<<endl;
		s.pop();
	}
}
void test04(){
	stack<Player*> s;
	Player p1("aaa",10);
	Player p2("bbb",20);
	Player p3("ccc",30);
	s.push(&p1);
	s.push(&p2);
	s.push(&p3);
	while(!s.empty()){
		Player* p=s.top();
		cout<<"Name: "<<p->m_name<<"Age: "<<p->m_age<<endl;
		s.pop();
	}
}
int main(void)
{
	test02();
	test03();
	test04();
	return 0;
}
