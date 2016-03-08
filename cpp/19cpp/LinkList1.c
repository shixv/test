#include"LinkList.h"


//��ʼ������
LinkList* Init_LinkList(){

	//������Ľṹ������ڴ�
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	if (list == NULL){
		return NULL;
	}

	list->header.next = NULL;
	list->length = 0;

	return list;
}
//�������
void Insert_LinkList(LinkList* list, int pos, LinkNode* data){

	if (list == NULL){
		return;
	}

	if (pos < 0 || pos > list->length - 1){
		return;
	}

	if (data == NULL){
		return;
	}

	//��λ��
	LinkNode* pCurrent = &(list->header);
	for (int i = 0; i < pos;i ++){
		pCurrent = pCurrent->next;
	}

	//���������
	data->next = pCurrent->next;
	pCurrent->next = data;

	list->length++;
}
//ɾ������
void Remove_LinkList(LinkList* list, int pos){

}
//�������
void Clear_LinkList(LinkList* list){

}
//��������
void Destroy_LinkList(LinkList* list){

}
//��ӡ����
void Print_LinkList(LinkList* list, PRINTNODE print){

}