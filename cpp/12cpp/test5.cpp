#include <iostream>
#include <memory>
using namespace std;

template <class T>
void print(auto_ptr<T>& p)
{
	if(p.get()==NULL){
		cout<<"NULL"<<endl;
	}
	else{
		cout<<*p<<endl;
	}
}
int main(void)
{
	auto_ptr<int> pa(new int(12));
	print(pa);
	cout<<*pa<<endl;
	*pa=13;
	cout<<*pa<<endl;
	return 0;
}
