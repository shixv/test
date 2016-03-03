#include<iostream>
using namespace std;
class DrinkTemplate{
	public:
		virtual void BoilWater() = 0; //煮开水
		virtual void Chongpao() = 0; //冲泡
		virtual void PourInCup() = 0; //倒入杯中
		virtual void AddSomething() = 0; //加料
		void MakeDrink(){ //模板方法
			Chongpao();
			BoilWater();
			PourInCup();
			AddSomething();
		}
};
//咖啡
class Coffee : public DrinkTemplate{
	public:
		virtual void BoilWater(){
			cout << "煮开水..." << endl;
		}
		virtual void Chongpao(){
			cout << "冲泡咖啡..." << endl;
		}
		virtual void PourInCup(){
			cout << "倒入杯中..." << endl;
		}
		virtual void AddSomething(){
			cout << "加点牛奶..." << endl;
		}
};
//茶水
class Tea : public DrinkTemplate{
	public:
		virtual void BoilWater(){
			cout << "煮开水..." << endl;
		}
		virtual void Chongpao(){
			cout << "冲泡茶叶..." << endl;
		}
		virtual void PourInCup(){
			cout << "倒入杯中..." << endl;
		}
		virtual void AddSomething(){
			cout << "加点糖..." << endl;
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
