#include <iostream>
using namespace std;
class Doctor{
	public:
		void TreatGanmao(){
			cout<<"zhiliaoganmao"<<endl;
		}
		void TreatJiaoqi(){
			cout<<"zhiliaiojiaoqi"<<endl;
		}
		void TreatZhichuang(){
			cout<<"zhiliaozhichuang"<<endl;
		}
};
class AbstractCommand{
	public:
		virtual void Excute()=0;
};
class TreatGanmaoCommand:public AbstractCommand{
	public:
		TreatGanmaoCommand(Doctor* doctor){
			this->doctor=doctor;
		}
		virtual void Excute(){
			this->doctor->TreatGanmao();
		}
	public:
		Doctor* doctor;
};
class TreatZhichuangCommand:public AbstractCommand{
	public:
		TreatZhichuangCommand(Doctor* doctor){
			this->doctor=doctor;
		}
		virtual void Excute(){
			this->doctor->TreatZhichuang();
		}
	public:
		Doctor* doctor;
};
void test01(){
	Doctor doctor;
	doctor.TreatGanmao();
	doctor.TreatZhichuang();
	doctor.TreatJiaoqi();
}
void test02(){
	Doctor doctor;
	AbstractCommand *ganmao=new TreatGanmaoCommand(&doctor);
	ganmao->Excute();
}
int main(void)
{
	test01();
	test02();
	return 0;
}
