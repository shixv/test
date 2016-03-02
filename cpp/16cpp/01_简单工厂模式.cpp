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
		cout << "����ƻ��!" << endl;
	}
};
//�㽶
class Banana : public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "�����㽶!" << endl;
	}
};
//Ѽ��
class Pear : public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "����Ѽ��!" << endl;
	}
};
//����������
class Watermellon : public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "��������!" << endl;
	}
};
//ˮ������
class FruitFactory{
public:
	static AbstractFruit* CreateFruit(string tag){
		if (tag.compare("apple") == 0){
			return new Apple;
		}
		else if (tag.compare("banana") == 0){
			return new Banana;
		}
		else if (tag.compare("pear") == 0){
			return new Pear;
		}
		else if (tag.compare("watermellon") == 0){  //����ˮ�����޸�Դ���룬Υ���˿���ԭ��
			return new Watermellon;
		}
		else{
			return NULL;
		}
	}
};
//����������������������ݲ�����̬��������
void test01(){
	//����ƻ��
	AbstractFruit* furit =  FruitFactory::CreateFruit("apple");
	furit->ShowName();
	//������
	delete furit;
	furit = FruitFactory::CreateFruit("pear");
	furit->ShowName();
	//�����㽶
	delete furit;
	furit = FruitFactory::CreateFruit("banana");
	furit->ShowName();
}
int main(){
	test01();
	system("pause");
	return EXIT_SUCCESS;
}