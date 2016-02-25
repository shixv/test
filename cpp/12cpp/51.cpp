#include <iostream>
#include <deque>
using namespace std;
void test01(){
	deque<int> d1;
	deque<int> d2(10,5);
	deque<int> d3(d2.begin(),d2.end());
	deque<int> d4(d3);
	for(auto it = d4.begin();it!=d4.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
}
void test02(){
	deque<int> d(10,4);
	deque<int> d1;
	d1.assign(8,8);
	for(auto it=d.begin();it!=d.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	for(auto it=d1.begin();it!=d1.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	cout<<"swaped"<<endl;
	d.swap(d1);
	for(auto it=d.begin();it!=d.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	for(auto it=d1.begin();it!=d1.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
}
void test03(){
	deque<int> d(10,6);
	cout<<"size: "<<d.size()<<endl;
	if(d.empty()==true){
		cout<<"empty!"<<endl;
	}
	else{
		cout<<"not empty!"<<endl;
	}
	d.resize(5);
	cout<<"size: "<<d.size()<<endl;
}
void test04(){
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	for(auto it=d.begin();it!=d.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	for(auto it=d.begin();it!=d.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	d.pop_front();
	d.pop_back();
	for(auto it=d.begin();it!=d.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	cout<<"front: "<<d.front()<<endl;
	cout<<"back: "<<d.back()<<endl;
	d.insert(d.begin(),90);
	for(auto it=d.begin();it!=d.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
}
void test05(){
	deque<int> d;
	d.push_back(100);
	d.push_back(200);
	d.push_back(300);
	d.erase(d.begin(),d.end());
	cout<<"size: "<<d.size()<<endl;
}
int main(void){
	test01();
	test02();
	test03();
	test04();
	test05();
	return EXIT_SUCCESS;
}
