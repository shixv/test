#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//图形类
//拥有纯虚函数的类，就是抽象类
//一个抽象类 是不可能被实例化的。
//抽象类存在的意义就是被继承 ， 所有的继承抽象类的子类，必须实现抽象类的纯虚函数。
//如果子类不实现抽象父类的纯虚函数，那么这个子类依然是一个抽象类。不能够被实例化。
class Shape
{
public:
	//得到图形面积的接口。  没有函数体。
	virtual double getArea() = 0; //纯虚函数
};
//具体类
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
	//求圆的面积
	virtual double getArea() {
		cout << "调用圆的Area" << endl;
		return 3.14*r * r;
	}
#endif
private:
	double r; //圆的半径
};
//正方形
class Rect : public Shape
{
public:
	Rect(double a)
	{
		this->a = a;
	}
	//求正方形面积
	virtual double getArea()  {
		cout << "调用正方形的Area" << endl;
		return a*a;
	}
	void func1()
	{
	}
private:
	double a; //正方形的边长
};
//实现一个具体的类
class Tri : public Shape
{
public:
	Tri(double a, double h)
	{
		this->a = a;
		this->h = h;
	}
	virtual double getArea() {
		cout << " 三角形的面积" << endl;
		return 0.5*a*h;
	}
	void func()
	{
	}
private:
	double a; //低
	double h; //高
};
//写一个架构， 打印图形面积的架构
void printShapeArea(Shape * sp)
{
	//sp->getArea()   getArea是虚函数， 就会发生多态
	cout << "面积是 " << sp->getArea() << endl;
}
//业务
int main(void)
{
	//面向抽象类进行编程 . 通过抽象类指针，来将main函数跟 具体的实体（圆，正方形） 进行解耦合。
	Shape *sp1 = new Circle(10.0); //如果Circle 不重写抽象类的纯虚函数， Circle 依然是一个抽象类，依然不能实例化
	printShapeArea(sp1);
	delete sp1;
	Shape *sp2 = new Rect(20.0);
	printShapeArea(sp2);
	delete sp2;
	//实现三角形的业务
	Shape *sp3 = new Tri(10.0, 20.0);
	printShapeArea(sp3);
	delete sp3;
	return 0;
}