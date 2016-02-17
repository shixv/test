#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
class Parent
{
public:
	Parent(int a)
	{
		cout << "Parent(int a)..." << endl;
		this->a = a;
		print();// �˴� ���õ��Ǹ����print ���� �����print��
					//���õ��Ǹ����print���� Ϊʲô��
					//ԭ�� ֻ�� ��ʱ�������vptrָ��ָ����Ǹ�����麯����
	}
	virtual void print()
	{
		cout << "Parent Print()... a = "  <<a << endl;
	}
	virtual ~Parent()
	{
	}
private:
	int a;
};
class Child :public Parent
{
public:
	Child(int a, int b) :Parent(a)
	{
		cout << "Child (int ,int )..." << endl;
		this->b = b;
		//�ڴ˴��� vptrָ���Ѿ���ָ������麯����ת���� ������麯����
		print();//���õ��Ǹ���� ���������
		//���� ��Ҫ�ڹ��캯���� �����麯�� ��������̬�� Ҳ��ò�Ҫ�ڹ��캯����дҵ��
	}
	virtual void print()
	{
		cout << "Child Print().. b =" << b << endl;
	}
	~Child()
	{
	}
private:
	int b;
};
int main(void)
{
	Parent *pp = new Child(10, 20);
	pp->print(); //������̬ �����Child ��print����
	delete pp;
	return 0;
}
