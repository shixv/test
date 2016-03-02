#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
using namespace std;
//抽象楼盘
class AbstractBuilding{
	public:
		virtual void sale() = 0;
	public:
		string quality;
};
//具体楼盘A 低档楼盘
class BuidingA : public AbstractBuilding{
	public:
		BuidingA(){
			quality = "低品质";
		}
		virtual void sale(){
			cout << "低档楼盘被售卖!" << endl;
		}
};
//具体楼盘B 中档楼盘
class BuidingB : public AbstractBuilding{
	public:
		BuidingB(){
			quality = "中品质";
		}
		virtual void sale(){
			cout << "中档楼盘被售卖!" << endl;
		}
};
//具体楼盘C 高档楼盘
class BuidingC : public AbstractBuilding{
	public:
		BuidingC(){
			quality = "高品质";
		}
		virtual void sale(){
			cout << "高档楼盘被售卖!" << endl;
		}
};
//中介
class Mediator{
	public:
		Mediator(){
			//初始化 将所有楼盘信息保存起来
			AbstractBuilding* buiding = NULL;
			buiding = new BuidingA;
			mList.push_back(buiding);
			buiding = new BuidingB;
			mList.push_back(buiding);
			buiding = new BuidingC;
			mList.push_back(buiding);
		}
		//提供对外接口
		AbstractBuilding* findBuiding(string quality){
			for (list<AbstractBuilding*>::iterator it = mList.begin(); it != mList.end(); it ++){
				if ((*it)->quality.compare(quality) == 0){
					return *it;
				}
			}
			return NULL;
		}
		~Mediator(){
			for (list<AbstractBuilding*>::iterator it = mList.begin(); it != mList.end(); it ++){
				if (*it != NULL){
					delete *it;
				}
			}
		}
	public:
		//需要容器保存楼盘信息
		list<AbstractBuilding*> mList;
};
//业务类 就是找到我想要的高品质楼盘
void doBussiness(){
	//创建中介
	Mediator* mediator = new Mediator;
	AbstractBuilding* buiding =  mediator->findBuiding("不高不低");
	if (buiding == NULL){
		cout << "没有满足条件的楼盘!" << endl;
		return;
	}
	buiding->sale();
}
int main(){
	doBussiness();
	system("pause");
	return EXIT_SUCCESS;
}
