#include <iostream>
using namespace std;
void print()
{
	cout<<"fuck"<<endl;
}
template<typename T,typename... Types>
void print(const T& firstArg,const Types&... args)
{
	cout<<firstArg;
	print(args...);
}
int main(void)
{
	print("fuck","you",123,'a','l',"l!\n");
	return 0;
}
