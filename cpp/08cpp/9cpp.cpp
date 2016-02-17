#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//------ 抽象层 -------
//抽象的CPU类
class CPU
{
public:
	virtual void caculate() = 0;
};
//抽象的card
class Card
{
public:
	virtual void display() = 0;
};
//抽象的内存条
class Memory
{
public:
	virtual void storage() = 0;
};
//定义个电脑类
class Computer
{
public:
	Computer(CPU *cpu, Card *card, Memory *mem)
	{
		this->cpu = cpu;
		this->card = card;
		this->mem = mem;
	}
	//电脑工作的方法
	void work()
	{
		this->cpu->caculate(); //发生多态，调用的是子类的具体的方法
		this->card->display();
		this->mem->storage();
	}
	~Computer()
	{
		if (this->cpu != NULL) {
			delete this->cpu;
		}
		if (this->card != NULL) {
			delete this->card;
		}
		if (this->mem != NULL) {
			delete this->mem;
		}
	}
private:
	CPU *cpu;
	Card *card;
	Memory *mem;
};
//--------------------
//------ 实现层 -------
//Intel的CPU
class IntelCPU : public CPU
{
public:
	virtual void caculate()  {
		cout << "IntelCPU 开始工作了" << endl;
	}
};
class IntelCard :public Card
{
public:
	virtual void display()  {
		cout << "IntelCard 开始工作了" << endl;
	}
};
class IntelMem :public Memory
{
public:
	virtual void storage()  {
		cout << "IntelMem 开始工作了" << endl;
	}
};
//具体的King的内存条
class KingstonMem :public Memory
{
public:
	virtual void storage()  {
		cout << "KingstonMem 开始工作了" << endl;
	}
};
//具体的n卡
class NvidaCard :public Card
{
public:
	virtual void display() {
		cout << "NvidaCard 开始工作了" << endl;
	}
};
//--------------------
//------ 业务逻辑层----
int main(void)
{
	//1 组装第一台电脑， 并工作 
	//创建一个电脑对象。
	CPU *intelCPU = new IntelCPU; //具体的IntelCPU零件
	Card *intelCard = new IntelCard;
	Memory *intelMem = new IntelMem;
	Computer *com1 = new Computer(intelCPU, intelCard, intelMem);
	com1->work();
	cout << " ----- " << endl;
	//1 组装第二台电脑， 并工作 
	Card *nCard = new NvidaCard;
	Memory *kMem = new KingstonMem;
	Computer *com2 = new Computer(intelCPU, nCard, kMem);
	com2->work();
	Computer *com3 = new Computer(new IntelCPU, new NvidaCard, new KingstonMem);
	com3->work();
	delete com3;
#if 0
	delete intelCPU;
	delete intelCard;
	delete intelMem;
	delete nCard;
	delete kMem;
	delete com1;
	delete com2;
#endif
	return 0;
}
