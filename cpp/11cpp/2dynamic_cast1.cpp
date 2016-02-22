#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
int main(void)
{
	double PI = 3.141592653;
	int num = (int)PI; //C语言风格的强制类型转化，可读性比较差，转换是部分类型。
	int num2 = static_cast<int>(PI);  //我们一般在C语言中使用的强制类型转换都是 静态转换
	cout << "num: " << num << endl;
	cout << "num2:" << num2 << endl;
	return 0;
}