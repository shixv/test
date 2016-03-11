#include <iostream>
#include <stack>
using namespace std;
template <typename T>
class Queue{
	private:
		stack<T> *head;
		stack<T> *rear;
	public:
		Queue(){
			head=new stack<T>;
			rear=new stack<T>;
		}
		~Queue(){
			delete head;
			delete rear;
		}
		void clear(){
			while(!(head->empty()))head->pop();
			while(!(rear->empty()))rear->pop();
		}
		void push(const T& data){
			while(!(head->empty())){
				rear->push(head->top());	
				head->pop();
			}
			rear->push(data);
		}
		void pop(){
			while(!(rear->empty())){
				head->push(rear->top());
				rear->pop();
			}
			head->pop();
		}
		T& back(){
			while(!(head->empty())){
				rear->push(head->top());
				head->pop();
			}
			return rear->top();
		}
		T& front(){
			while(!(rear->empty())){
				head->push(rear->top());
				rear->pop();
			}
			return head->top();
		}
};
void test(){
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout<<q.front()<<endl;
	cout<<q.back()<<endl;
	q.pop();
	cout<<q.front()<<endl;
	q.clear();
}
int main(void)
{
	test();

	return 0;
}
