#ifndef LINKLIST_HPP
#define LINKLIST_HPP

template <class T>
class LinkNode{
	public:
		T data;
		LinkNode<T>* next;

};
template <class T>
class Linklist{
	public:
		LinkNode<T>* head;
		int length;
	public:
		Linklist(){
			LinkNode<T>* newnode=new LinkNode<T>();
			newnode->data=(T)NULL;
			newnode->next=NULL;
			this->head=newnode;
			this->length=0;
		}
		void Insert_Begin(T data){
			LinkNode<T>* newnode=new LinkNode<T>();
			newnode->data=data;
			newnode->next=NULL;

			this->head->next=newnode;
			this->length++;
		}
};
#endif
