#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
//打印函数
void printVector(vector<int> v){
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
}
//创建VECTOR
void test01(){
	vector<int> v; //创建空的VECTOR容器
	vector<int> v2(10, 2); //带参数的构造函数
	vector<int> v3(v2); //拷贝构造
	vector<int> v4(v2.begin(),v2.end());
	//打印
	printVector(v2);
	cout << endl;
	printVector(v3);
	cout << endl;
	printVector(v4);
	cout << endl;
	//数组初始化
	int arr[] = { 4, 2, 8, 6 };
	vector<int> v5(arr,arr+sizeof(arr)/sizeof(int));
	printVector(v5);
	cout << endl;
}
//vector常用赋值操作
void test02(){
	//创建并且初始化容器
	int arr[] = {1,5,7,2};
	vector<int> v1(arr,arr+sizeof(arr)/sizeof(int));
	vector<int> v2; //空的vector容器
	v2.assign(v1.begin(),v1.end());
	vector<int> v3;
	v3 = v2; //=号赋值
}
//大小操作
void test03(){
	int arr[] = {5,3,8,9};
	vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
	printVector(v);
	cout << endl;
	cout << "-----------------" << endl;
	v.resize(2);
	cout << "size:" << v.size() << endl;
	printVector(v);
	//重新resize
	v.resize(10);
	cout << "size:" << v.size() << endl;
	printVector(v);
}
//动态增长原理
void test04(){
	//创建空的VECTOR容器
	vector<int> v;
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
	v.reserve(100000);
	int* address = NULL; 
	int count = 0; //统计内存首地址变化次数
	for (int i = 0; i < 100000; i ++){
		v.push_back(i);
		if (address != &v[0]){
			address = &v[0];
			count++;
		}
	}
	cout << "size:" << v.size() << endl;
	cout << "capacity : " << v.capacity() << endl;
	cout << "count:" << count << endl;
}
//vector容器赋值操作
void test05(){
	vector<int> v;
	v.assign(10,5);
	vector<int> v2;
	v2 = v;
}
//swap小专题
void test06(){
	int arr1[] = {1,8,4,5};
	int arr2[] = {7,8,9,1};
	vector<int> v1(arr1,arr1+sizeof(arr1)/sizeof(int));
	vector<int> v2(arr2, arr2 + sizeof(arr2) / sizeof(int));
	//遍历打印V1
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//遍历打印V2
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it ++){
		cout << *it << " ";
	}
	cout << endl;
	//交换两个容器中的元素
	v1.swap(v2);
	cout << "交换之后:" << endl;
	//遍历打印V1
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//遍历打印V2
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	//【】打印
	for (int i = 0; i < v1.size(); i ++){
		cout << v1[i] << " ";
	}
	cout << endl;
	//at成员方法
	for (int i = 0; i < v1.size(); i++){
		cout << v1.at(i) << " ";
	}
	cout << endl;
	//back和front方法
	cout << v1.front() << endl;
	cout << v1.back() << endl;
}
//vector容器插入和删除操作
void test07(){
	int arr[] = {1,2,6,4};
	vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
	//头插法
	v.insert(v.begin(),10);
	//打印
	for (vector<int>::iterator it = v.begin(); it != v.end(); it ++){
		cout << *it << " ";
	}
	cout << endl;
	//向尾部添加元素
	v.push_back(100);
	//打印
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	v.pop_back();
	//打印
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	//清空数据
	//v.erase(v.begin(), v.end());
	//v.clear();
	v.erase(v.begin());
	//cout << "size:" << v.size() << endl;
	//打印
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}
int main(){
	//test01();
	//test03();
	//test04();
	//test06();
	test07();
	system("pause");
	return EXIT_SUCCESS;
}
