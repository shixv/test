#include <iostream>
using namespace std;
class Shape
{
	private:
	public:
		virtual float getperimeter()=0;
		virtual ~Shape(){}
};
class Circle:public Shape
{
	private:
		float raduis;
	public:
		float getperimeter(){return raduis*raduis*3.14;}
		Circle():raduis(1.0){}
		Circle(float r):raduis(r){}
		~Circle(){}
};
class Triangle:public Shape
{
	private:
		float a;
		float b;
		float c;
	public:
		float	getperimeter(){return a+b+c;}
		Triangle()
		{
			a=3.0;
			b=4.0;
			c=5.0;
		}
		Triangle(float x,float y,float z):a(x),b(y),c(z){}
		~Triangle(){}
};
class Rectangle:public Shape
{
	private:
		float a;
		float b;
	public:
		float getperimeter(){return (a+b)*2.0;}
		Rectangle():a(3.0),b(4.0){}
		Rectangle(float x,float y):a(x),b(y){}
		~Rectangle(){}
};

void print(Shape &s)
{
	cout<<"zhou chang wei "<<s.getperimeter()<<endl;
}

int main(void)
{
	Circle c(10.0);
	Triangle t(5.0,6.0,7.0);
	Rectangle r(3.0,4.0);
	print(c);
	print(t);
	print(r);
	return 0;
}
