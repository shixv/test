#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Doctor{
	public:
		void TreatGanmao(){
			cout << "���Ƹ�ð��" << endl;
		}
		void  TreatJiaoqi(){
			cout << "���ƽ�����" << endl;
		}
		void  TreatZhichuang(){
			cout << "�����̴�!" << endl;
		}
};
//��������
class AbstractCommand{
	public:
		virtual void Excute() = 0;
};
//���Ƹ�ð������
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
//�����̴�������
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
