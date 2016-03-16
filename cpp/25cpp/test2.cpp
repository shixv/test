#include<iostream>
using namespace std;

#include"SeqStack.hpp"


int main(){

	SeqStack<int> stack(128);
	stack.Push(10);
	stack.Push(20);
	stack.Push(30);

	while (stack.Size() > 0){
		int val =  stack.Top();
		cout << val << " ";
		stack.Pop();
	}

	cout << endl;


	system("pause");
	return 0;
}