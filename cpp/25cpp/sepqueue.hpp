#ifndef seqqueue
#define seqqueue


template <class T>
class SeqQueue{
	public:
		SeqQueue(int len){
			this->address=new T[len];
			this->length=0;
			this->capacity=len;
		}
		~SeqQueue(){
			if(this->address!=NULL){
				delete[] this->address;
			}
		}
		void Push(T data){
			if(this->length==this->capacity)
				return;
			this->address[this->length]=data;
			this->length++;
		}
		T Front(){
			return this->address[0];
		}
		void Pop(){
			if(this->length==0){
				return;
			}
			for(int i=0;i<this->length;i++){
				this->address[i]=this->address[i+1];
			}
			this->length--;
		}
		int size(){
			return this->length;
		}
	public:
		T* address;
		int length;
		int capacity;
};

#endif
