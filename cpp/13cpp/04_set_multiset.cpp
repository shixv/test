#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<string>
using namespace std;
//创建set容器
void test01(){
	set<int> s; //空的set集合
	set<int> s2(s); //拷贝构造
	set<int> s3;
	s3 = s2;
	s3.swap(s2);
	if (!s.empty()){
		cout << "不空@" << endl;
	}
	else{
		cout << "空" << endl;
	}
}
class compare{
	public:
		bool operator()(int v1,int v2){
			return v1 > v2;
		}
};
//set容器插入和删除
void test02(){
	//创建空的集合
	set<int, compare> s;
	s.insert(5);
	s.insert(3);
	s.insert(2);
	s.insert(10);
	//遍历
	for (set<int,compare>::iterator it = s.begin(); it != s.end(); it ++){
		cout << *it << " ";
	}
	cout << endl;
	//删除
	s.erase(s.begin()); //删除第一个位置
	s.erase(10); //删除10
	//遍历
	for (set<int>::iterator it = s.begin(); it != s.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}
class player{
	public:
		player(string name, int score) :name(name), score(score){}
	public:
		string name;
		int score;
};
//仿函数用来约定set容器排序的规则
class compare2{
	public:
		bool operator()(player p1, player p2){
			return p1.score > p2.score;
		}
};
void test03(){
	//创建一个存储player对象的集合set，并且指定他的排序规则
	set<player, compare2> s;
	//创建数据
	player p1("aaa", 10);
	player p2("bbb", 20);
	player p3("ccc", 30);
	//插入数据
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	//遍历
	for (set<player, compare2>::iterator it = s.begin(); it != s.end();it ++){
		cout << "Name:" << (*it).name << " Score:" << (*it).score << endl;
	}
}
int main(){
	//test02();
	test03();
//	system("pause");
	return EXIT_SUCCESS;
}
