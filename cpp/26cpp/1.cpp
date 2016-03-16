#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


class A{
public:
	void PrintA(){
		cout << "A" << endl;
	}
};

class B : public A{
public:

};

//继承是为了复用之前的人(死的，活的)写的代码


class Animal{
public:
	virtual void Hou(){
		cout << "吼" << endl;
	}
};

class Dog : public Animal{
public:
	virtual void Hou(){
		cout << "汪汪叫..." << endl;
	}
};
//9:12
void doBussiness(Animal* animal){
	animal->Hou();
}

//9:13

//猫
class Cat :public Animal{
public:
	virtual void Hou(){
		cout << "喵喵叫..." << endl;
	}
};

//多态成立的三个条件
//1.继承
//2.虚函数
//3 父类指针指向子类对象

int main01(){

	Animal father;
	Dog dog;
	Cat cat;
	doBussiness(&father);
	doBussiness(&dog);
	doBussiness(&cat);

	system("pause");
	return EXIT_SUCCESS;
}