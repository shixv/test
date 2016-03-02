#include <iostream>
using namespace std;
class AbstractApple{
	public:
		virtual void ShowName()=0;
		virtual ~AbstractApple(){}
};
class ChinaApple:public AbstractApple{
	public:
		virtual void ShowName(){
			cout<<"Iamchinaapple"<<endl;
		}
		~ChinaApple(){}
};
class USApple:public AbstractApple{
	public:
		virtual void ShowName(){
			cout<<"Imausapple"<<endl;
		}
		USApple(){}
};
class JapApple:public AbstractApple{
	public:
		virtual void ShowName(){
			cout<<"iam Jpa apple"<<endl;
		}
		JapApple(){}
};
class AfricaApple:public AbstractApple{
	public:
		virtual void ShowName(){
			cout<<"iam Africa apple"<<endl;
		}
		~AfricaApple(){}
};
class AbstractBanana{
	public:
		virtual void ShowName()=0;
		virtual ~AbstractBanana(){}
};
class ChinaBanana:public AbstractBanana{
	public:
		virtual void ShowName(){
			cout<<"china baanan"<<endl;
		}
		~ChinaBanana(){}
};
class USBanana:public AbstractBanana{
	public:
		virtual void ShowName(){
			cout<<"UsBananan"<<endl;
		}
		~USBanana(){}
};
class JapBanana:public AbstractBanana{
	public:
		virtual void ShowName(){
			cout<<"Japbananan"<<endl;
		}
		~JapBanana(){}
};
class AfricaBanana:public AbstractBanana{
	public:
		virtual void ShowName(){
			cout<<"Africabananan"<<endl;
		}
		~AfricaBanana(){}
};
class AbstractPear{
	public:
		virtual void ShowName()=0;
		virtual ~AbstractPear(){}
};
class ChinaPear:public AbstractPear{
	public:
		virtual void ShowName(){
			cout<<"china pear"<<endl;
		}
		~ChinaPear(){}
};
class USPear:public AbstractPear{
	public:
		virtual void ShowName(){
			cout<<"us pear"<<endl;
		}
		~USPear(){}
};
class JapPear:public AbstractPear{
	public:
		virtual void ShowName(){
			cout<<"jap per"<<endl;
		}
		~JapPear(){}
};
class AfricaPear:public AbstractPear{
	public:
		virtual void ShowName(){
			cout<<"Africa per"<<endl;
		}
		~AfricaPear(){}
};
class AbstractFactory{
	public:
		virtual AbstractApple* CreateApple()=0;
		virtual AbstractBanana* CreateBanana()=0;
		virtual AbstractPear* CreatePear()=0;
		virtual ~AbstractFactory(){}
};
class ChinaFactory:public AbstractFactory{
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
		~ChinaFactory(){}
};
class USFactory:public AbstractFactory{
	public:
		virtual AbstractApple* CreateApple(){
			return new USApple;
		}
		virtual AbstractBanana* CreateBanana(){
			return new USBanana;
		}
		virtual AbstractPear* CreatePear(){
			return new USPear;
		}
		~USFactory(){}
};
class JapFactory:public AbstractFactory{
	public:
		virtual AbstractApple* CreateApple(){
			return new JapApple;
		}
		virtual AbstractBanana* CreateBanana(){
			return new JapBanana;
		}
		virtual AbstractPear* CreatePear(){
			return new JapPear;
		}
		~JapFactory(){}
};
class AfricaFactory:public AbstractFactory{
	public:
		virtual AbstractApple* CreateApple(){
			return new AfricaApple;
		}
		virtual AbstractBanana* CreateBanana(){
			return new AfricaBanana;
		}
		virtual AbstractPear* CreatePear(){
			return new AfricaPear;
		}
		~AfricaFactory(){}
};
void test01()
{
	AbstractApple* apple=NULL;
	AbstractBanana* banana=NULL;
	AbstractPear* pear=NULL;
	AbstractFactory* factory=NULL;
	factory=new ChinaFactory;
	apple=factory->CreateApple();
	banana=factory->CreateBanana();
	pear=factory->CreatePear();
	apple->ShowName();
	banana->ShowName();
	pear->ShowName();
	delete apple;
	delete banana;
	delete pear;
	cout<<"--------------"<<endl;	
	factory=new USFactory;
	apple=factory->CreateApple();
	banana=factory->CreateBanana();
	pear=factory->CreatePear();
	apple->ShowName();
	banana->ShowName();
	pear->ShowName();
	delete apple;
	delete banana;
	delete pear;
	cout<<"----------------"<<endl;
	factory=new JapFactory;
	apple=factory->CreateApple();
	banana=factory->CreateBanana();
	pear=factory->CreatePear();
	apple->ShowName();
	banana->ShowName();
	pear->ShowName();
	delete apple;
	delete banana;
	delete pear;
	cout<<"----------------"<<endl;
	factory=new AfricaFactory;
	apple=factory->CreateApple();
	banana=factory->CreateBanana();
	pear=factory->CreatePear();
	apple->ShowName();
	banana->ShowName();
	pear->ShowName();
	delete apple;
	delete banana;
	delete pear;
}
int main(void)
{
	test01();
	return 0;
}
