#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
//写一个自定义的 异常，来继承标准的异常
class MyExcepion :public exception
{
	public:
		MyExcepion(char *m_s)
		{
			this->m_s = m_s;
		}
		//重写exception中的虚函数 what方法
		char* what(void) const {
			//在这里实现Mycectipn的what具体的方法
			cout << "MyException的异常 " << endl;
			return this->m_s;
		}
	private:
		char *m_s;
};
class Teacher
{
	public:
		Teacher(int id, string name)
		{
			if (id > 100) {
				//认为id>100 是越界， 抛出一个out_of_range异常
				string str = "id 超出范围";
				throw out_of_range(str);
			}
			this->id = id;
			this->name = name;
		}
	private:
		int id;
		string name;
};
int main(void)
{
	try {
		Teacher t1(10001, "zhang3");
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
	try {
		throw MyExcepion("自定义的异常数据");
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
	return 0;
}
