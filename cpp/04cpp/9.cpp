#include <iostream>

using namespace std;

class Complex
{
public:
	Complex()
	{
		this->a = 0;
		this->b = 0;
	}
	Complex(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	void print()
	{
		cout << "( " << a << ", " << b << "i )" << endl;
	}

	Complex & operator+=(Complex &c1);
	Complex & operator-=(Complex &c1);

private:
	int a;
	int b;
};

Complex  & Complex::operator+=(Complex &c1)
{
	this->a += c1.a;
	this->b += c1.b;

	return *this;
}
Complex  & Complex::operator-=(Complex &c1)
{
	this->a -= c1.a;
	this->b -= c1.b;

	return *this;
}

int main(void)
{
	Complex c1(10, 20);
	Complex c2(100, 300);

	(c1 += c2) += c2;

	c1.print();
	c2.print();
	
	return 0;
}
