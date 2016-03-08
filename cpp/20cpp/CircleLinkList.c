#include"CircleLinkList.h"

//初始化链表
CircleLinkList* Init_CircleLinkList(){
	
	//给链表开辟内存
	CircleLinkList* clist = (CircleLinkList*)malloc(sizeof(CircleLinkList));
	if (clist == NULL){
		return NULL;
	}

	clist->header.next = NULL;
	clist->length = 0;

	return clist;
}
//插入数据
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

	//找位置 辅助指针变量
	CircleLinkNode* pCurrent = &(clist->header);
	for (int i = 0; i < pos;i ++){
		pCurrent = pCurrent->next;
	}

	//将结点入链表
	data->next = pCurrent->next;
	pCurrent->next = data;

	//判断是否插入到尾部
	if (pos == clist->length){
		data->next = &(clist->header);
	}

	clist->length++;
}
//删除 根据位置删除
void RemoveByPos_CircleLinkList(CircleLinkList* clist, int pos){


	if (clist == NULL){
		return;
	}

	if (pos < 0 || pos > clist->length - 1){
		return;
	}

	//找位置 辅助指针变量
	CircleLinkNode* pCurrent = &(clist->header);
	for (int i = 0; i < pos;i++){
		pCurrent = pCurrent->next;
	}

	//缓存下待删除的结点
	CircleLinkNode* pDel = pCurrent->next;

	pCurrent->next = pDel->next;

	clist->length--;
}
//删除 根据值删除(新增)
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data){

	if (clist == NULL){
		return;
	}

	if (data == NULL){
		return;
	}

	//辅助指针变量
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

	//表示找到了
	if (flag == 1){
		pPrev->next = pCurrent->next;
		clist->length--;
	}

}
//获取长度
int Length_CircleLinkList(CircleLinkList* clist){

	if (clist == NULL){
		return NULL;
	}
	return clist->length;
}
//根据值修改
void Modify_CircleLinkList(CircleLinkList* clist, CircleLinkNode* oldvalue, CircleLinkNode* newvalue){

	if (clist == NULL || oldvalue == NULL || newvalue == NULL){
		return;
	}

	//辅助指针
	CircleLinkNode* pPrev = &(clist->header);
	CircleLinkNode* pCurrent = pPrev->next;
	for (int i = 0; i < clist->length; i ++){
		if (pCurrent == oldvalue){
			//修改newvalue的next指针指向
			newvalue->next = pCurrent->next;
			pPrev->next = newvalue;
			break;
		}
		pPrev = pCurrent;
		pCurrent = pPrev->next;
	}
}
//清空链表
void Clear_CircleLinkList(CircleLinkList* clist){

	if (clist == NULL){
		return;
	}

	clist->header.next = NULL;
	clist->length = 0;
}
//根据位置返回数据
CircleLinkNode* GetByPos_CircleLinkList(CircleLinkList* clist, int pos){

	if (clist == NULL){
		return NULL;
	}
	if (pos < 0 || pos > clist->length - 1){
		return NULL;
	}
	//辅助指针变量
	CircleLinkNode* pCurrent = &(clist->header);
	for (int i = 0; i < pos; i++){
		pCurrent = pCurrent->next;
	}

	return pCurrent->next;
}
//销毁
void Destroy_CircleLinkList(CircleLinkList* clist){

	if (clist == NULL){
		return;
	}
	
	free(clist);
}
//打印
void Print_CircleLinkList(CircleLinkList* clist, PRINTLINKNODE print){

	if (clist == NULL){
		return;
	}
	if (print == NULL){
		return;
	}

	//辅助指针变量
	CircleLinkNode* pCurrent = clist->header.next;
	for (int i = 0; i < clist->length ; i ++){
		print(pCurrent);
		pCurrent = pCurrent->next;
		//判断是否为头结点，如果是头结点就跳过这个头结点
		if (pCurrent == &(clist->header)){
			pCurrent = pCurrent->next;
		}
	}

	printf("-----------------------\n");


}