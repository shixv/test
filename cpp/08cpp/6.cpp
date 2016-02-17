#include <iostream>
using namespace std;
//有一个大哥的虚线， 大哥的抽象类
class BigBrother
{
public:
	//大哥要会打人，  拥有一个打人的接口.
	virtual void fightPeople() = 0;
};
//江湖上 梦想成为大哥的人
//具体的实现类
class EastNeverLose :public BigBrother
{
public:
	virtual void fightPeople()  {
		cout << "使用葵花宝典 打人" << endl;
	}
	void Zigong()
	{
	}
};
//具体的实现类
class DuanYu :public BigBrother
{
public:
	virtual void fightPeople()  {
		cout << "使用六脉神剑 打人" << endl;
	}
};
//Boss
int main(void)
{
	//boss 只需要有一个人 顶替大哥的职位
	BigBrother *bro = new EastNeverLose;
	//大哥 你给我去打人
	bro->fightPeople();
	delete bro;
	return 0;
}
