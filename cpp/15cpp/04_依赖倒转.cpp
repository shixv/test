#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//银行工作人员
class BankWorker{
	public:
		void Pay(){
			cout << "支付业务" << endl;
		}
		void Transform(){
			cout << "转账业务" << endl;
		}
		void Save(){
			cout << "存款业务" << endl;
		}
};
void doBussiness01(){
	//违反单一职责原则
	BankWorker* worker = new BankWorker;
	worker->Pay();
	worker->Save();
	worker->Transform();
}
//抽象银行工作人员
class AbstractBankWorker{
	public:
		virtual void doBussiness() = 0;
};
//专门负责支付业务
class PayBankWorker : public AbstractBankWorker{
	public:
		virtual void doBussiness(){
			cout << "办理支付业务!" << endl;
		}
};
//专门负责转账业务
class TransformBankWorker : public AbstractBankWorker{
	public:
		virtual void doBussiness(){
			cout << "办理转账业务!" << endl;
		}
};
//专门办理存款业务
class SaveBankWorker : public AbstractBankWorker{
	public:
		virtual void doBussiness(){
			cout << "办理存款业务!" << endl;
		}
};
//高层业务
void doLogic(AbstractBankWorker* worker){
	worker->doBussiness();
}
void test01(){
	AbstractBankWorker* worker = NULL;
	worker = new SaveBankWorker;
	//高层业务
	doLogic(worker);
}
int main(){
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
