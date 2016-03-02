#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//组合和继承，优先使用组合
class AbstractCar{
	public:
		virtual void run() = 0;
};
//宝马
class BMWCar : public AbstractCar{
	public:
		virtual void run(){
			cout << "宝马车启动..." << endl;
		}
};
//大众
class DassCar : public AbstractCar{
	public:
		virtual void run(){
			cout << "大众车启动..." << endl;
		}
};
//人开着宝马车去上班
class Person : public BMWCar{
	public:
		void GoWork(){
			run();
		}
};
//合成复用 继承和组合优先使用组合
class PersonTall{
	public:
		void setCar(AbstractCar* car){
			this->pCar = car;
		}
		void GoWork(){
			pCar->run();
		}
	public:
		AbstractCar* pCar;
};
void test01(){
	AbstractCar* car = NULL;
	car = new BMWCar;
	PersonTall* person = new PersonTall;
	//开宝马
	person->setCar(car);
	person->GoWork();
	delete car;
	//开大众
	car = new DassCar;
	person->setCar(car);
	person->GoWork();
}
int main(){
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
