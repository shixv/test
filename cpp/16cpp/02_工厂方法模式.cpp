#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//����ˮ��
class AbstractFruit{
public:
	virtual void ShowName() = 0;
};
//ƻ��
class Apple : public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "����ƻ��!" << endl;;
	}
};
//�㽶
class Banana : public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "�����㽶!" << endl;;
	}
};
//Ѽ��
class Pear : public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "����Ѽ��!" << endl;;
	}
};
//���󹤳�
class AbstractFactory{
public:
	virtual AbstractFruit* CreateFruit() = 0;
};
//ƻ������
class AppleFactory : public AbstractFactory{
public:
	virtual AbstractFruit* CreateFruit() {
		return new Apple;
	}
};
//�㽶����
class BananaFactory : public AbstractFactory{
public:
	virtual AbstractFruit* CreateFruit() {
		return new Banana;
	}
};
//Ѽ�湤��
class PearFactory : public AbstractFactory{
public:
	virtual AbstractFruit* CreateFruit() {
		return new Pear;
	}
};
void test01(){
	AbstractFruit* fruit = NULL;
	AbstractFactory* factory = NULL;
	//�����ƻ��
	factory = new AppleFactory;
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;
	//������㽶
	factory = new BananaFactory;
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;
	//�����Ѽ��
	factory = new PearFactory;
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;
}
int main(){
	test01();
	system("pause");
	return EXIT_SUCCESS;
}