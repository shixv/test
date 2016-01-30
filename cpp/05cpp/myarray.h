#include <iostream>

using namespace std;

class MyArray
{
	public:
		MyArray();
		MyArray(int len);
		~MyArray();
		MyArray(const MyArray &another);

		void setData(int index,int value);
		int getData(int index);

		int &operator[](int index)const;

		int getLen()const
		{
			return this->len;
		}
		friend ostream &operator<<(ostream &os,const MyArray &array);
		friend istream &operator>>(istream &is,MyArray &array);

	private:
		int len;
		int *space;
};
