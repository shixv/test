#include <iostream>
using namespace std;
class BankWorker{
	public:
		void Pay(){
			cout<<"zhifuyewu"<<endl;
		}
		void Transform(){
			cout<<"zhuanzhang"<<endl;
		}
		void Save(){
			cout<<"cunkuan"<<endl;
		}
};
void doBussiness01(){
	BankWorker* worker=new BankWorker;
	worker->Pay();
	worker->Transform();
	worker->Save();
}
class AbsoluteBankWorker{
	public:
		virtual void doBussiness()=0;
};
class PayBankWorker:public AbsoluteBankWorker{
	virtual void doBussiness(){
		cout<<"zhifuyewu"<<endl;
	}
};
class TransformBankWorker:public AbsoluteBankWorker{
	public:
		virtual void doBussiness(){
			cout<<"zhuanzhang"<<endl;
		}
};
class SaveBankWorker:public AbsoluteBankWorker{
	public:
		virtual void doBussiness(){
			cout<<"cunkuan"<<endl;;
		}
};
void doLogic(AbsoluteBankWorker* worker){
	worker->doBussiness();
}
void test01(){
	AbsoluteBankWorker* worker=NULL;
	worker=new SaveBankWorker;
	doLogic(worker);
}
int main(void)
{
	test01();	
	return 0;
}
