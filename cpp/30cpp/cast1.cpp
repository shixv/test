#include <iostream>
using namespace std;

void cast1(char* b)
{
	cout<<"QAQ"<<endl;
}
int main(void){
	const char* a="ajfadsk";
	cast1(const_cast<char*>(a));
	return 0;
}
