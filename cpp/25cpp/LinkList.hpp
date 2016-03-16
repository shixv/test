#ifndef LINKLIST_HPP
#define LINKLIST_HPP
//链表节点
template<class T>
class LinkNode{
public:
	T data;
	LinkNode<T>* next;
};
//链表类
template<class T>
class LinkList{
public:
	//打印回调
	typedef void(*PRINTNODE)(T);
	LinkList(){
		//创建头结点
		LinkNode<T>* newnode = new LinkNode<T>();
		newnode->data = (T)NULL;
		newnode->next = NULL;
		this->head = newnode;
		this->length = 0;
	}
	//删除堆内存
	~LinkList(){
		if (this->head == NULL){
			return;
		}
		LinkNode<T>* pCurrent = this->head;
		while (pCurrent != NULL){
			//缓存下一个节点
			LinkNode<T>* pNext = pCurrent->next;
			delete pCurrent;
			pCurrent = pNext;
		}
	}
	//头插法
	void Insert_Begin(T data){
		//创建新的节点
		LinkNode<T>* newnode = new LinkNode<T>();
		newnode->data = data;
		newnode->next = NULL;
		newnode->next = this->head->next;
		this->head->next = newnode;
		this->length++;
	}
	//尾插法
	void Insert_Back(T data){
		//创建节点
		LinkNode<T>* newnode = new LinkNode<T>();
		newnode->data = data;
		newnode->next = NULL;
		//辅助指针
		LinkNode<T>* pCurrent = this->head;
		while (pCurrent->next != NULL){
			pCurrent = pCurrent->next;
		}
		pCurrent->next = newnode;
		this->length++;
	}
	//增加打印
	void PrintList(PRINTNODE print){
		LinkNode<T>* pCurrent = this->head->next;
		while (pCurrent != NULL){
			//缓存下一个节点
			print(pCurrent->data);
			pCurrent = pCurrent->next;
		}
	}
public:
	LinkNode<T> * head; //头结点
	int length; //链表长度
};
#endif
