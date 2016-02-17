#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//------ ����� -------
//�����CPU��
class CPU
{
public:
	virtual void caculate() = 0;
};
//�����card
class Card
{
public:
	virtual void display() = 0;
};
//������ڴ���
class Memory
{
public:
	virtual void storage() = 0;
};
//�����������
class Computer
{
public:
	Computer(CPU *cpu, Card *card, Memory *mem)
	{
		this->cpu = cpu;
		this->card = card;
		this->mem = mem;
	}
	//���Թ����ķ���
	void work()
	{
		this->cpu->caculate(); //������̬�����õ�������ľ���ķ���
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
//------ ʵ�ֲ� -------
//Intel��CPU
class IntelCPU : public CPU
{
public:
	virtual void caculate()  {
		cout << "IntelCPU ��ʼ������" << endl;
	}
};
class IntelCard :public Card
{
public:
	virtual void display()  {
		cout << "IntelCard ��ʼ������" << endl;
	}
};
class IntelMem :public Memory
{
public:
	virtual void storage()  {
		cout << "IntelMem ��ʼ������" << endl;
	}
};
//�����King���ڴ���
class KingstonMem :public Memory
{
public:
	virtual void storage()  {
		cout << "KingstonMem ��ʼ������" << endl;
	}
};
//�����n��
class NvidaCard :public Card
{
public:
	virtual void display() {
		cout << "NvidaCard ��ʼ������" << endl;
	}
};
//--------------------
//------ ҵ���߼���----
int main(void)
{
	//1 ��װ��һ̨���ԣ� ������ 
	//����һ�����Զ���
	CPU *intelCPU = new IntelCPU; //�����IntelCPU���
	Card *intelCard = new IntelCard;
	Memory *intelMem = new IntelMem;
	Computer *com1 = new Computer(intelCPU, intelCard, intelMem);
	com1->work();
	cout << " ----- " << endl;
	//1 ��װ�ڶ�̨���ԣ� ������ 
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
