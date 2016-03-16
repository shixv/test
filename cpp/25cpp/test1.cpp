#include<iostream>
using namespace std;
#include"LinkList.hpp"
void MyPrint(int data){
	cout << "data:" << data << endl;
}
int main(){
	LinkList<int> list;
	list.Insert_Begin(10);
	list.Insert_Begin(20);
	list.PrintList(MyPrint);
	system("pause");
	return 0;
}
