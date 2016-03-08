#include"LinkList.h"

//�����ʼ��
LinkList* Init_LinkList(){

	//������ṹ������ڴ�
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	if (list == NULL){
		return NULL;
	}

	//����һ��ͷ���
	LinkNode* header = (LinkNode*)malloc(sizeof(LinkNode));
	if (header == NULL){
		free(list);
		list = NULL;
		return NULL;
	}
	header->data = -1;
	header->next = NULL;

	list->head = header;
	list->length = 0;


	return list;
}
//��������
void Insert_LinkList(LinkList* list, int pos, void* data){

	if (list == NULL){
		return;
	}

	if (pos < 0){
		return;
	}

	if (pos > list->length){
		pos = list->length;
	}

	//����ָ�����
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos;i++){
		pCurrent = pCurrent->next;
	}

	//�����µĽ��
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	//�½ڵ�������
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;
	
	//���½������
	list->length++;
}
//ɾ������
void Remove_LinkList(LinkList* list, int pos){

	if (list == NULL){
		return;
	}

	if (pos < 0 || pos > list->length -1){
		return;
	}

	//��ֵָ�����
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos;i++){
		pCurrent = pCurrent->next;
	}

	//�����´�ɾ�����
	LinkNode* pDel = pCurrent->next;
	pCurrent->next = pDel->next;
	free(pDel);

	list->length--;
}
//���������
int Length_LinkList(LinkList* list){
	if (list == NULL){
		return;
	}
	return list->length;
}
//�ж��Ƿ�Ϊ��
int IsEmpty_LinkList(LinkList* list){
	
	if (list == NULL){
		return -1;
	}

	if (list->length == 0){
		return LINKLIST_TRUE;
	}

	return LINKLIST_FAlSE;
}
//�������
void Clear_LinkList(LinkList* list){

	if (list == NULL){
		return;
	}

	//����ָ�����
	LinkNode* pCurrent = list->head->next;
	while (pCurrent != NULL){
		//������һ�����λ��
		LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}
	//�ı�ͷ���ָ��
	list->head->next = NULL;
	list->length = 0;
}
//���ָ��λ�õ�����
void* Get_LinkList(LinkList* list, int pos){
	if (list == NULL){
		return NULL;
	}

	if (pos < 0 || pos > list->length - 1){
		return NULL;
	}

	//����ָ�����
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos;i++){
		pCurrent = pCurrent->next;
	}

	return pCurrent->next->data;
}
//��������
void Destroy_LinkList(LinkList* list){

	if (list == NULL){
		return;
	}
	Clear_LinkList(list); //�������
	if (list->head != NULL){
		free(list->head);
	}
	//�ͷ������ڴ�
	free(list);
}
//��ӡ����
void Print_LinkList(LinkList* list, PRINTLINKNODE print){

	if (list == NULL){
		return;
	}

	if (print == NULL){
		return;
	}

	//���� ����ָ�����
	LinkNode* pCurrent = list->head->next;
	while (pCurrent != NULL){
		print(pCurrent->data);
		pCurrent = pCurrent->next;
	}

	printf("\n------------------------\n");
}
