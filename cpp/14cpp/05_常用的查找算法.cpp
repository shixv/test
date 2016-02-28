#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//find算法
void test01(){
	/*
		template<class _InIt,
		class _Ty> inline
		_InIt _Find(_InIt _First, _InIt _Last, const _Ty& _Val, false_type)
		{	// find first matching _Val
		for (; _First != _Last; ++_First)
		if (*_First == _Val)
		break;
		return (_First);
		}
		*/
	vector<int> v;
	v.push_back(5);
	v.push_back(2);
	v.push_back(1);
	v.push_back(10);
	vector<int>::iterator ret = find(v.begin(), v.end(), 1);
	if (ret == v.end()){
		cout << "没有找到!" << endl;
		return;
	}
	cout << "ret:" << *ret << endl;
}
class Player{
	public:
		Player(string name, int age) :name(name), age(age){}
		bool operator==(const Player& p){
			if (this->name.compare(p.name) == 0 && this->age == p.age){
				return true;
			}
			else{
				return false;
			}
		}	
	public:
		string name;
		int age;
};
void test02(){
	vector<Player> v;
	Player p1("aaa", 10);
	Player p2("bbb", 20);
	Player p3("ccc", 30);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	vector<Player>::iterator ret = find(v.begin(), v.end(), p2);
	if (ret == v.end()){
		cout << "没有找到!" << endl;
		return;
	}
	cout << (*ret).name << " " << (*ret).age << endl;
}
//adjacent_find 查找相邻重复元素
void test03(){
	vector<int> v;
	v.push_back(5);
	v.push_back(2);
	v.push_back(2);
	v.push_back(7);
	v.push_back(1);
	vector<int>::iterator ret = adjacent_find(v.begin(),v.end());
	if (ret == v.end()){
		cout << "没有找到!" << endl;
		return;
	}
	cout << "ret:" << *ret << endl;
}
//binary_search 二分查找
void test04(){
	vector<int> v;
	v.push_back(5);
	v.push_back(2);
	v.push_back(2);
	v.push_back(7);
	v.push_back(1);
	sort(v.begin(),v.end());
	bool flag = binary_search(v.begin(),v.end(),2);
	if (flag){
		cout << "查找到!" << endl;
	}
	else{
		cout << "没有查找到!" << endl;
	}
}
//find_if
struct MyCompre{
	bool operator()(int v){
		return v > 5;
	}
};
void test05(){
	/*
		template<class _InIt,
		class _Pr> inline
		_InIt _Find_if(_InIt _First, _InIt _Last, _Pr _Pred)
		{	// find first satisfying _Pred
		for (; _First != _Last; ++_First)
		if (_Pred(*_First))
		break;
		return (_First);
		}
		*/
	vector<int> v;
	v.push_back(5);
	v.push_back(2);
	v.push_back(2);
	v.push_back(7);
	v.push_back(1);
	vector<int>::iterator ret = find_if(v.begin(), v.end(), MyCompre());
	if (ret == v.end()){
		cout << "没有找到!" << endl;
		return;
	}
	cout << "ret:" << *ret << endl;
}
//count count_if
struct Greater2{
	bool operator()(int v){
		return v > 2;
	}
};
void test06(){
	vector<int> v;
	v.push_back(5);
	v.push_back(2);
	v.push_back(2);
	v.push_back(7);
	v.push_back(1);
	int cnt = count(v.begin(),v.end(),2);
	cout << "cnt:" << cnt << endl;
	cnt = count_if(v.begin(), v.end(), Greater2());
	cout << "cnt:" << cnt << endl;
}
int main(){
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	system("pause");
	return 0;
}
