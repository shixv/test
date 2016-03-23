#include <iostream>
using namespace std;
class Demo
{
	public:
		static int get(){return 5;}
};
int get(){return 10;}
namespace NS
{
	int get(){return 20;}
}
[[constructor(101)]] void p(void)
{
	cout<<"heheda"<<endl;
}

auto main(void)->int 
{
	Demo* pd=new Demo();
	Demo d;
	std::cout<<pd->get()<<std::endl; //5
	std::cout<<d.get()<<std::endl;//5
	std::cout<<NS::get()<<std::endl;//20
	std::cout<<Demo::get()<<std::endl;//20
	std::cout<<::get()<<std::endl;//10
	std::cout<<get()<<std::endl;//10
	return 0;
}
