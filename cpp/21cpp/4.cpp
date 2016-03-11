#include <iostream>
#include <vector>
using namespace std;
class Observer{
	public:
		virtual void response()=0;
};
class Subject{
	public:
		virtual void addObserver(Observer*)=0;
		virtual void cry()=0;
};
class Cat:public Subject{
	private:
		vector<Observer*> list;
		string name;
	public:
		Cat(string name){
			this->name=name;
		}
		void addObserver(Observer* obs){
			list.push_back(obs);
		}
		void cry(){
			cout<<name<<" begin cry~~"<<endl;
			for(auto& i:list){
				i->response();
			}
		}
};
class Mouse:public Observer{
	private:
		string name;
	public:
		Mouse(string name,Subject* subject){
			this->name=name;
			subject->addObserver(this);
		}
		void response(){
			cout<<name<<" run away~~~"<<endl;
		}
};
class Master:public Observer{
	private:
		string name;
	public:
		Master(string name,Subject* subject){
			this->name=name;
			subject->addObserver(this);
		}
		void response(){
			cout<<name<<" wake up~~~"<<endl;
		}
};
void test(){
	Cat *Tom=new Cat("Tom");
	Mouse Jerry("Jerry",Tom);
	Master Jack("Jack",Tom);
	Tom->cry();
}
int main(void){
	test();
	return 0;
}
