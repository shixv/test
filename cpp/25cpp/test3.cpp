#include <iostream>
#include "sepqueue.hpp"
using namespace std;
int main(void)
{
	SeqQueue<int> queue(128);
	queue.Push(10);
	queue.Push(20);
	queue.Push(30);

	while(queue.size()>0){
		cout<<queue.Front()<<" ";
		queue.Pop();
	}
	return 0;
}
