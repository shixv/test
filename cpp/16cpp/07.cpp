#include <iostream>
using namespace std;

class BeautyGirl{
	public:
		virtual void MakeEyesWithMan()=0;
		virtual void HappyWithMan()=0;
};

class PanJinLian:public BeautyGirl{
	public:
		virtual void MakeEyesWithMan(){
			cout<<"panjinlianbutingdezhayanjing...."<<endl;
		}
		virtual void HappyWithMan(){
			cout<<"yuguanrenhuaqianyuexia"<<endl;
		}
};
class Wangpo:public BeautyGirl{
	public:
		Wangpo(BeautyGirl* girl){
			this->girl=girl;
		}
		virtual void MakeEyesWithMan(){
			girl->MakeEyesWithMan();
		}
		virtual void HappyWithMan(){
			girl->HappyWithMan();
		}
	public:
		BeautyGirl* girl;
};
int main(void)
{
	Wangpo* wangpo=new Wangpo(new PanJinLian);
	wangpo->MakeEyesWithMan();
	wangpo->HappyWithMan();
	return 0;
}
