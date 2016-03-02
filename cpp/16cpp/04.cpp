#include <iostream>
using namespace std;
class Singleton_lazy{
	public:
		static Singleton_lazy* getInstance(){
			if(instance==NULL){
				instance=new Singleton_lazy;
			}
			return instance;
		}
	private:
		Singleton_lazy(){}
		static Singleton_lazy* instance;
};
Singleton_lazy* Singleton_lazy::instance=NULL;
class Singleton_hungry{
	public:
		static Singleton_hungry* getInstance(){
			return instance;
		}
	private:
		Singleton_hungry(){}
		static Singleton_hungry* instance;
};
Singleton_hungry* Singleton_hungry::instance=new Singleton_hungry;
void test01(){
	Singleton_lazy* lazy1=Singleton_lazy::getInstance();
	Singleton_lazy* lazy2=Singleton_lazy::getInstance();
	Singleton_hungry* hungry1=Singleton_hungry::getInstance();
	Singleton_hungry* hungry2=Singleton_hungry::getInstance();
	if(lazy1==lazy2)
		cout<<"xiangtong"<<endl;
	else
		cout<<"buxinagtong"<<endl;
	if(hungry1==hungry2)
		cout<<"xiangtong"<<endl;
	else
		cout<<"buxinagtong"<<endl;
}
int main(void)
{
	test01();
	return 0;
}
