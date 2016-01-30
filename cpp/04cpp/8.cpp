#include <iostream>

using namespace std;

class Complex
{
	private:
		int a;
		int b;

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
		Complex operator+(Complex &c1, Complex &c2);
		Complex operator-(Complex &c1, Complex &c2);
		Complex operator*(Complex &c1, Complex &c2);


		//����һ���ֲ�����
//		Complex addComplex(Complex &another)
//		{
//			Complex temp(this->a + another.a, this->b + another.b);
//			return temp;
//		}

		//����һ��ȫ�ֺ���Ϊ��Ԫ
		//	friend Complex operator+(Complex &c1, Complex &c2);

};

//дһ��ȫ�ֵķ���
//Complex addComplex(Complex &c1, Complex &c2)
//{
//	Complex temp(c1.a + c2.a, c1.b + c2.b);

//	return temp;
//}

//ȫ���ṩһ��+�����������
Complex Complex::operator+(Complex &c1, Complex &c2)
{
	Complex temp(c1.a + c2.a, c1.b + c2.b);
	return temp;
}
Complex Complex::operator-(Complex &c1,Complex &c2)
{
	Complex tmp(c1.a-c2.a,c1.b-c2.b);
	return tmp;
}
Complex Complex::operator*(Complex &c1,Complex &c2)
{
	Complex tmp(c1.a*c2.a-c1.b*c2.b,c1.a*c2.b+c2.a*c1.b);
	return tmp;
}

int main(void)
{
	Complex c1(1, 2);
	Complex c2(3, 4);
	//c3 = c1 + c2;
	//	Complex c3 = addComplex(c1, c2);

//	c3.print();

	//	Complex c4 = c1.addComplex(c2);

//	c4.print();

	//������һ������� һ���µĺ��壬���� ���������
	//Complex c5 = c1 + c2;
//	Complex c5 = operator+(c1, c2);
//	c5.print();

	Complex c6 = c1 + c2; //operator+(c1, c2)
	c6.print();


	return 0;
}
