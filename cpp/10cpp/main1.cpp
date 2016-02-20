#include <iostream>
#include "myvector1.h"

using namespace std;

int main(void)
{
	MyVector<int> vector_int(10);

	for (int i = 0; i < 10; i++) {
		vector_int[i] = i + 10;
	}
	cout << "vector_int:" << endl;
	cout << vector_int << endl;


	MyVector<int> vector_int2(vector_int);
	cout << "vector_int2:" << endl;
	cout << vector_int2 << endl;

	MyVector<char> vector_char(10);
	for (int i = 0; i < 10; i++) {
		vector_char[i] = 'a' + i;
	}

	cout << "vector_char:" << endl;
	cout << vector_char << endl;

	MyVector<char> vector_char2;

	vector_char2 = vector_char;
	cout << "vector_char2:" << endl;
	cout << vector_char2 << endl;

	
	return 0;
}
