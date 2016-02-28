#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//一元函数对象 for_each
class MyPrint{
public:
	void operator()(int v){
		cout << v << " ";
	}
};
void test01(){
	vector<int> v;
	for (int i = 0; i < 10;i++){
		v.push_back(i+1);
	}
	MyPrint print;
	for_each(v.begin(),v.end(),print);
	cout << endl;
}
class Greater5{
public:
	bool operator()(int v){
		return v > 7;
	}
};
//一元谓词 find_if
void test02(){
	vector<int> v;
	v.push_back(7);
	v.push_back(10);
	v.push_back(12);
	vector<int>::iterator ret = find_if(v.begin(), v.end(), Greater5());
	if (ret == v.end()){
		cout << "没有找到!" << endl;
		return;
	}
	cout << "ret:" << *ret << endl;
}
//transform
class Plus100{
public:
	int operator()(int v){
		return v + 100;
	}
};
void test03(){
	vector<int> v;
	v.push_back(7);
	v.push_back(10);
	v.push_back(12);
	vector<int> dest; //目标容器
	dest.resize(v.size());
	transform(v.begin(), v.end(), dest.begin(), Plus100());
	for_each(dest.begin(), dest.end(), MyPrint());
	cout << endl;
}
struct MyCompare{
	bool operator()(int v1,int v2){
		return v1 > v2;
	}
};
//二元谓词
void test04(){
	vector<int> v;
	v.push_back(7);
	v.push_back(10);
	v.push_back(12);
	sort(v.begin(), v.end(), MyCompare());
	//遍历
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}
int main(){
	//test01();
	//test02();
	//test03();
	test04();
	system("pause");
	return 0;
}
