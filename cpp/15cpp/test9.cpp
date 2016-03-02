#include <iostream>
#include <memory>
using namespace std;
class Simple
{
	public:
		Simple(){mIntPtr=new int();}
		~Simple(){delete mIntPtr;}
		void setIntPtr(int inInt){*mIntPtr=inInt;}
	protected:
		int* mIntPtr;
};
void doSomething(shared_ptr<Simple>& outSimplePtr)
{
	outSimplePtr=shared_ptr<Simple>(new Simple);
}
int main(void)
{
	shared_ptr<Simple> simplePtr(new Simple);
	for(int i=0;i<10;i++)
	doSomething(simplePtr);
//	delete simplePtr;
	return 0;
}
