#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Doctor{
	public:
		void TreatGanmao(){
			cout << "ÖÎÁÆ¸ÐÃ°£¡" << endl;
		}
		void  TreatJiaoqi(){
			cout << "ÖÎÁÆ½ÅÆø£¡" << endl;
		}
		void  TreatZhichuang(){
			cout << "ÖÎÁÆÖÌ´¯!" << endl;
		}
};
//³éÏóÃüÁî
class AbstractCommand{
	public:
		virtual void Excute() = 0;
};
//ÖÎÁÆ¸ÐÃ°µÄÃüÁî
class TreatGanmaoCommand : public AbstractCommand{
	public:
		TreatGanmaoCommand(Doctor* doctor){
			this->doctor = doctor;
		}
		virtual void Excute(){
			this->doctor->TreatGanmao();
		}
	public:
		Doctor* doctor;
};
//ÖÎÁÆÖÌ´¯µÄÃüÁî
class TreatZhchuangCommand : public AbstractCommand{
	public:
		TreatZhchuangCommand(Doctor* doctor){
			this->doctor = doctor;
		}
		virtual void Excute(){
			this->doctor->TreatZhichuang();
		}
	public:
		Doctor* doctor;
};
void test02(){
	Doctor doctor;
	AbstractCommand* ganmao = new TreatGanmaoCommand(&doctor);
	ganmao->Excute();
}
void test01(){
	Doctor doctor;
	doctor.TreatGanmao();
	doctor.TreatJiaoqi();
	doctor.TreatZhichuang();
}
int main(){
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
