#include <iostream>
#include <list>
using namespace std;
class PersonA{
	public:
		void TreatGanmao(){
			cout<<"zhiliaoganmao"<<endl;
		}
};
class PersonB{
	public:
		void TreatZhichuang(){
			cout<<"zhiliaozhichuan"<<endl;
		}
};
class PersonC{
	public:
		void TreatJiaoqi(){\
			cout<<"zhiliaojiaoqi"<<endl;
		}
};
class Patient{
	public:
		virtual void treat()=0;
};
class AdapterPersonA:public Patient{
	public:
		AdapterPersonA(){
			person=new PersonA;
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
class AdapterPersonB:public Patient{
	public:
		AdapterPersonB(){
			person=new PersonB;
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
class AdapterPersonC:public Patient{
	public:
		AdapterPersonC(){
			person=new PersonC;
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
class Doctor{
	public:
		void addPatient(Patient* patient){
			mList.push_back(patient);
		}
		void startTreat(){
			for(auto& i:mList)
				i->treat();
		}
	public:
		list<Patient*> mList;
};
void test01(){
	Patient* persona=new AdapterPersonA;
	Patient* personb=new AdapterPersonB;
	Patient* personc=new AdapterPersonC;
	Doctor* doctor=new Doctor;
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
	return 0;
}
