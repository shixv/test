#include <iostream>
using namespace std;
class AbstractCar{
	public:
		virtual ~AbstractCar(){}
		virtual void run()=0;
};
class BMWCar:public AbstractCar{
	public:
		virtual ~BMWCar(){}
		virtual void run(){
			cout<<"baoma"<<endl;
		}
};
class DassCar:public AbstractCar{
	public:
		virtual ~DassCar(){}
		virtual void run(){
			cout<<"dazhong"<<endl;
		}
};
/*
class Person:public BMWCar{
	public:
		void goWork(){
			run();
		}
};
*/
class PersonTall{
	public:
		void setCar(AbstractCar* car){
			this->pCar=car;
		}
		void goWork(){
			pCar->run();
		}
	public:
		AbstractCar* pCar;
};
void test01(){
	AbstractCar* car=NULL;
	car=new BMWCar;
	PersonTall* person=new PersonTall;
	person->setCar(car);
	person->goWork();
	delete car;
	car=new DassCar;
	person->setCar(car);
	person->goWork();
}
int main(void)
{
	test01();
	return 0;
}
