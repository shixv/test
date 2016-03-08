#include"LinkList.h"


//初始化链表
LinkList* Init_LinkList(){

	//给链表的结构体分配内存
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	if (list == NULL){
		return NULL;
	}

	list->header.next = NULL;
	list->length = 0;

	return list;
}
//插入操作
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

	//找位置
	LinkNode* pCurrent = &(list->header);
	for (int i = 0; i < pos;i ++){
		pCurrent = pCurrent->next;
	}

	//结点入链表
	data->next = pCurrent->next;
	pCurrent->next = data;

	list->length++;
}
//删除操作
void Remove_LinkList(LinkList* list, int pos){

}
//清空链表
void Clear_LinkList(LinkList* list){

}
//销毁链表
void Destroy_LinkList(LinkList* list){

}
//打印链表
void Print_LinkList(LinkList* list, PRINTNODE print){

}