#include <iostream>
using namespace std;
//��һ���������ߣ� ���ĳ�����
class BigBrother
{
public:
	//���Ҫ����ˣ�  ӵ��һ�����˵Ľӿ�.
	virtual void fightPeople() = 0;
};
//������ �����Ϊ������
//�����ʵ����
class EastNeverLose :public BigBrother
{
public:
	virtual void fightPeople()  {
		cout << "ʹ�ÿ������� ����" << endl;
	}
	void Zigong()
	{
	}
};
//�����ʵ����
class DuanYu :public BigBrother
{
public:
	virtual void fightPeople()  {
		cout << "ʹ�������� ����" << endl;
	}
};
//Boss
int main(void)
{
	//boss ֻ��Ҫ��һ���� �������ְλ
	BigBrother *bro = new EastNeverLose;
	//��� �����ȥ����
	bro->fightPeople();
	delete bro;
	return 0;
}
