#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//抽象苹果
class AbstractApple{
public:
	virtual void ShowName() = 0;
};
//中国苹果
class ChinaApple : public AbstractApple{
public:
	virtual void ShowName(){
		cout << "我是中国苹果！" << endl;
	}
};
//美国苹果
class USAApple : public AbstractApple{
public:
	virtual void ShowName(){
		cout << "我是美国苹果！" << endl;
	}
};
//日本苹果
class JapanApple : public AbstractApple{
public:
	virtual void ShowName(){
		cout << "我是日本小苹果！" << endl;
	}
};
//新增:非洲苹果
class AfricanApple : public AbstractApple{
public:
	virtual void ShowName(){
		cout << "我是非洲黑苹果！" << endl;
	}
};
//抽象香蕉
class AbstractBanana{
public:
	virtual void ShowName() = 0;
};
//中国香蕉
class ChinaBanana :public AbstractBanana{
public:
	virtual void ShowName(){
		cout << "我是中国大香蕉！" << endl;
	}
};
//美国香蕉
class USABanana : public AbstractBanana{
public:
	virtual void ShowName(){
		cout << "我是美国香蕉！" << endl;
	}
};
//日本香蕉
class JapanBanana : public AbstractBanana{
public:
	virtual void ShowName(){
		cout << "我是日本小香蕉！" << endl;
	}
};
//新增:非洲香蕉
class AfricanBanana : public AbstractBanana{
public:
	virtual void ShowName(){
		cout << "我是非洲黑香蕉！" << endl;
	}
};
//抽象鸭梨
class AbstractPear{
public:
	virtual void ShowName() = 0;
};
//中国鸭梨
class ChinaPear :public AbstractPear{
public:
	virtual void ShowName(){
		cout << "我是中国大鸭梨！" << endl;
	}
};
//美国鸭梨
class USAPear :public AbstractPear{
public:
	virtual void ShowName(){
		cout << "我是美国鸭梨！" << endl;
	}
};
//日本鸭梨
class JapanPear :public AbstractPear{
public:
	virtual void ShowName(){
		cout << "我是日本小鸭梨！" << endl;
	}
};
//非洲鸭梨
class AfricanPear : public AbstractPear{
public:
	virtual void ShowName(){
		cout << "我是非洲黑鸭梨！" << endl;
	}
};
//抽象工厂
class AbstractFactory{
public:
	virtual AbstractApple* CreateApple() = 0;
	virtual AbstractBanana* CreateBanana() = 0;
	virtual AbstractPear* CreatePear() = 0;
	//新增葡萄  
};
//中国工厂
class ChinaFactory : public AbstractFactory{
public:
	virtual AbstractApple* CreateApple(){
		return new ChinaApple;
	}
	virtual AbstractBanana* CreateBanana(){
		return new ChinaBanana;
	}
	virtual AbstractPear* CreatePear(){
		return new ChinaPear;
	}
};
//美国工厂
class USAFactory : public AbstractFactory{
public:
	virtual AbstractApple* CreateApple(){
		return new USAApple;
	}
	virtual AbstractBanana* CreateBanana(){
		return new USABanana;
	}
	virtual AbstractPear* CreatePear(){
		return new USAPear;
	}
};
//日本小工厂
class JapanFactory : public AbstractFactory{
public:
	virtual AbstractApple* CreateApple(){
		return new JapanApple;
	}
	virtual AbstractBanana* CreateBanana(){
		return new JapanBanana;
	}
	virtual AbstractPear* CreatePear(){
		return new JapanPear;
	}
};
//非洲黑工厂
class AfricanFactory : public AbstractFactory{
public:
	virtual AbstractApple* CreateApple(){
		return new AfricanApple;
	}
	virtual AbstractBanana* CreateBanana(){
		return new AfricanBanana;
	}
	virtual AbstractPear* CreatePear(){
		return new AfricanPear;
	}
};
//如果你增加一个产品族，符合开闭原则
//如果增加一个产品等级结构，不符合开闭原则
void test01(){
	AbstractApple* apple = NULL;
	AbstractBanana* banana = NULL;
	AbstractPear* pear = NULL;
	AbstractFactory* factory = NULL;
	//想吃中国苹果 香蕉 梨
	factory = new ChinaFactory; 
	apple = factory->CreateApple();
	banana = factory->CreateBanana();
	pear = factory->CreatePear();
	apple->ShowName();
	banana->ShowName();
	pear->ShowName();
	delete pear;
	delete banana;
	delete apple;
	delete factory;
	//想吃美国的苹果 香蕉 梨
	factory = new USAFactory;
	apple = factory->CreateApple();
	banana = factory->CreateBanana();
	pear = factory->CreatePear();
	apple->ShowName();
	banana->ShowName();
	pear->ShowName();
	delete pear;
	delete banana;
	delete apple;
	delete factory;
	//想吃日本
	factory = new JapanFactory;
	apple = factory->CreateApple();
	banana = factory->CreateBanana();
	pear = factory->CreatePear();
	apple->ShowName();
	banana->ShowName();
	pear->ShowName();
	delete pear;
	delete banana;
	delete apple;
	delete factory;
}
int main(){
	test01();
	system("pause");
	return EXIT_SUCCESS;
}