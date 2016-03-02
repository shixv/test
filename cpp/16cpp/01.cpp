#include <iostream>
using namespace std;
class AbstractFruit{
	public:
		virtual void showName()=0;
		virtual ~AbstractFruit(){}
};
class Apple:public AbstractFruit{
	public:
		virtual void showName(){
			cout<<"Iamapple"<<endl;
		}
		~Apple(){}
};
class Banana:public AbstractFruit{
	virtual void showName(){
		cout<<"iambanana"<<endl;
	}
	~Banana(){};
};
class Pear:public AbstractFruit{
	public:
		virtual void showName(){
			cout<<"Iam pear"<<endl;
		}
		~Pear(){}
};
class Watermellon:public AbstractFruit{
	virtual void showName(){
		cout<<"iam xigua"<<endl;
	}
	~Watermellon(){}
};
class FruitFactory{
	public:
		static AbstractFruit* CreateFruit(string tag){
			if(tag.compare("apple")==0){
				return new Apple;
			}
			else if(tag.compare("banana")==0){
				return new Banana;
			}
			else if(tag.compare("pear")==0){
				return new Pear;
			}
			else if(tag.compare("watermellon")==0){
				return new Watermellon;
			}
			else
			{
				return NULL;
			}
			return NULL;
		}
		~FruitFactory(){}
};
void test01(){
	AbstractFruit* fruit=FruitFactory::CreateFruit("apple");
	fruit->showName();
	delete fruit;
	fruit=FruitFactory::CreateFruit("pear");
	fruit->showName();
	delete fruit;
	fruit=FruitFactory::CreateFruit("banana");
	fruit->showName();
	delete fruit;
	fruit=FruitFactory::CreateFruit("watermellon");
	fruit->showName();
}
int main(void)
{
	test01();
	return 0;
}
