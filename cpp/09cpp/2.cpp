#include <iostream>
using namespace std;
class Employee
{
	public:
		Employee();
		virtual ~Employee();
		virtual void getPay()=0;
		virotual void upLevel()=0;
		void virtual displayStatus();
	private:
		string name;
		int id;
		double salary;
		int level;
		static int startNum;
};
startNum=1000;
Employee::Employee()
{
	level=1;
	id=startNum++;
	salary=0.0;
	cout<<"Employee().."<<endl;
}
Employee::~Employee()
{
	cout<<"~Employee().."<<endl;
}
class Technician:public Employee
{
	public:
		Technician();
		~Technician();
		virtual void getPay();
		virtual void upLevel();
	private:
		int workHour;
		double perHourMoney;
};
Technician::Technician()
{
	cout<<"please name"<<endl;
	cin>>this->name;
	perHourMoney=100;
}
Technician:~Technician()
{
	cout<<"~Technician().."<<endl;
}
void Technician::getPay()
{
	cout<<"hour"endl;
	cin>>workHour;
	this->salary=perHourMoney*workHour;
}
void Technician::upLevel(int addLevel)
{
	this->level+=addLevel;
}
void Technician::displayStatus()
{
	cout<<"name"<<this->name<<endl;
	}
int main(void)
{
	Employee *em1=new Technician;
	em1->getPay();
	em1->upLevel();
	em1->displayStatus();
	return 0;
}

