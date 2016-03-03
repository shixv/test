#include <iostream>
using namespace std;
class AbstractWeapon{
	public:
		virtual void UseWeapon()=0;
};
class CaiDao:public AbstractWeapon{
	public:
		virtual void UseWeapon(){
			cout<<"caidao"<<endl;
		}
};
class ZhiJiaDao :public AbstractWeapon{
	public:
		virtual void UseWeapon(){
			cout<<"zhijiadao"<<endl;
		}
};
class People{
	public:
		People(){
			weapon=NULL;
		}
		void setWeapon(AbstractWeapon* weapon){
			this->weapon=weapon;
		}
		void UseWeapon(){
			this->weapon->UseWeapon();
		}
	public:
		AbstractWeapon* weapon;
};
void test01(){
	AbstractWeapon* weapon=new CaiDao;
	People* people=new People;
	people->setWeapon(weapon);
	people->UseWeapon();
	delete weapon;
	weapon=new ZhiJiaDao;
	people->setWeapon(weapon);
	people->UseWeapon();
	delete weapon;
	delete people;
}
int main(void)
{
	test01();
	return 0;
}
