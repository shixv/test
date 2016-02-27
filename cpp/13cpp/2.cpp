#include <iostream>
#include <queue>
using namespace std;

void test01(){
	queue<int> q;
	queue<int> q1(q);
	queue<int> q2;
	q2=q1;
}

void test02(){
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	while(q.size()!=0){
		int val=q.front();
		cout<<val<<" ";
		q.pop();
	}
}
class Player{
	public:
		Player(){}
		Player(string s,int a):name(s),age(a){}
		Player(const Player& p):name(p.name),age(p.age){}
	public:
		string name;
		int age;
};
void test03(){
	queue<Player> q;
	Player p1("aaa",10);
	Player p2("bbb",20);
	Player p3("ccc",30);
	q.push(p1);
	q.push(p2);
	q.push(p3);
	while(q.size()>0){
		Player p=q.front();
		cout<<"Name: "<<p.name<<"Age: "<<p.age<<endl;
		q.pop();
	}
}
void test04(){
	queue<Player*> q;

	Player p1("aaa",10);
	Player p2("bbb",20);
	Player p3("ccc",30);

	q.push(&p1);
	q.push(&p2);
	q.push(&p3);
	
	while(!q.empty()){
		q.front();
		Player* p=q.front();
		cout<<"Name :"<<p->name<<"Age :"<<p->age<<endl;
		q.pop();
	}
}
int main(void)
{
	test02();
	test03();
	test04();
	return 0;
}
