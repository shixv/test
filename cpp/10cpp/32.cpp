#include <iostream>
using namespace std;
template <class T>
class Complex;
template<class T>
Complex<T> mySub(Complex<T> &c1, Complex<T> &c2);
template <class T>
class Complex
{
	//����ȫ�ֺ���operator<< Ϊģ�������Ԫ����
	//1 ���˵����һ��ȫ�ֺ���Ϊģ�������Ԫ������ ��Ҫ ������������֮��� <T>
	//2 ��Ҫ����ʹ����Ԫ�� 
	friend ostream& operator<<(ostream &os, Complex<T> &c);
#if 0
	{
		os << "( " << c.a << ", " << c.b << " i )" << endl;
		return os;
	}
#endif
	//������Ԫ
	friend Complex<T> mySub<T>(Complex<T> &c1, Complex<T> &c2);
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
	void printComplex()
	{
		cout << "( " << a << ", " << b << " i )" << endl;
	}
#if 0
	//����+�Ų�����
	Complex operator+(Complex &another)
	{
		Complex temp(this->a + another.a, this->b + another.b);
		return temp;
	}
#endif
	Complex operator-(Complex &another);
	Complex operator+(Complex &another);
private:
	T a;
	T b;
};
template<class T>
Complex<T> Complex<T>::operator+(Complex<T> &another)
{
	Complex temp(this->a + another.a, this->b + another.b);
	return temp;
}
template <class T>
Complex<T> Complex<T>::operator-(Complex<T> &another)
{
	Complex temp(this->a - another.a, this->b - another.b);
	return temp;
}
//дһ��<<����������
#if 1
template<class T>
ostream& operator<<<T>(ostream &os, Complex<T> &c)
{
	os << "( " << c.a << ", " << c.b << " i )" << endl;
	return os;
}
#endif
//дһ��ȫ�ֵļ���
template <class T>
Complex<T>mySub(Complex<T> &c1, Complex<T> &c2)
{
	Complex<T> temp(c1.a - c2.a, c1.b - c2.b);
	return temp;
}
int main(void)
{
	Complex<int> c1(1, 2);
	Complex<int> c2(2, 4);
	c1.printComplex();
	c2.printComplex();
	Complex<int> c3;//����c3���޲ι���
	c3 = c1 + c2; // c1.operator+(c2);
	c3.printComplex();
	Complex<int> c4;
	c4 = c1 - c2;
	c4.printComplex();
	cout << " -----" << endl;
	cout << c3 << endl; // operator<<(cout, c3); // cout.operator(c3)	
	mySub(c1, c2);
	return 0;
}
