#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
using namespace std;
//map初始化
void test01(){
	//map容器需要制定key和value的类型
	map<int, int> m; //默认构造
	map<int, int> m2(m);//拷贝构造
}
//map容器插入
void test02(){
	map<int, int> m; //创建空的map容器
	//第一种方式
	m.insert(pair<int,int>(10,20));
	//第二种方式
	m.insert(make_pair(10,30));
	//第三种
	m.insert(map<int,int>::value_type(10,40));
	//打印
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it ++){
		cout << (*it).first << " " << (*it).second << endl;
	}
	//第四种 数组方式  当key存在，就会修改这个key对应的实值
	m[10] = 50;
	//打印
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++){
		cout << (*it).first << " " << (*it).second << endl;
	}
	cout << "--------------------" << endl;
	cout << " m[100]:" << m[100] << endl;
	//如果访问一个不存的key，那么会输出默认值，并且将这条数据插入到map中
	//打印
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++){
		cout << (*it).first << " " << (*it).second << endl;
	}
}
//仿函数
class compare{
	public:
		bool operator()(int key1,int key2){
			return key1 > key2;
		}
};
//map删除操作
void test03(){
	map<int, int, compare> m;
	m.insert(make_pair(2,100));
	m.insert(make_pair(1, 200));
	m.insert(make_pair(5, 300));
	m.insert(make_pair(7, 400));
	//遍历
	for (map<int, int, compare>::iterator it = m.begin(); it != m.end(); it++){
		cout << it->first << " " << it->second << endl;
	}
	//删除
	m.erase(2);
	cout << "----------" << endl;
	//遍历
	for (map<int, int, compare>::iterator it = m.begin(); it != m.end(); it++){
		cout << it->first << " " << it->second << endl;
	}
}
//查找
void test04(){
	map<int, int> m;
	m.insert(make_pair(2, 100));
	m.insert(make_pair(1, 200));
	m.insert(make_pair(5, 300));
	m.insert(make_pair(7, 400));
	//find
	map<int, int>::iterator ret =  m.find(2);
	if (ret == m.end()){
		cout << "没有找到!" << endl;
	}
	else{
		cout << "找到:" << (*ret).first << ":" << (*ret).second << endl;
	}
	//lower_bound(keyElem);
	ret = m.lower_bound(2);
	if (ret == m.end()){
		cout << "没有找到!" << endl;
	}
	else{
		cout << "找到:" << (*ret).first << ":" << (*ret).second << endl;
	}
	//upper_bound(keyElem);
	ret = m.upper_bound(2);
	if (ret == m.end()){
		cout << "没有找到!" << endl;
	}
	else{
		cout << "找到:" << (*ret).first << ":" << (*ret).second << endl;
	}
	//equal_range(keyElem)
	pair<map<int, int>::iterator, map<int, int>::iterator> ret2 = m.equal_range(2);
	if (ret2.first == m.end()){
		cout << "没有找到!" << endl;
	}
	else{
		cout << (*(ret2.first)).first << ":" << (*(ret2.first)).second << endl;
	}
	if (ret2.second == m.end()){
		cout << "没有找到!" << endl;
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
