#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

/*
   1 ���������Ե����������ʹ��
   2 ����������ֱ�Ӹ�ֵ���������
   3 ����������ֱ�ӳ�ʼ���������
   4 *** ����ָ�����ֱ��ָ���������
   5 �������ÿ���ֱ�������������
   */
class Parent
{
  public:
	void printP()
	{
	  cout << "a = " << a << endl;
	}
	int a;
};

class Child :public Parent
{
  public:
	void printC()
	{
	  cout << "Child :: print: b = " << b << endl;
	}
	int b;
};

void myPrint(Parent *p)//ͨ��һ������ָ����βΣ��Ϳ��Խ���ȫ��Parent�����ʵ�ζ���
{
  p->printP();
}

int main(void)
{
  //Child c;
  //Parent p = c; //ͨ������������������ʼ����
  //Parent p;
  //Child c = p; // ������ͨ�����������������ֵ��
  Parent p;

  Child c;
  c.printP();  // ������� ����ֱ�ӵ� ����ʹ�á�
  cout << c.a << endl;
  p = c;//���������������ֵ

  //�����ָ��
  Parent *pp = NULL;
  Child *cp = NULL;
  //cp = &p;//a printP(); //����ָ��ִ�и������ ����Ķ����޷���������ָ�����������
  //cp->a;
  //cp->printC();
  //cp->b;
  //cp->printC();
  pp = &c; //�ø���ָ��ָ��������Ķ���
  pp->a;
  pp->printP(); //����ָ��ָ������ ���� �����ܹ����㸸��ָ��ȫ������
  //����ָ�����ָ��������� ������ļ����Ը�ֵԭ��

  myPrint(&p);
  myPrint(&c);

  return 0;
}
