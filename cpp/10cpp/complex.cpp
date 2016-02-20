#include <iostream>
using namespace std;

template<class T>
class Complex
{
	public:
		Complex()
		{
			this->a=0;
			this->b=0;
		}
		Complex(int a,int b)
		{
			this->a=a;
			this->b=b;
		}
		void printComplex()
		{
			cout<<"("<<a<<","<<b<<"i)"<<endl;
		}
		Complex operator+(Complex &another);
		Complex operator-(Complex &another);
	private:
		T a;
		T b;
};

template<class T>
Complex<T> Complex<T>::operator+(Complex<T> &another)
{
	Complex<T> temp(this->a+another.a,this->b+another.b);
	return temp;
}
template<class T>
Complex<T> Complex<T>::operator-(Complex<T> &another)
{
	Complex<T> temp(this->a-another.a,this->b-another.b);
	return temp;
}

int main(void)
{
	Complex<int> c1(1,2);
	Complex<int> c2(2,4);

	c1.printComplex();
	c2.printComplex();

	Complex<int> c3=c1+c2;
	c3.printComplex();
	Complex<int> c4=c1-c2;
	c4.printComplex();
	return 0;
}
