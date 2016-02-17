#include <iostream>

using namespace std;

class Figure
{
	public:
		virtual void getArea()=0;
};
class Circle:public Figure
{
	public:
		Circle(int a,int b)
		{
			this->a=a;
			this->b=b;
		}
		virtual void getArea()
		{
			cout<<"yian de mina ji: "<<3.14*a*a<<endl;
		}
	private:
		int a;
		int b;
};

class Tri:public Figure
{
	public:
		Tri(int a,int b)
		{
			this->a=a;
			this->b=b;
		}
		virtual void getArea()
		{
			cout<<"san jiao xing mian ji "<<a*b/2<<endl;
		}

	private:
		int a;
		int b;
};

class Square:public Figure
{
	public:
		Square(int a,int b)
		{
			this->a=a;
			this->b=b;
		}
		virtual void getArea()
		{
			cout<<"si bian xing mian ji : "<<a*b<<endl;
		}

	private:
		int a;
		int b;
};

void area_func(Figure *base)
{
	base->getArea();
}

int main(void)
{
	Figure *base=NULL;

	Circle c1(10,20);
	Tri t1(20,30);
	Square s1(50,60);

	area_func(&c1);
	area_func(&t1);
	area_func(&s1);

	return 0;
}
