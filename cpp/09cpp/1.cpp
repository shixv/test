#include <iostream>
using namespace std;
class Shape
{
	public:
		virtual void show()=0;
		virtual void showArea()=0;
		virtual ~Shape(){
		}
};
class Circle: public Shape
{
	public:
		virtual void show()
		{
			cout<<this->r<<endl;
		}
		~Circle(){
			cout<<"~Circle()\n";
		}
		Circle(double r)
		{
			this->r=r;
		}
		virtual void showArea(){
			cout<<r*r*3.14<<endl;
		}
	private:
		double r;
};
class Square:public Shape
{
	public:
		Square(double a)
		{
			cout<<"Square()."<<endl;
			this->a=a;
		}
		virtual void show(){
			cout<<this->a<<endl;
		}
		virtual void showArea()
		{
			cout<<a*a<<endl;
		}
		~Square()
		{
			cout<<"~Square().."<<endl;
		}
	private:
		double a;
};
int main(void)
{
	Shape *array[2];
	for(int i=0;i<2;i++)
	{
		if(i==0)
		{
			double r;
			cout<<"please input r"<<endl;
			cin>>r;
			array[0]=new Circle(r);
		}
		else{
			double a;
			cout<<"Please input a"<<endl;
			cin>>a;
			array[1]=new Square(a);
		}
	}
	for(int i=0;i<2;i++)
	{
		array[i]->show();
		array[i]->showArea();
	}
	return 0;
}
