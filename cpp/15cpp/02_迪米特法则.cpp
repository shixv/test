#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
using namespace std;
//����¥��
class AbstractBuilding{
	public:
		virtual void sale() = 0;
	public:
		string quality;
};
//����¥��A �͵�¥��
class BuidingA : public AbstractBuilding{
	public:
		BuidingA(){
			quality = "��Ʒ��";
		}
		virtual void sale(){
			cout << "�͵�¥�̱�����!" << endl;
		}
};
//����¥��B �е�¥��
class BuidingB : public AbstractBuilding{
	public:
		BuidingB(){
			quality = "��Ʒ��";
		}
		virtual void sale(){
			cout << "�е�¥�̱�����!" << endl;
		}
};
//����¥��C �ߵ�¥��
class BuidingC : public AbstractBuilding{
	public:
		BuidingC(){
			quality = "��Ʒ��";
		}
		virtual void sale(){
			cout << "�ߵ�¥�̱�����!" << endl;
		}
};
//�н�
class Mediator{
	public:
		Mediator(){
			//��ʼ�� ������¥����Ϣ��������
			AbstractBuilding* buiding = NULL;
			buiding = new BuidingA;
			mList.push_back(buiding);
			buiding = new BuidingB;
			mList.push_back(buiding);
			buiding = new BuidingC;
			mList.push_back(buiding);
		}
		//�ṩ����ӿ�
		AbstractBuilding* findBuiding(string quality){
			for (list<AbstractBuilding*>::iterator it = mList.begin(); it != mList.end(); it ++){
				if ((*it)->quality.compare(quality) == 0){
					return *it;
				}
			}
			return NULL;
		}
		~Mediator(){
			for (list<AbstractBuilding*>::iterator it = mList.begin(); it != mList.end(); it ++){
				if (*it != NULL){
					delete *it;
				}
			}
		}
	public:
		//��Ҫ��������¥����Ϣ
		list<AbstractBuilding*> mList;
};
//ҵ���� �����ҵ�����Ҫ�ĸ�Ʒ��¥��
void doBussiness(){
	//�����н�
	Mediator* mediator = new Mediator;
	AbstractBuilding* buiding =  mediator->findBuiding("���߲���");
	if (buiding == NULL){
		cout << "û������������¥��!" << endl;
		return;
	}
	buiding->sale();
}
int main(){
	doBussiness();
	system("pause");
	return EXIT_SUCCESS;
}
