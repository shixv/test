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

//�̳���Ϊ�˸���֮ǰ����(���ģ����)д�Ĵ���


class Animal{
public:
	virtual void Hou(){
		cout << "��" << endl;
	}
};

class Dog : public Animal{
public:
	virtual void Hou(){
		cout << "������..." << endl;
	}
};
//9:12
void doBussiness(Animal* animal){
	animal->Hou();
}

//9:13

//è
class Cat :public Animal{
public:
	virtual void Hou(){
		cout << "������..." << endl;
	}
};

//��̬��������������
//1.�̳�
//2.�麯��
//3 ����ָ��ָ���������

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