#include <iostream>

using namespace std;

class CPU
{
	public:
		virtual void caculate()=0;
};

class Card
{
	public:
		virtual void display()=0;
};

class Memory
{
	public:
		virtual void storage()=0;
};

class Computer
{
	public:
		Computer(CPU *cpu,Card *card,Memory *mem)
		{
			this->cpu=cpu;
			this->card=card;
			this->mem=mem;
		}

		void work()
		{
			this->cpu->caculate();
			this->card->display();
			this->mem->storage();
		}
	private:
		CPU *cpu;
		Card *card;
		Memory *mem;
};
		
class IntelCPU:public CPU
{
	public:
		void caculate(){
			cout<<"cpu work!"<<endl;
		}
};
class IntelMemory:public Memory
{
	public:
		void storage(){
			cout<<"mem work!"<<endl;
		}
};
class IntelCard:public Card
{
	public:
		void display(){
			cout<<"card work!"<<endl;
		}
};


int main(void)
{
	CPU *cpu=new IntelCPU;
	Card *card=new IntelCard;
	Memory *mem=new IntelMemory;
	Computer *com1=new Computer(cpu,card,mem);

	com1->work();


	return 0;
}
