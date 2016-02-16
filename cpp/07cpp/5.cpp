#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

/*
   1 子类对象可以当作父类对象使用
   2 子类对象可以直接赋值给父类对象
   3 子类对象可以直接初始化父类对象
   4 *** 父类指针可以直接指向子类对象
   5 父类引用可以直接引用子类对象
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

void myPrint(Parent *p)//通过一个父类指针的形参，就可以接收全部Parent家族的实参对象。
{
  p->printP();
}

int main(void)
{
  //Child c;
  //Parent p = c; //通过子类对象给父类对象初始化。
  //Parent p;
  //Child c = p; // 不可以通过父类对象给子类对象赋值。
  Parent p;

  Child c;
  c.printP();  // 子类对象 可以直接当 父类使用。
  cout << c.a << endl;
  p = c;//子类对象给父类对象赋值

  //父类的指针
  Parent *pp = NULL;
  Child *cp = NULL;
  //cp = &p;//a printP(); //子类指针执行父类对象， 父类的对象无法满足子类指针的所有需求，
  //cp->a;
  //cp->printC();
  //cp->b;
  //cp->printC();
  pp = &c; //让父类指针指向了子类的对象
  pp->a;
  pp->printP(); //父类指针指向子类 对象， 子类能够满足父类指针全部需求。
  //父类指针可以指向子类对象， 就是类的兼容性赋值原则

  myPrint(&p);
  myPrint(&c);

  return 0;
}
