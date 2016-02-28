#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
struct MyPrint{
	void operator()(int v){
		cout << v << " ";
	}
};
//内建函数对象
void tesy01(){
	plus<int> plus;
	cout << plus(10, 20) << endl;
	//创建vector
	vector<int> v;
	v.push_back(20);
	v.push_back(10);
	v.push_back(70);
	v.push_back(60);
	greater<int> myGreater;
	sort(v.begin(), v.end(), myGreater);
	for_each(v.begin(), v.end(), MyPrint());
}
struct MyPrint02 : public binary_function<int,int,void>{
	void operator()(int v,int v2) const{
		cout << "v:" << v << " v2:" << v2 << endl;
		cout << v + v2 << " ";
	}
};
//bind1st bind2nd 绑定适配器
void test02(){
	vector<int> v;
	for (int i = 0; i < 10;i++){
		v.push_back(i + 1);
	}
	int val = 50;
	for_each(v.begin(), v.end(), bind2nd(MyPrint02(),val));
	//给自定义函数对象继承一个基类 
	//如果是二元函数对象 继承binary_function<参数1类型,参数2类型，返回值类型>
	//如果是一元函数对象 继承unary_function<参数类型，返回值类型>
	//给重载胡函数调用符号() 加上CONST
}
//取反适配器not1 not2
struct MyCompare : public binary_function<int,int,bool>{
public:
	bool operator()(int v1,int v2) const{
		return v1 > v2;
	}
};
struct MyCompare02 : public unary_function<int,bool>{
	bool operator()(int v) const{
		return v > 3;
	}
};
void test03(){
	vector<int> v;
	v.push_back(5);
	v.push_back(6);
	v.push_back(1);
	v.push_back(3);
	sort(v.begin(), v.end(), not2(MyCompare()));
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
	vector<int>::iterator ret = find_if(v.begin(), v.end(),not1(MyCompare02()));
	cout << "ret:" << *ret << endl;
}
//ptr_fun 将普通函数适配成函数对象
void print04(int v,int v2){
	cout << v + v2 << " ";
}
void test04(){
	vector<int> v;
	v.push_back(5);
	v.push_back(6);
	v.push_back(1);
	v.push_back(3);
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(print04),100));
}
class Player{
public:
	Player(string name, int age) :m_name(name), m_age(age){}
	//成员函数 打印
	void print(){
		cout << "Name:" << m_name << " Age:" << m_age << "..." <<  endl;
	}
public:
	string m_name; 
	int m_age;
};
//mem_fun mem_fun_ref 适配成员函数
void test05(){
	//如果容器中放的是数据实体 恋情mem_fun_ref
	vector<Player> v;
	Player p1("aaa", 10);
	Player p2("bbb", 20);
	Player p3("ccc", 30);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	for_each(v.begin(), v.end(), mem_fun_ref(&Player::print));
	//如果容器元素类型是对象指针 用mem_fun
	vector<Player*> v2;
	v2.push_back(&p1);
	v2.push_back(&p2);
	v2.push_back(&p3);
	for_each(v2.begin(),v2.end(),mem_fun(&Player::print));
}
int main(){
	//tesy01();
	//test02();
	//test03();
	//test04();
	test05();
	system("pause");
	return 0;
}
