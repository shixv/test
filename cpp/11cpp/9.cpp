#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
//дһ���Զ���� �쳣�����̳б�׼���쳣
class MyExcepion :public exception
{
	public:
		MyExcepion(char *m_s)
		{
			this->m_s = m_s;
		}
		//��дexception�е��麯�� what����
		char* what(void) const {
			//������ʵ��Mycectipn��what����ķ���
			cout << "MyException���쳣 " << endl;
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
				//��Ϊid>100 ��Խ�磬 �׳�һ��out_of_range�쳣
				string str = "id ������Χ";
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
		throw MyExcepion("�Զ�����쳣����");
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
	return 0;
}
