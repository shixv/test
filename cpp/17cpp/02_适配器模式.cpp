#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
using namespace std;
class PersonA{
public:
	void TreatGanmao(){
		cout << "治疗感冒！" << endl;
	}
};
class PersonB{
public:
	void TreatZhichuang(){
		cout << "治疗痔疮！" << endl;
	}
};
class PersonC{
public:
	void TreatJiaoqi(){
		cout << "治疗脚气！" << endl;
	}
};
//目标接口
class Patient{
public:
	virtual void treat() = 0;
};
//personA适配器
class AdapterPersonA : public Patient{
public:
	AdapterPersonA(){
		person = new PersonA;
	}
	~AdapterPersonA(){
		delete person;
	}
	virtual void treat(){
		person->TreatGanmao();
	}
public:
	PersonA* person;
};
//PersonB
class AdapterPersonB : public Patient{
public:
	AdapterPersonB(){
		person = new PersonB;
	}
	~AdapterPersonB(){
		delete person;
	}
	virtual void treat(){
		person->TreatZhichuang();
	}
public:
	PersonB* person;
};
//适配
class AdapterPersonC : public Patient{
public:
	AdapterPersonC(){
		person = new PersonC;
	}
	~AdapterPersonC(){
		delete person;
	}
	virtual void treat(){
		person->TreatJiaoqi();
	}
public:
	PersonC* person;
};
//医生治病
class Doctor{
public:
	void addPatient(Patient* patient){
		mList.push_back(patient);
	}
	void startTreat(){
		for (list<Patient*>::iterator it = mList.begin(); it != mList.end(); it ++){
			(*it)->treat();
		}
	}
public:
	list<Patient*> mList;
};
void test01(){
	Patient* persona = new AdapterPersonA;
	Patient* personb = new AdapterPersonB;
	Patient* personc = new AdapterPersonC;
	//创建医生
	Doctor* doctor = new Doctor;
	doctor->addPatient(persona);
	doctor->addPatient(personb);
	doctor->addPatient(personc);
	doctor->startTreat();
	delete doctor;
	delete personc;
	delete personb;
	delete persona;
}
int main(){
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
