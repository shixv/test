#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>
using namespace std;
//deque容器初始化
void test01(){
	deque<int> d1; //默认构造
	deque<int> d2(10,5); //带参数的构造函数
	deque<int> d3(d2.begin(), d2.end()); //带参数的构造函数
	deque<int> d4(d3); //拷贝构造
	//打印
	for (deque<int>::iterator it = d4.begin(); it != d4.end(); it ++){
		cout << *it << " ";
	}
	cout << endl;
}
//deque容器赋值操作
void test02(){
	deque<int> d(10, 4);
	deque<int> d1; //空的deque
	//d1 = d;
	d1.assign(8,8);
	//d1.assign(d.begin(),d.end());
	//打印
	for (deque<int>::iterator it = d.begin(); it != d.end(); it ++){
		cout << *it << " ";
	}
	cout << endl;
	for (deque<int>::iterator it = d1.begin(); it != d1.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	cout << "交换之后:" << endl;
	d.swap(d1);
	//打印
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	for (deque<int>::iterator it = d1.begin(); it != d1.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}
//deque大小操作
void test03(){
	deque<int> d(10,6);
	cout << "size:" << d.size() << endl;
	if (d.empty() == true){
		cout << "空!" << endl;
	}
	else{
		cout << "不空!" << endl;
	}
	//改变size大小
	d.resize(5);
	cout << "size:" << d.size() << endl;
}
//deque插入和删除
void test04(){
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	//打印
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	//打印
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	//去除头部 去除尾部
	d.pop_front(); //删除头部元素
	d.pop_back(); //删除尾部元素
	//打印
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	cout << "front:" << d.front() << endl;
	cout << "back:" << d.back() << endl;
	//插入操作
	d.insert(d.begin(),90);
	//打印
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}
//deque容器删除操作
void test05(){
	deque<int> d;
	d.push_back(100);
	d.push_back(200);
	d.push_back(300);
	//删除全部元素
	d.erase(d.begin(),d.end());
	//d.clear();
	cout << "size:" << d.size() << endl;
	//删除指定位置
	//d.erase(d.begin());
}
int main(){
	test01();
	test02();
	test03();
	test04();
	test05();
	return EXIT_SUCCESS;
}
