#ifndef __HAS_HEAD_LIST_H__
#define __HAS_HEAD_LIST_H__

#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node
{
	int data; //数据域
	struct node *next; //指针域
};


//初始化链表
void init_list(struct node **head_p);

//创建一个链表的节点
struct node *make_node(int data);

//销毁一个节点
void free_node(struct node *node);

//插入到有头节点链表的尾部
void insert_node_to_end(struct node *new_node, struct node *head);
void insert_node_to_head(struct node *new_node,struct node *head);

void print_list(struct node *head);
#endif
