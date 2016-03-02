#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//��Ϻͼ̳У�����ʹ�����
class AbstractCar{
	public:
		virtual void run() = 0;
};
//����
class BMWCar : public AbstractCar{
	public:
		virtual void run(){
			cout << "��������..." << endl;
		}
};
//����
class DassCar : public AbstractCar{
	public:
		virtual void run(){
			cout << "���ڳ�����..." << endl;
		}
};
//�˿��ű���ȥ�ϰ�
class Person : public BMWCar{
	public:
		void GoWork(){
			run();
		}
};
//�ϳɸ��� �̳к��������ʹ�����
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
	//������
	person->setCar(car);
	person->GoWork();
	delete car;
	//������
	car = new DassCar;
	person->setCar(car);
	person->GoWork();
}
int main(){
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
