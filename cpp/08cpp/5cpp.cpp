#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//ͼ����
//ӵ�д��麯�����࣬���ǳ�����
//һ�������� �ǲ����ܱ�ʵ�����ġ�
//��������ڵ�������Ǳ��̳� �� ���еļ̳г���������࣬����ʵ�ֳ�����Ĵ��麯����
//������಻ʵ�ֳ�����Ĵ��麯������ô���������Ȼ��һ�������ࡣ���ܹ���ʵ������
class Shape
{
public:
	//�õ�ͼ������Ľӿڡ�  û�к����塣
	virtual double getArea() = 0; //���麯��
};
//������
class Circle :public Shape
{
public:
	Circle(double r)
	{
		this->r = r;
	}
	void print()
	{
		//
	}
#if 1
	//��Բ�����
	virtual double getArea() {
		cout << "����Բ��Area" << endl;
		return 3.14*r * r;
	}
#endif
private:
	double r; //Բ�İ뾶
};
//������
class Rect : public Shape
{
public:
	Rect(double a)
	{
		this->a = a;
	}
	//�����������
	virtual double getArea()  {
		cout << "���������ε�Area" << endl;
		return a*a;
	}
private:
	double a; //�����εı߳�
};
//дһ���ܹ��� ��ӡͼ������ļܹ�
void printShapeArea(Shape * sp)
{
	//sp->getArea()   getArea���麯���� �ͻᷢ����̬
	cout << "����� " << sp->getArea() << endl;
}
//ҵ��
int main(void)
{
	//�����������б�� . ͨ��������ָ�룬����main������ �����ʵ�壨Բ�������Σ� ���н���ϡ�
	Shape *sp1 = new Circle(10.0); //���Circle ����д������Ĵ��麯���� Circle ��Ȼ��һ�������࣬��Ȼ����ʵ����
	Shape *sp2 = new Rect(20.0);
		printShapeArea(sp1);
	printShapeArea(sp2);
	return 0;
}
