#include <iostream>
using namespace std;
class Caculator{
	public:
		Caculator(){
			this->a=0;
			this->b=0;
		}
		Caculator(int a,int b,string myoperator){
			this->a=a;
			this->b=b;
			this->myoperator=myoperator;
		}
		int getResult(int a,int b,string myoperator){
			if(myoperator.compare("+")==0){
				return a+b;
			}
			else if(myoperator.compare("-")==0){
				return a-b;
			}
			else if(myoperator.compare("/")==0){
				return a/b;
			}
			else if(myoperator.compare("*")==0){
				return a*b;
			}
			else
				return -1;
		}
		~Caculator(){}	
	public:
		int a;
		int b;
		string myoperator;
};
void test01(){
	Caculator caculator;
	int ret=caculator.getResult(10,20,"+");
	cout<<ret<<endl;
}
class abstractcaculator{
	public:
		abstractcaculator(int a,int b):a(a),b(b){}
		virtual int getResult()=0;
		virtual ~abstractcaculator(){};
	public:
		int a;
		int b;
};
class Plus :public abstractcaculator{
	public:
		Plus(int a,int b):abstractcaculator(a,b){}
		~Plus(){}
		int getResult(){
			return a+b;
		}
};
class Minute:public abstractcaculator{
	public:
		~Minute(){}
		Minute(int a,int b):abstractcaculator(a,b){}
		virtual int getResult(){
			return a-b;
		}
};
class Divide:public abstractcaculator{
	public:
		Divide(int a,int b):abstractcaculator(a,b){}
		~Divide(){}
		virtual int getResult(){
			return a/b;
		}
};
class Multiplies:public abstractcaculator{
	public:
		Multiplies(int a,int b):abstractcaculator(a,b){}
		~Multiplies(){}
		virtual int getResult(){
			return a*b;
		}
};
class Module:public abstractcaculator{
	public:
		Module(int a,int b):abstractcaculator(a,b){}
		~Module(){}
		virtual int getResult(){
			return a%b;
		}
};
void doBussiness(abstractcaculator* caculator){
	caculator->getResult();
}
void test02(){
	abstractcaculator* caculator=NULL;
	caculator = new Plus(10,20);
	cout<<"jieguo: "<<caculator->getResult()<<endl;
	delete caculator;
	caculator=new Minute(100,20);
	cout<<"jieguo: "<<caculator->getResult()<<endl;
}
int main(void)
{
	return 0;
}
