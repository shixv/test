#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<string>
using namespace std;
//����set����
void test01(){
	set<int> s; //�յ�set����
	set<int> s2(s); //��������
	set<int> s3;
	s3 = s2;
	s3.swap(s2);
	if (!s.empty()){
		cout << "����@" << endl;
	}
	else{
		cout << "��" << endl;
	}
}
class compare{
public:
	bool operator()(int v1,int v2){
		return v1 > v2;
	}
};
//set���������ɾ��
void test02(){
	//�����յļ���
	set<int, compare> s;
	s.insert(5);
	s.insert(3);
	s.insert(2);
	pair<set<int,compare>::iterator,bool> ret = s.insert(10);
	if (ret.second){
		cout << "��һ�β���Ԫ�سɹ���" << endl;
	}
	else{
		cout << "��һ�β���ʧ��!" << endl;
	}
	ret = s.insert(10);
	if (ret.second){
		cout << "�ڶ��β���Ԫ�سɹ���" << endl;
	}
	else{
		cout << "�ڶ��β���ʧ��!" << endl;
	}
	//����
	for (set<int,compare>::iterator it = s.begin(); it != s.end(); it ++){
		cout << *it << " ";
	}
	cout << endl;
	//ɾ��
	s.erase(s.begin()); //ɾ����һ��λ��
	s.erase(10); //ɾ��10
	//����
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
//�º�������Լ��set��������Ĺ���
class compare2{
public:
	bool operator()(player p1, player p2){
		return p1.score > p2.score;
	}
};
void test03(){
	//����һ���洢player����ļ���set������ָ�������������
	set<player, compare2> s;
	//��������
	player p1("aaa", 10);
	player p2("bbb", 20);
	player p3("ccc", 30);
	//��������
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	//����
	for (set<player, compare2>::iterator it = s.begin(); it != s.end();it ++){
		cout << "Name:" << (*it).name << " Score:" << (*it).score << endl;
	}
}
//����
void test04(){
	set<int> s;
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);
	set<int>::iterator ret =  s.find(200);
	//����ҵ������ز������ݵ�λ�ã�����鲻������ end()
	if (ret == s.end()){
		cout << "û���ҵ�!" << endl;
	}
	else{
		cout << "�ҵ�:" << *ret << endl;
	}
	//lower_bound(keyElem) ����ҵ����أ�û���ҵ�����end()
	ret = s.lower_bound(20);
	if (ret == s.end()){
		cout << "�Ҳ���!" << endl;
	}
	else{
		cout << "�ҵ�:" << *ret << endl;
	}
	//upper_bound(keyElem) 
	ret = s.upper_bound(20);
	if (ret == s.end()){
		cout << "�Ҳ���!" << endl;
	}
	else{
		cout << "�ҵ�:" << *ret << endl;
	}
	//equal_range(keyElem);
	pair<set<int>::iterator,set<int>::iterator> ret2 = s.equal_range(20);
	if (ret2.first == s.end()){
		cout << "û���ҵ�!" << endl;
	}
	else{
		cout << "�ҵ�:" << *(ret2.first) << endl;
	}
	if (ret2.second == s.end()){
		cout << "û���ҵ�!" << endl;
	}
	else{
		cout << "�ҵ�:" <<*(ret2.second) << endl;
	}
}
int main(){
	//test02();
	//test03();
	test04();
	system("pause");
	return EXIT_SUCCESS;
}
