#include"CircleLinkList.h"

//��ʼ������
CircleLinkList* Init_CircleLinkList(){
	
	//���������ڴ�
	CircleLinkList* clist = (CircleLinkList*)malloc(sizeof(CircleLinkList));
	if (clist == NULL){
		return NULL;
	}

	clist->header.next = NULL;
	clist->length = 0;

	return clist;
}
//��������
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data){
	
	if (clist == NULL){
		return;
	}
	if (pos < 0){
		return;
	}
	if (pos > clist->length){
		pos = clist->length;
	}
	if (data == NULL){
		return;
	}

	//��λ�� ����ָ�����
	CircleLinkNode* pCurrent = &(clist->header);
	for (int i = 0; i < pos;i ++){
		pCurrent = pCurrent->next;
	}

	//�����������
	data->next = pCurrent->next;
	pCurrent->next = data;

	//�ж��Ƿ���뵽β��
	if (pos == clist->length){
		data->next = &(clist->header);
	}

	clist->length++;
}
//ɾ�� ����λ��ɾ��
void RemoveByPos_CircleLinkList(CircleLinkList* clist, int pos){


	if (clist == NULL){
		return;
	}

	if (pos < 0 || pos > clist->length - 1){
		return;
	}

	//��λ�� ����ָ�����
	CircleLinkNode* pCurrent = &(clist->header);
	for (int i = 0; i < pos;i++){
		pCurrent = pCurrent->next;
	}

	//�����´�ɾ���Ľ��
	CircleLinkNode* pDel = pCurrent->next;

	pCurrent->next = pDel->next;

	clist->length--;
}
//ɾ�� ����ֵɾ��(����)
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data){

	if (clist == NULL){
		return;
	}

	if (data == NULL){
		return;
	}

	//����ָ�����
	CircleLinkNode* pPrev = &(clist->header);
	CircleLinkNode* pCurrent = pPrev->next;
	int flag = 0;
	for (int i = 0; i < clist->length; i ++){
		
		if (pCurrent == data){
			flag = 1;
			break;
		}

		pPrev = pCurrent;
		pCurrent = pPrev->next;
	}

	//��ʾ�ҵ���
	if (flag == 1){
		pPrev->next = pCurrent->next;
		clist->length--;
	}

}
//��ȡ����
int Length_CircleLinkList(CircleLinkList* clist){

	if (clist == NULL){
		return NULL;
	}
	return clist->length;
}
//����ֵ�޸�
void Modify_CircleLinkList(CircleLinkList* clist, CircleLinkNode* oldvalue, CircleLinkNode* newvalue){

	if (clist == NULL || oldvalue == NULL || newvalue == NULL){
		return;
	}

	//����ָ��
	CircleLinkNode* pPrev = &(clist->header);
	CircleLinkNode* pCurrent = pPrev->next;
	for (int i = 0; i < clist->length; i ++){
		if (pCurrent == oldvalue){
			//�޸�newvalue��nextָ��ָ��
			newvalue->next = pCurrent->next;
			pPrev->next = newvalue;
			break;
		}
		pPrev = pCurrent;
		pCurrent = pPrev->next;
	}
}
//�������
void Clear_CircleLinkList(CircleLinkList* clist){

	if (clist == NULL){
		return;
	}

	clist->header.next = NULL;
	clist->length = 0;
}
//����λ�÷�������
CircleLinkNode* GetByPos_CircleLinkList(CircleLinkList* clist, int pos){

	if (clist == NULL){
		return NULL;
	}
	if (pos < 0 || pos > clist->length - 1){
		return NULL;
	}
	//����ָ�����
	CircleLinkNode* pCurrent = &(clist->header);
	for (int i = 0; i < pos; i++){
		pCurrent = pCurrent->next;
	}

	return pCurrent->next;
}
//����
void Destroy_CircleLinkList(CircleLinkList* clist){

	if (clist == NULL){
		return;
	}
	
	free(clist);
}
//��ӡ
void Print_CircleLinkList(CircleLinkList* clist, PRINTLINKNODE print){

	if (clist == NULL){
		return;
	}
	if (print == NULL){
		return;
	}

	//����ָ�����
	CircleLinkNode* pCurrent = clist->header.next;
	for (int i = 0; i < clist->length ; i ++){
		print(pCurrent);
		pCurrent = pCurrent->next;
		//�ж��Ƿ�Ϊͷ��㣬�����ͷ�����������ͷ���
		if (pCurrent == &(clist->header)){
			pCurrent = pCurrent->next;
		}
	}

	printf("-----------------------\n");


}