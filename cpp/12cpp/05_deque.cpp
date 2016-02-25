#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>
using namespace std;
//deque������ʼ��
void test01(){
	deque<int> d1; //Ĭ�Ϲ���
	deque<int> d2(10,5); //�������Ĺ��캯��
	deque<int> d3(d2.begin(), d2.end()); //�������Ĺ��캯��
	deque<int> d4(d3); //��������
	//��ӡ
	for (deque<int>::iterator it = d4.begin(); it != d4.end(); it ++){
		cout << *it << " ";
	}
	cout << endl;
}
//deque������ֵ����
void test02(){
	deque<int> d(10, 4);
	deque<int> d1; //�յ�deque
	//d1 = d;
	d1.assign(8,8);
	//d1.assign(d.begin(),d.end());
	//��ӡ
	for (deque<int>::iterator it = d.begin(); it != d.end(); it ++){
		cout << *it << " ";
	}
	cout << endl;
	for (deque<int>::iterator it = d1.begin(); it != d1.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	cout << "����֮��:" << endl;
	d.swap(d1);
	//��ӡ
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	for (deque<int>::iterator it = d1.begin(); it != d1.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}
//deque��С����
void test03(){
	deque<int> d(10,6);
	cout << "size:" << d.size() << endl;
	if (d.empty() == true){
		cout << "��!" << endl;
	}
	else{
		cout << "����!" << endl;
	}
	//�ı�size��С
	d.resize(5);
	cout << "size:" << d.size() << endl;
}
//deque�����ɾ��
void test04(){
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	//��ӡ
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	//��ӡ
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	//ȥ��ͷ�� ȥ��β��
	d.pop_front(); //ɾ��ͷ��Ԫ��
	d.pop_back(); //ɾ��β��Ԫ��
	//��ӡ
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	cout << "front:" << d.front() << endl;
	cout << "back:" << d.back() << endl;
	//�������
	d.insert(d.begin(),90);
	//��ӡ
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}
//deque����ɾ������
void test05(){
	deque<int> d;
	d.push_back(100);
	d.push_back(200);
	d.push_back(300);
	//ɾ��ȫ��Ԫ��
	d.erase(d.begin(),d.end());
	//d.clear();
	cout << "size:" << d.size() << endl;
	//ɾ��ָ��λ��
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
