#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
using namespace std;
//map��ʼ��
void test01(){
	//map������Ҫ�ƶ�key��value������
	map<int, int> m; //Ĭ�Ϲ���
	map<int, int> m2(m);//��������
}
//map��������
void test02(){
	map<int, int> m; //�����յ�map����
	//��һ�ַ�ʽ
	m.insert(pair<int,int>(10,20));
	//�ڶ��ַ�ʽ
	m.insert(make_pair(10,30));
	//������
	m.insert(map<int,int>::value_type(10,40));
	//��ӡ
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it ++){
		cout << (*it).first << " " << (*it).second << endl;
	}
	//������ ���鷽ʽ  ��key���ڣ��ͻ��޸����key��Ӧ��ʵֵ
	m[10] = 50;
	//��ӡ
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++){
		cout << (*it).first << " " << (*it).second << endl;
	}
	cout << "--------------------" << endl;
	cout << " m[100]:" << m[100] << endl;
	//�������һ�������key����ô�����Ĭ��ֵ�����ҽ��������ݲ��뵽map��
	//��ӡ
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++){
		cout << (*it).first << " " << (*it).second << endl;
	}
}
//�º���
class compare{
	public:
		bool operator()(int key1,int key2){
			return key1 > key2;
		}
};
//mapɾ������
void test03(){
	map<int, int, compare> m;
	m.insert(make_pair(2,100));
	m.insert(make_pair(1, 200));
	m.insert(make_pair(5, 300));
	m.insert(make_pair(7, 400));
	//����
	for (map<int, int, compare>::iterator it = m.begin(); it != m.end(); it++){
		cout << it->first << " " << it->second << endl;
	}
	//ɾ��
	m.erase(2);
	cout << "----------" << endl;
	//����
	for (map<int, int, compare>::iterator it = m.begin(); it != m.end(); it++){
		cout << it->first << " " << it->second << endl;
	}
}
//����
void test04(){
	map<int, int> m;
	m.insert(make_pair(2, 100));
	m.insert(make_pair(1, 200));
	m.insert(make_pair(5, 300));
	m.insert(make_pair(7, 400));
	//find
	map<int, int>::iterator ret =  m.find(2);
	if (ret == m.end()){
		cout << "û���ҵ�!" << endl;
	}
	else{
		cout << "�ҵ�:" << (*ret).first << ":" << (*ret).second << endl;
	}
	//lower_bound(keyElem);
	ret = m.lower_bound(2);
	if (ret == m.end()){
		cout << "û���ҵ�!" << endl;
	}
	else{
		cout << "�ҵ�:" << (*ret).first << ":" << (*ret).second << endl;
	}
	//upper_bound(keyElem);
	ret = m.upper_bound(2);
	if (ret == m.end()){
		cout << "û���ҵ�!" << endl;
	}
	else{
		cout << "�ҵ�:" << (*ret).first << ":" << (*ret).second << endl;
	}
	//equal_range(keyElem)
	pair<map<int, int>::iterator, map<int, int>::iterator> ret2 = m.equal_range(2);
	if (ret2.first == m.end()){
		cout << "û���ҵ�!" << endl;
	}
	else{
		cout << (*(ret2.first)).first << ":" << (*(ret2.first)).second << endl;
	}
	if (ret2.second == m.end()){
		cout << "û���ҵ�!" << endl;
	}
	else{
		cout << (*(ret2.second)).first << ":" << (*(ret2.second)).second << endl;
	}
}
int main(){
	test02();
	test03();
	test04();
	system("pause");
	return EXIT_SUCCESS;
}
