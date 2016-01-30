#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "MyArray.h"

using namespace std;

int main(void)
{
	MyArray array1(10);

	//给数组赋值
	cin >> array1;

	cout << " -----" << endl;
	//遍历数组
	cout << array1 << endl;
	

#if 1
	MyArray array2 = array1; //Myarray array2(array1);

	cout << array2 << endl;

#endif

	MyArray array3;

	array3 = array1; //array3.operator=(array1);

	cout << array3 << endl;

	//if (array2 == array1) //array2.operator==(array1)
	//if (array2 != array1)

	if (array3 == array1) {
		cout << "array3 == array1" << endl;
	}
	else {
		cout << "array3 != array1" << endl;
	}

	if (array3 != array1) {
		cout << "array3 != array1" << endl;

	}
	else {
		cout << "array3 == array1" << endl;

	}

	return 0;
}