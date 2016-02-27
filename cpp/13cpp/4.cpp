#include <iostream>
#include <set>
using namespace std;

class compare{
	public:
		bool operator()(int v1,int v2){
			return v1>v2;
		}
};
void test01(){
	set<int> s;
	set<int> s2(s);
	set<int> s3;
	s3=s2;
	s3.swap(s2);

	if(!s.empty()){
		cout<<"bukong"<<endl;
	}
	else{
		cout<<"koong"<<endl;
	}
}
void test02(){
	set<int,compare> s;
	s.insert(5);
	s.insert(1);
	s.insert(0);
	s.insert(2);
	s.insert(4);
	for(auto it=s.begin();it!=s.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	s.erase(s.begin());
	s.erase(5);
	for(auto it=s.begin();it!=s.end();it++){
		cout<<*it<<" ";
	}

}
class Player{
	public:
		string name;
		int score;
};
class compare1{
	public:
		bool operator()(Player p1,Player p2){
			return p1.score>p2.score;
		}
};
void test03(){
	set<Player,compare1> s;
	Player p1("aaa",10);
	Player p2("bbb",20);
	Player p3("ccc",30);
	for(auto it=s.begin;it!=s.ed:
int main(void)
{
	test01();
	test02();
	return 0;
}
