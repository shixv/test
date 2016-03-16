#ifndef SEQSTACK_HPP
#define SEQSTACK_HPP
template<class T>
class SeqStack{
public:
	SeqStack(int len){
		this->address = new T[len];
		this->length = 0;
	}
	//入栈
	void Push(T data){
		this->address[this->length] = data;
		this->length++;
	}
	//获得栈顶元素
	T Top(){
		return this->address[this->length - 1];
	}
	//出栈
	void Pop(){
		if (this->length){
			this->length--;
		}
	}
	//获得栈中元素的个数
	int Size(){
		return this->length;
	}
public:
	T* address;
	int length;
};
#endif
