#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//���й�����Ա
class BankWorker{
	public:
		void Pay(){
			cout << "֧��ҵ��" << endl;
		}
		void Transform(){
			cout << "ת��ҵ��" << endl;
		}
		void Save(){
			cout << "���ҵ��" << endl;
		}
};
void doBussiness01(){
	//Υ����һְ��ԭ��
	BankWorker* worker = new BankWorker;
	worker->Pay();
	worker->Save();
	worker->Transform();
}
//�������й�����Ա
class AbstractBankWorker{
	public:
		virtual void doBussiness() = 0;
};
//ר�Ÿ���֧��ҵ��
class PayBankWorker : public AbstractBankWorker{
	public:
		virtual void doBussiness(){
			cout << "����֧��ҵ��!" << endl;
		}
};
//ר�Ÿ���ת��ҵ��
class TransformBankWorker : public AbstractBankWorker{
	public:
		virtual void doBussiness(){
			cout << "����ת��ҵ��!" << endl;
		}
};
//ר�Ű�����ҵ��
class SaveBankWorker : public AbstractBankWorker{
	public:
		virtual void doBussiness(){
			cout << "������ҵ��!" << endl;
		}
};
//�߲�ҵ��
void doLogic(AbstractBankWorker* worker){
	worker->doBussiness();
}
void test01(){
	AbstractBankWorker* worker = NULL;
	worker = new SaveBankWorker;
	//�߲�ҵ��
	doLogic(worker);
}
int main(){
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
