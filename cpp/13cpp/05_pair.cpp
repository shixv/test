#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class Player{
	public:
		Player(string name,int age):name(name),age(age){}
	public:
		string name;
		int age;
};
int main(){
	//基础数据类型
	pair<int, int> pair1(10,20);
	cout << pair1.first << " " << pair1.second << endl;
	//对象
	pair<int, Player> pair2(20, Player("aaa", 30));
	cout << pair2.first << " " << pair2.second.name << " " << pair2.second.age << endl;
	//make_pair
	pair<int, Player> pair3 = make_pair(100, Player("bbb", 20));
	cout << pair3.first << " " << pair3.second.name << " " << pair3.second.age << endl;
//	system("pause");
	return EXIT_SUCCESS;
}
