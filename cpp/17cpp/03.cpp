#include <iostream>
using namespace std;
class DrinkTemplate{
	public:
		virtual void BoilWater()=0;
		virtual void Chongpao()=0;
		virtual void PourInCup()=0;
		virtual void AddSomething()=0;
		void MakeDrink(){
			BoilWater();
			Chongpao();
			PourInCup();
			AddSomething();
		}
};
class Coffee:public DrinkTemplate{
	public:
		virtual void BoilWater()
		{
			cout<<"zhukaishui"<<endl;
		}
		virtual void Chongpao(){
			cout<<"chongpaokafei"<<endl;
		}
		virtual void PourInCup(){
			cout<<"daorubeizhong"<<endl;
		}
		virtual void AddSomething(){
			cout<<"jiaodianniunai"<<endl;
		}
};
class Tea:public DrinkTemplate{
	public:
		virtual void BoilWater()
		{
			cout<<"zhukaishui"<<endl;
		}
		virtual void Chongpao(){
			cout<<"chongpaokafei"<<endl;
		}
		virtual void PourInCup(){
			cout<<"daorubeizhong"<<endl;
		}
		virtual void AddSomething(){
			cout<<"jiaodianniunai"<<endl;
		}
};
void test01(){
	Coffee coffee;
	coffee.MakeDrink();
	Tea tea;
	tea.MakeDrink();
}
int main(void)
{
	test01();
	return 0;
}
