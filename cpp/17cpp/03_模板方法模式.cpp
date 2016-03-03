#include<iostream>
using namespace std;
class DrinkTemplate{
	public:
		virtual void BoilWater() = 0; //��ˮ
		virtual void Chongpao() = 0; //����
		virtual void PourInCup() = 0; //���뱭��
		virtual void AddSomething() = 0; //����
		void MakeDrink(){ //ģ�巽��
			Chongpao();
			BoilWater();
			PourInCup();
			AddSomething();
		}
};
//����
class Coffee : public DrinkTemplate{
	public:
		virtual void BoilWater(){
			cout << "��ˮ..." << endl;
		}
		virtual void Chongpao(){
			cout << "���ݿ���..." << endl;
		}
		virtual void PourInCup(){
			cout << "���뱭��..." << endl;
		}
		virtual void AddSomething(){
			cout << "�ӵ�ţ��..." << endl;
		}
};
//��ˮ
class Tea : public DrinkTemplate{
	public:
		virtual void BoilWater(){
			cout << "��ˮ..." << endl;
		}
		virtual void Chongpao(){
			cout << "���ݲ�Ҷ..." << endl;
		}
		virtual void PourInCup(){
			cout << "���뱭��..." << endl;
		}
		virtual void AddSomething(){
			cout << "�ӵ���..." << endl;
		}
};
void test01(){
	Coffee coffee;
	coffee.MakeDrink();
	cout << "------------" << endl;
	Tea tea;
	tea.MakeDrink();
}
int main(){
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
