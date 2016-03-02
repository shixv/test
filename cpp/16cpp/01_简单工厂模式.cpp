#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//抽象水果
class AbstractFruit{
public:
	virtual void ShowName() = 0;
};
//苹果
class Apple : public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "我是苹果!" << endl;
	}
};
//香蕉
class Banana : public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "我是香蕉!" << endl;
	}
};
//鸭梨
class Pear : public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "我是鸭梨!" << endl;
	}
};
//新增：西瓜
class Watermellon : public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "我是西瓜!" << endl;
	}
};
//水果工厂
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
		else if (tag.compare("watermellon") == 0){  //新增水果，修改源代码，违背了开闭原则
			return new Watermellon;
		}
		else{
			return NULL;
		}
	}
};
//给工厂传入参数，工厂根据参数动态创建对象
void test01(){
	//创建苹果
	AbstractFruit* furit =  FruitFactory::CreateFruit("apple");
	furit->ShowName();
	//创建梨
	delete furit;
	furit = FruitFactory::CreateFruit("pear");
	furit->ShowName();
	//创建香蕉
	delete furit;
	furit = FruitFactory::CreateFruit("banana");
	furit->ShowName();
}
int main(){
	test01();
	system("pause");
	return EXIT_SUCCESS;
}