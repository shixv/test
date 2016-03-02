#include <iostream>
using namespace std;
class AbstractFruit{
	public:
		virtual void ShowName()=0;
		virtual ~AbstractFruit(){}
};
class Apple:public AbstractFruit{
	virtual void ShowName(){
		cout<<"woshiapple"<<endl;
	}
	virtual ~Apple(){}
};
class Banana:public AbstractFruit{
	virtual void ShowName(){
		cout<<"woshibanana"<<endl;
	}
	virtual ~Banana(){}
};
class Pear:public AbstractFruit{
	virtual void ShowName(){
		cout<<"iampear"<<endl;
	}
	~Pear(){}
};
class AbstractFactory{
	public:
		virtual AbstractFruit* CreateFruit()=0;
		virtual ~AbstractFactory(){}
};
class AppleFactory:public AbstractFactory{
	public:
		virtual Apple* CreateFruit(){
			return new Apple;
		}
		virtual ~AppleFactory(){}
};
class BananaFactory:public AbstractFactory{
	public:
		virtual Banana* CreateFruit(){
				return new Banana;
		}
		virtual ~BananaFactory(){}
};
class PearFactory:public AbstractFactory{
	public:
		virtual Pear* CreateFruit(){
				return new Pear;
		}
		virtual ~PearFactory(){}
};
void test01(void){
	AbstractFactory *factory=NULL;
	AbstractFruit *fruit=NULL;
	factory=new AppleFactory;
	fruit=factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;
	factory=new BananaFactory;
	fruit=factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;
	factory=new PearFactory;
	fruit=factory->CreateFruit();
	fruit->ShowName();
}
int main(void)
{
	test01();
	return 0;
}
