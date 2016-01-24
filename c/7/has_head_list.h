#ifndef __HAS_HEAD_LIST_H__
#define __HAS_HEAD_LIST_H__

#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node
{
	int data; //������
	struct node *next; //ָ����
};


//��ʼ������
void init_list(struct node **head_p);

//����һ������Ľڵ�
struct node *make_node(int data);

//����һ���ڵ�
void free_node(struct node *node);

//���뵽��ͷ�ڵ������β��
void insert_node_to_end(struct node *new_node, struct node *head);
void insert_node_to_head(struct node *new_node,struct node *head);

void print_list(struct node *head);
#endif
