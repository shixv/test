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

#if 0
		friend Complex & operator++(Complex &c);
		friend const Complex & operator++(Complex &c, int);
#endif
		friend Complex & operator--(Complex &c);


		//++c1,  c1.operator++();
		Complex & operator++()
		{
			this->a++;
			this->b++;

			return *this;
		}
		//��++�ĳ�Ա����д��
		const Complex  operator++(int)
		{
			Complex temp(this->a, this->b);

			this->a++;
			this->b++;

			return temp;
		}
		Complex &operator--()
		{
			this->a--;
			this->b--;
			return *this;
		}
		const Complex operator--(int)
		{
			Complex temp(this->a,this->b);
			this->a--;
			this->b--;
			return temp;
		}

	private:
		int a;
		int b;
};

#if 0
//ȫ�����ز����� ǰ++
Complex & operator++(Complex &c)
{
	c.a++;
	c.b++;

	return c;
}

//����Ǻ�++ ���ߺ�-- ��Ҫ���βζ��һ�� ռλ���� int
//
const Complex & operator++(Complex &c, int) //��Ԫ
{
	Complex temp(c.a, c.b);

	c.a++;
	c.b++;

	return temp;
}
#endif



/*Complex & operator--(Complex &c)
{
	c.a--;
	c.b--;

	return c;
}
*/
int main(void)
{
//	int a = 10;

	Complex c1(10, 20);
	Complex c2;

	c2 = c1--;

	c1.print();
	c2.print();


	return 0;
}
