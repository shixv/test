#include <iostream>
using namespace std;
class SubSystem1{
	public:
		void run(){
			cout<<"xitongyiqigong..."<<endl;
		}
};
class SubSystem2{
	public:
		void run(){
			cout<<"xitong2qigong..."<<endl;
		}
};
class SubSystem3{
	public:
		void run(){
			cout<<"xitong3qigong..."<<endl;
		}
};
void test01(){
	SubSystem1* sys1=new SubSystem1;
	SubSystem2* sys1=new SubSystem2;
	SubSystem3* sys1=new SubSystem3;
	sys1->run();
	sys2->run();
	sys3->run();
	delete sys3;
	delete sys2;
	delete sys1;
}
class Facede{
	public:
		Facede(){
			SubSystem1* sys1=new SubSystem1;
			SubSystem2* sys1=new SubSystem2;
			SubSystem3* sys1=new SubSystem3;
		}
		void run(){
			sys1->run();
			sys2->run();
			sys3->run();
		}
	public:
		SubSystem1* sys1;
		SubSystem2* sys2;
		SubSystem3* sys3;
};
int main(void)
{
	return 0;
}
