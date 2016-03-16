#include <iostream>
using namespace std;
class teacher01{
	public:
		void PrintTeacher(){
			cout<<"teacher01"<<endl;
		}
};
class teacher02{
	public:
		virtual void PrintTeacher(){
			cout<<"teacher01"<<endl;
		}
		virtual void PrintTeacher01(){
			cout<<"teacher02"<<endl;
		}
};
class Son:public teacher02{
	public:
		virtual void PrintTeacher03(){
			cout<<"teacher03"<<endl;
		}
};
typedef void(*Func)(void);

int main(void){
	teacher02 teacher;
	Func testPrint=(Func)(*((int*)*((int*)(&teacher))+1));
	testPrint();
	cout<<"size: "<<sizeof(Son)<<endl;
	Son son;
	
	testPrint=(Func)(*((int*)*((int*)(&son))+2));
	testPrint();
	

	return 0;
}
