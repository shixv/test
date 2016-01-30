#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	Student(int id, string name)
	{
		this->id = id;
		this->name = name;
	}

	void printS()
	{
		cout << id << name << endl;
	}
private:
	int id;
	string name;
};

int main(void)
{
	string str = "123456712242342323435"; //string str("1234566")
	string str1(str); //string str1 = str2;
	cout << str << endl;

	cout << str1 << endl;

	for (unsigned int i = 0; i < str1.length(); i++)
	{
		cout << str[i] << endl;
	}



	string str2;
	cin >> str2;
	cout<<str2<<endl;
	//string str3 = str1 + str2;

	str2 = str1;

	cout << "str2 :" << str2 << endl;
	if (str1 != str2)
	{

	}

	
	return 0;
}
