#include"LinkList.h"
LinkList* Init_LinkList()
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	if (list == NULL)
	{
		return NULL;
	}
	LinkNode* header = (LinkNode*)malloc(sizeof(LinkNode));
	if (header == NULL)
	{
		free(list);
		list = NULL;
		return list;
	}
	header->data = 0;
	header->next = NULL;
	list->head = header;
	list->length = 0;
	return list;
}
void* Insert_LinkList(LinkList* list, int pos, void* data)
{
	if (list == NULL)
	{
		return NULL;
	}
	if (pos < 0)
	{
		return NULL;
	}
	if (pos > 0)
	{
		pos = list->length;
	}
	LinkNode* pCurrent = (LinkNode*)malloc(sizeof(LinkNode));
	if (pCurrent == NULL)
	{
		return NULL;
	}
	for (int i = 0; i < list->length; i++)
	{
		pCurrent = pCurrent->next;
	}
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	if (newnode == NULL)
	{
		return NULL;
	}
	newnode->data = data;
	newnode->next = NULL;
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;
	list->length++;
	return list;
}
//ɾ��ָ��λ������
void DeleteByPos_LinkList(LinkList* list, int pos)
{
	if (list == NULL)
	{
		return;
	}
	if (pos < 0 || pos>list->length)
	{
		return;
	}
	LinkNode* pCurrent = (LinkNode*)malloc(sizeof(LinkNode));
	if (pCurrent == NULL)
	{
		return;
	}
	for (int i = 0; i < list->length; i++)
	{
		pCurrent = pCurrent->next;
	}
	LinkNode* pDel = pCurrent->next; 
	pCurrent->next = pDel->next;
	free(pDel);
	list->length--;
}
//���������
int Length_LinkList(LinkList* list)
{
	if (list == NULL)
	{
		return 0;
	}
	return list->length;
}
//�ж��Ƿ�Ϊ��
int IsEmpty_LinkList(LinkList* list)
{
	if (list == NULL)
	{
		return -1;
	}
	if (list->length == 0)
	{
		return 0;
	}
	return 1;
}
//�������
void Clear_LinkList(LinkList* list)
{
	if (list == NULL)
	{
		return;
	}
	LinkNode* pCurrent = list->head->next;
	while (pCurrent != NULL)
	{
		LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}
	list->head->next = NULL;
	list->length--;
}
//���ָ��λ�õ�����
void* GetDataByPos_LinkList(LinkList* list, int pos)
{
	if (list == NULL)
	{
		return NULL;
	}
	if (pos < 0 || pos > list->length)
	{
		return NULL;
	}
	LinkNode* pCurrent = (LinkNode*)malloc(sizeof(LinkNode));
	for (int i = 0; i < list->length; i++)
	{
		pCurrent = pCurrent->next;
	}
	return pCurrent->data;
}
//��������
void Destroy_LinkList(LinkList* list)
{
	if (list == NULL)
	{
		return;
	}
	Clear_LinkList(list);
	if (list->head != NULL)
	{
		free(list->head);
	}
	free(list);
}
//��ӡ����
void Print_LinkList(LinkList* list, PRINTNODE print)
{
	if (list == NULL)
	{
		return;
	}
	if (print == NULL)
	{
		return;
	}
	LinkNode* pCurrent = list->head->next;
	for (int i = 0; i < list->length; i++)
	{
		print(pCurrent->data);
		pCurrent = pCurrent->next;
	}
	printf("----------------\n");
}
