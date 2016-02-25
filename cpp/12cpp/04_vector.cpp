#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
//��ӡ����
void printVector(vector<int> v){
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
}
//����VECTOR
void test01(){
	vector<int> v; //�����յ�VECTOR����
	vector<int> v2(10, 2); //�������Ĺ��캯��
	vector<int> v3(v2); //��������
	vector<int> v4(v2.begin(),v2.end());
	//��ӡ
	printVector(v2);
	cout << endl;
	printVector(v3);
	cout << endl;
	printVector(v4);
	cout << endl;
	//�����ʼ��
	int arr[] = { 4, 2, 8, 6 };
	vector<int> v5(arr,arr+sizeof(arr)/sizeof(int));
	printVector(v5);
	cout << endl;
}
//vector���ø�ֵ����
void test02(){
	//�������ҳ�ʼ������
	int arr[] = {1,5,7,2};
	vector<int> v1(arr,arr+sizeof(arr)/sizeof(int));
	vector<int> v2; //�յ�vector����
	v2.assign(v1.begin(),v1.end());
	vector<int> v3;
	v3 = v2; //=�Ÿ�ֵ
}
//��С����
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
	//����resize
	v.resize(10);
	cout << "size:" << v.size() << endl;
	printVector(v);
}
//��̬����ԭ��
void test04(){
	//�����յ�VECTOR����
	vector<int> v;
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
	v.reserve(100000);
	int* address = NULL; 
	int count = 0; //ͳ���ڴ��׵�ַ�仯����
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
//vector������ֵ����
void test05(){
	vector<int> v;
	v.assign(10,5);
	vector<int> v2;
	v2 = v;
}
//swapСר��
void test06(){
	int arr1[] = {1,8,4,5};
	int arr2[] = {7,8,9,1};
	vector<int> v1(arr1,arr1+sizeof(arr1)/sizeof(int));
	vector<int> v2(arr2, arr2 + sizeof(arr2) / sizeof(int));
	//������ӡV1
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//������ӡV2
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it ++){
		cout << *it << " ";
	}
	cout << endl;
	//�������������е�Ԫ��
	v1.swap(v2);
	cout << "����֮��:" << endl;
	//������ӡV1
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//������ӡV2
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	//������ӡ
	for (int i = 0; i < v1.size(); i ++){
		cout << v1[i] << " ";
	}
	cout << endl;
	//at��Ա����
	for (int i = 0; i < v1.size(); i++){
		cout << v1.at(i) << " ";
	}
	cout << endl;
	//back��front����
	cout << v1.front() << endl;
	cout << v1.back() << endl;
}
//vector���������ɾ������
void test07(){
	int arr[] = {1,2,6,4};
	vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
	//ͷ�巨
	v.insert(v.begin(),10);
	//��ӡ
	for (vector<int>::iterator it = v.begin(); it != v.end(); it ++){
		cout << *it << " ";
	}
	cout << endl;
	//��β�����Ԫ��
	v.push_back(100);
	//��ӡ
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	v.pop_back();
	//��ӡ
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	//�������
	//v.erase(v.begin(), v.end());
	//v.clear();
	v.erase(v.begin());
	//cout << "size:" << v.size() << endl;
	//��ӡ
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
