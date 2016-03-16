#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class teacher01{
public:
	void PrintTeacher(){
		cout << "teacher01" << endl;
	}
};

class teacher02{
public:
	virtual void PrintTeacher(){
		cout << "teacher01" << endl;
	}
	virtual void PrintTeacher01(){
		cout << "teacher02" << endl;
	}
};

typedef void(*Func)(void);

int main(){


	printf("teacher01 size: %d\n", sizeof(teacher01));
	printf("teacher02 size : %d\n", sizeof(teacher02));

	//虚函数调用
	teacher02 teacher;

	printf("虚函数表地址:%d\n", (int*)(&teacher));

	//Func testPrint = (Func)(*((int*)*((int*)(&teacher)) + 2));
	void(*testPrint)(void) = (void(*)(void))(*((int*