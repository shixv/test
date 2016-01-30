#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "MyArray.h"

using namespace std;

int main(void)
{
	MyArray array(10);

	//给数组赋值
	for (int i = 0; i < 10; i++) {
		int value = i + 10;
		array.setData(i, value);
	}

	cout << " -----" << endl;
	//遍历数组
	for (int i = 0; i < 10; i++) {
		//cout << array[i] << endl;
		cout << array.getData(i) << endl;
	}


	MyArray array2 = array;

	for (int i = 0; i < 10; i++)
	{
		cout << array2.getData(i) << endl;
	}

	return 0;
}
