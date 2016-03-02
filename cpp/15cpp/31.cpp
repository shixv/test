#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//计算器
class Caculator{
	public:
		Caculator(){
			this->a = 0;
			this->b = 0;
			this->MyOperator = "";
		}
		//获得结果
		int GetResult(int a, int b, string MyOperator){
			if (MyOperator.compare("+") == 0){
				return a + b;
			}
			else if (MyOperator.compare("-") == 0){
				return a - b;
			}
			else if (MyOperator.compare("/") == 0){
				return a / b;
			}
			else if (MyOperator.compare("*") == 0){
				return a * b;
			}
			else{
				return -1;
			}
		}
	public:
		int a;
		int b;
		string MyOperator;
};
void test01(){
	Caculator caculator;
	int ret = caculator.GetResult(10,20,"+");
	cout << ret << endl;
}
//最好扩展功能的时候，不要去修改源代码，应该通过增加代码完成扩展
//简单问题复杂化....
//计算器的抽象类
class AbstractCaculator{
	public:
		AbstractCaculator(int a,int b):a(a),b(b){}
		virtual int GetResult() = 0; //纯虚函数
	public:
		int a;
		int b;
};
//加法计算器
class Plus : public AbstractCaculator{
	public:
		Plus(int a, int b) :AbstractCaculator(a, b){}
		virtual int GetResult(){
			return a + b;
		}
};
//减法计算器
class Minute : public AbstractCaculator{
	public:
		Minute(int a, int b) :AbstractCaculator(a, b){}
		virtual int GetResult(){
			return a - b;
		}
};
//除法计算器
class Divide : public AbstractCaculator{
	public:
		Divide(int a, int b) :AbstractCaculator(a, b){}
		virtual int GetResult(){
			return a / b;
		}
};
//乘法
class Multiplies : public AbstractCaculator{
	public:
		Multiplies(int a, int b) : AbstractCaculator(a, b){}
		virtual int GetResult(){
			return a * b;
		}
};
//新增加功能 取模运算  通过增加代码完成
class Module : public AbstractCaculator{
	public:
		Module(int a, int b) : AbstractCaculator(a, b){}
		virtual int GetResult(){
			return a % b;
		}
};
//计算操作
void doBussiness(AbstractCaculator* caculator){
	caculator->GetResult();
}
void test02(){
	AbstractCaculator* caculator = NULL;
	//创建加法计算器
	caculator = new Plus(10,20);
	cout << "结果：" << caculator->GetResult() << endl;
	delete caculator;
	caculator = new Minute(100,20);
	cout << "结果：" << caculator->GetResult() << endl;
	delete caculator;
}
int main(){
	system("pause");
	return EXIT_SUCCESS;
}
