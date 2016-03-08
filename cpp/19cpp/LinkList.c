#include"LinkList.h"

//链表初始化
LinkList* Init_LinkList(){

	//给链表结构体分配内存
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	if (list == NULL){
		return NULL;
	}

	//创建一个头结点
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
//插入数据
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

	//辅助指针变量
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos;i++){
		pCurrent = pCurrent->next;
	}

	//创建新的结点
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	//新节点入链表
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;
	
	//更新结点数量
	list->length++;
}
//删除数据
void Remove_LinkList(LinkList* list, int pos){

	if (list == NULL){
		return;
	}

	if (pos < 0 || pos > list->length -1){
		return;
	}

	//赋值指针变量
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos;i++){
		pCurrent = pCurrent->next;
	}

	//缓存下待删除结点
	LinkNode* pDel = pCurrent->next;
	pCurrent->next = pDel->next;
	free(pDel);

	list->length--;
}
//获得链表长度
int Length_LinkList(LinkList* list){
	if (list == NULL){
		return;
	}
	return list->length;
}
//判断是否为空
int IsEmpty_LinkList(LinkList* list){
	
	if (list == NULL){
		return -1;
	}

	if (list->length == 0){
		return LINKLIST_TRUE;
	}

	return LINKLIST_FAlSE;
}
//清空链表
void Clear_LinkList(LinkList* list){

	if (list == NULL){
		return;
	}

	//辅助指针变量
	LinkNode* pCurrent = list->head->next;
	while (pCurrent != NULL){
		//缓存下一个结点位置
		LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}
	//改变头结点指向
	list->head->next = NULL;
	list->length = 0;
}
//获得指定位置的数据
void* Get_LinkList(LinkList* list, int pos){
	if (list == NULL){
		return NULL;
	}

	if (pos < 0 || pos > list->length - 1){
		return NULL;
	}

	//辅助指针变量
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos;i++){
		pCurrent = pCurrent->next;
	}

	return pCurrent->next->data;
}
//销毁链表
void Destroy_LinkList(LinkList* list){

	if (list == NULL){
		return;
	}
	Clear_LinkList(list); //清空链表
	if (list->head != NULL){
		free(list->head);
	}
	//释放链表内存
	free(list);
}
//打印函数
void Print_LinkList(LinkList* list, PRINTLINKNODE print){

	if (list == NULL){
		return;
	}

	if (print == NULL){
		return;
	}

	//遍历 辅助指针变量
	LinkNode* pCurrent = list->head->next;
	while (pCurrent != NULL){
		print(pCurrent->data);
		pCurrent = pCurrent->next;
	}

	printf("\n------------------------\n");
}
