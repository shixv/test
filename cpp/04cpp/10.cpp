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
		//后++的成员函数写法
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
//全局重载操作符 前++
Complex & operator++(Complex &c)
{
	c.a++;
	c.b++;

	return c;
}

//如果是后++ 或者后-- 需要在形参多加一个 占位参数 int
//
const Complex & operator++(Complex &c, int) //亚元
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
