#include <iostream>
#include <functional>
using namespace std;

template <int i,typename FuncType>
class Loop
{
	public:
		static inline void Do(FuncType func){
			Loop<i-1,FuncType>::Do(func);
			func(i);
		}
};
template<typename FuncType>
class Loop<-1,FuncType>
{
	public:
		static inline void Do(FuncType func){}
};
void DoWork(int i){cout<<"DoWork("<<i<<")"<<endl;}

int main(void)
{
	Loop<100,function<void(int)>>::Do(DoWork);
	return 0;
}
