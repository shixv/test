#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

/*
cin.get() //一次只能读取一个字符
cin.get(一个参数) //读一个字符
cin.get(三个参数) //可以读字符串
cin.getline()
cin.ignore()
cin.putback()
*/

//标准cin>>默认的是 根据空格来区分每一个变量
void test1()
{
	int myInt;
	long myLong;
	char buf[128] = { 0 };

	cin >> myInt;
	cin >> myLong;
	cin >> buf;

	cout << "myInt :" << myInt << endl;
	cout << "myLong :" << myLong << endl;
	cout << "buf :" << buf << endl;

}

void test2()
{
	char ch;

	while ((ch = cin.get()) != EOF) {
		cout << ch << endl;
	}
}

void test3()
{
	char a, b, c;

	char buf[10] = { 0 };

	cout << "请输入数据到缓冲区， 调用cin.get(a)去阻塞等待缓冲区数据，如果缓冲区中没有数据，就阻塞" << endl;
	//cin.get(a); //从缓冲区中读一个字节， 存到a中
	//cin.get(b);
	//cin.get(c);



	//cout << "a = " << a << endl;
	//cout << "b = " << b << endl;
	//cout << "c = " << c << endl;
	cin.get(buf, 10, ' ');

	cout << "buf :" << buf << endl;

}

int main(void)
{
	//test1();

	//test2();

	test3();
	
	return 0;
}
