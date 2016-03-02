#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//����ƻ��
class AbstractApple{
public:
	virtual void ShowName() = 0;
};
//�й�ƻ��
class ChinaApple : public AbstractApple{
public:
	virtual void ShowName(){
		cout << "�����й�ƻ����" << endl;
	}
};
//����ƻ��
class USAApple : public AbstractApple{
public:
	virtual void ShowName(){
		cout << "��������ƻ����" << endl;
	}
};
//�ձ�ƻ��
class JapanApple : public AbstractApple{
public:
	virtual void ShowName(){
		cout << "�����ձ�Сƻ����" << endl;
	}
};
//����:����ƻ��
class AfricanApple : public AbstractApple{
public:
	virtual void ShowName(){
		cout << "���Ƿ��޺�ƻ����" << endl;
	}
};
//�����㽶
class AbstractBanana{
public:
	virtual void ShowName() = 0;
};
//�й��㽶
class ChinaBanana :public AbstractBanana{
public:
	virtual void ShowName(){
		cout << "�����й����㽶��" << endl;
	}
};
//�����㽶
class USABanana : public AbstractBanana{
public:
	virtual void ShowName(){
		cout << "���������㽶��" << endl;
	}
};
//�ձ��㽶
class JapanBanana : public AbstractBanana{
public:
	virtual void ShowName(){
		cout << "�����ձ�С�㽶��" << endl;
	}
};
//����:�����㽶
class AfricanBanana : public AbstractBanana{
public:
	virtual void ShowName(){
		cout << "���Ƿ��޺��㽶��" << endl;
	}
};
//����Ѽ��
class AbstractPear{
public:
	virtual void ShowName() = 0;
};
//�й�Ѽ��
class ChinaPear :public AbstractPear{
public:
	virtual void ShowName(){
		cout << "�����й���Ѽ�棡" << endl;
	}
};
//����Ѽ��
class USAPear :public AbstractPear{
public:
	virtual void ShowName(){
		cout << "��������Ѽ�棡" << endl;
	}
};
//�ձ�Ѽ��
class JapanPear :public AbstractPear{
public:
	virtual void ShowName(){
		cout << "�����ձ�СѼ�棡" << endl;
	}
};
//����Ѽ��
class AfricanPear : public AbstractPear{
public:
	virtual void ShowName(){
		cout << "���Ƿ��޺�Ѽ�棡" << endl;
	}
};
//���󹤳�
class AbstractFactory{
public:
	virtual AbstractApple* CreateApple() = 0;
	virtual AbstractBanana* CreateBanana() = 0;
	virtual AbstractPear* CreatePear() = 0;
	//��������  
};
//�й�����
class ChinaFactory : public AbstractFactory{
public:
	virtual AbstractApple* CreateApple(){
		return new ChinaApple;
	}
	virtual AbstractBanana* CreateBanana(){
		return new ChinaBanana;
	}
	virtual AbstractPear* CreatePear(){
		return new ChinaPear;
	}
};
//��������
class USAFactory : public AbstractFactory{
public:
	virtual AbstractApple* CreateApple(){
		return new USAApple;
	}
	virtual AbstractBanana* CreateBanana(){
		return new USABanana;
	}
	virtual AbstractPear* CreatePear(){
		return new USAPear;
	}
};
//�ձ�С����
class JapanFactory : public AbstractFactory{
public:
	virtual AbstractApple* CreateApple(){
		return new JapanApple;
	}
	virtual AbstractBanana* CreateBanana(){
		return new JapanBanana;
	}
	virtual AbstractPear* CreatePear(){
		return new JapanPear;
	}
};
//���޺ڹ���
class AfricanFactory : public AbstractFactory{
public:
	virtual AbstractApple* CreateApple(){
		return new AfricanApple;
	}
	virtual AbstractBanana* CreateBanana(){
		return new AfricanBanana;
	}
	virtual AbstractPear* CreatePear(){
		return new AfricanPear;
	}
};
//���������һ����Ʒ�壬���Ͽ���ԭ��
//�������һ����Ʒ�ȼ��ṹ�������Ͽ���ԭ��
void test01(){
	AbstractApple* apple = NULL;
	AbstractBanana* banana = NULL;
	AbstractPear* pear = NULL;
	AbstractFactory* factory = NULL;
	//����й�ƻ�� �㽶 ��
	factory = new ChinaFactory; 
	apple = factory->CreateApple();
	banana = factory->CreateBanana();
	pear = factory->CreatePear();
	apple->ShowName();
	banana->ShowName();
	pear->ShowName();
	delete pear;
	delete banana;
	delete apple;
	delete factory;
	//���������ƻ�� �㽶 ��
	factory = new USAFactory;
	apple = factory->CreateApple();
	banana = factory->CreateBanana();
	pear = factory->CreatePear();
	apple->ShowName();
	banana->ShowName();
	pear->ShowName();
	delete pear;
	delete banana;
	delete apple;
	delete factory;
	//����ձ�
	factory = new JapanFactory;
	apple = factory->CreateApple();
	banana = factory->CreateBanana();
	pear = factory->CreatePear();
	apple->ShowName();
	banana->ShowName();
	pear->ShowName();
	delete pear;
	delete banana;
	delete apple;
	delete factory;
}
int main(){
	test01();
	system("pause");
	return EXIT_SUCCESS;
}