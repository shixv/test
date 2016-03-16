#ifndef SEQSTACK_HPP
#define SEQSTACK_HPP
template<class T>
class SeqStack{
public:
	SeqStack(int len){
		this->address = new T[len];
		this->length = 0;
	}
	//��ջ
	void Push(T data){
		this->address[this->length] = data;
		this->length++;
	}
	//���ջ��Ԫ��
	T Top(){
		return this->address[this->length - 1];
	}
	//��ջ
	void Pop(){
		if (this->length){
			this->length--;
		}
	}
	//���ջ��Ԫ�صĸ���
	int Size(){
		return this->length;
	}
public:
	T* address;
	int length;
};
#endif
