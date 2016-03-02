#include <iostream>
#include <string>
using namespace std;


class AbstractHero{
	public:
		virtual void status()=0;
};
class Zhangfei:public AbstractHero{
	public:
		virtual void status(){
			cout<<"gongjili: "<<10000<<endl;
			cout<<"fangyili: "<<10000<<endl;
			cout<<"xueliang: "<<5000<<endl;
			cout<<"zhili: "<<50<<endl;
			cout<<"sudu: "<<300<<endl;
		}
};
class Equipment:public AbstractHero{
	public:
		Equipment(AbstractHero* hero){
			this->hero=hero;
	}
		virtual void status(){}
	public:
		AbstractHero* hero;
};
class Zhangbashemao:public Equipment{
	public:
		void addStatus(){
			cout<<"xueling"+300<<endl;
			cout<<"gongjili"+10000<<endl;
		}
		virtual void status(AbstractHero* hero):Equipment(hero){
			hero->status();
		}
};

class Bailongma:public Equipment{
	public:
		Bailongma(AbstractHero* hero):Equipment(hero){}
		void addStatus(){
			cout<<"sudu+"<<500<<endl;
			cout<<"zhuangbeifujiashuxing:"<<"ninenggei"<<endl;
		}
};
void test01(){
	AbstractHero* zhangfei=new Zhangfei;
	zhangfei->status();
	cout<<"----------------"<<endl;
	AbstractHero* zhangbashemaozhangfei=new Zhangbashemao(zhangfei);
	zhangbashemaozhangfei->status();
	cout<<"-----------------"<<endl;
	AbstractHero* bailongmazhangzhangfei=new Bailongma(zhangbashemaozhangfei);
	bailongmazhangzhangfei->status();

	delete bailongmazhangzhangfei;
	delete zhangfei;
	delete zhangbashemaozhangfei;
}
int main(void)
{

	test01();
	return 0;
}
