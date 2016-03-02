#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//������
class Caculator{
	public:
		Caculator(){
			this->a = 0;
			this->b = 0;
			this->MyOperator = "";
		}
		//��ý��
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
//�����չ���ܵ�ʱ�򣬲�Ҫȥ�޸�Դ���룬Ӧ��ͨ�����Ӵ��������չ
//�����⸴�ӻ�....
//�������ĳ�����
class AbstractCaculator{
	public:
		AbstractCaculator(int a,int b):a(a),b(b){}
		virtual int GetResult() = 0; //���麯��
	public:
		int a;
		int b;
};
//�ӷ�������
class Plus : public AbstractCaculator{
	public:
		Plus(int a, int b) :AbstractCaculator(a, b){}
		virtual int GetResult(){
			return a + b;
		}
};
//����������
class Minute : public AbstractCaculator{
	public:
		Minute(int a, int b) :AbstractCaculator(a, b){}
		virtual int GetResult(){
			return a - b;
		}
};
//����������
class Divide : public AbstractCaculator{
	public:
		Divide(int a, int b) :AbstractCaculator(a, b){}
		virtual int GetResult(){
			return a / b;
		}
};
//�˷�
class Multiplies : public AbstractCaculator{
	public:
		Multiplies(int a, int b) : AbstractCaculator(a, b){}
		virtual int GetResult(){
			return a * b;
		}
};
//�����ӹ��� ȡģ����  ͨ�����Ӵ������
class Module : public AbstractCaculator{
	public:
		Module(int a, int b) : AbstractCaculator(a, b){}
		virtual int GetResult(){
			return a % b;
		}
};
//�������
void doBussiness(AbstractCaculator* caculator){
	caculator->GetResult();
}
void test02(){
	AbstractCaculator* caculator = NULL;
	//�����ӷ�������
	caculator = new Plus(10,20);
	cout << "�����" << caculator->GetResult() << endl;
	delete caculator;
	caculator = new Minute(100,20);
	cout << "�����" << caculator->GetResult() << endl;
	delete caculator;
}
int main(){
	system("pause");
	return EXIT_SUCCESS;
}
