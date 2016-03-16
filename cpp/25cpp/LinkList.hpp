#ifndef LINKLIST_HPP
#define LINKLIST_HPP
//����ڵ�
template<class T>
class LinkNode{
public:
	T data;
	LinkNode<T>* next;
};
//������
template<class T>
class LinkList{
public:
	//��ӡ�ص�
	typedef void(*PRINTNODE)(T);
	LinkList(){
		//����ͷ���
		LinkNode<T>* newnode = new LinkNode<T>();
		newnode->data = (T)NULL;
		newnode->next = NULL;
		this->head = newnode;
		this->length = 0;
	}
	//ɾ�����ڴ�
	~LinkList(){
		if (this->head == NULL){
			return;
		}
		LinkNode<T>* pCurrent = this->head;
		while (pCurrent != NULL){
			//������һ���ڵ�
			LinkNode<T>* pNext = pCurrent->next;
			delete pCurrent;
			pCurrent = pNext;
		}
	}
	//ͷ�巨
	void Insert_Begin(T data){
		//�����µĽڵ�
		LinkNode<T>* newnode = new LinkNode<T>();
		newnode->data = data;
		newnode->next = NULL;
		newnode->next = this->head->next;
		this->head->next = newnode;
		this->length++;
	}
	//β�巨
	void Insert_Back(T data){
		//�����ڵ�
		LinkNode<T>* newnode = new LinkNode<T>();
		newnode->data = data;
		newnode->next = NULL;
		//����ָ��
		LinkNode<T>* pCurrent = this->head;
		while (pCurrent->next != NULL){
			pCurrent = pCurrent->next;
		}
		pCurrent->next = newnode;
		this->length++;
	}
	//���Ӵ�ӡ
	void PrintList(PRINTNODE print){
		LinkNode<T>* pCurrent = this->head->next;
		while (pCurrent != NULL){
			//������һ���ڵ�
			print(pCurrent->data);
			pCurrent = pCurrent->next;
		}
	}
public:
	LinkNode<T> * head; //ͷ���
	int length; //������
};
#endif
