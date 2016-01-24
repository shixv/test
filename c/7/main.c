#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "has_head_list.h"

int main(void)
{
	struct node *head = NULL;
	struct node *new_node = NULL;
	int num = 10;
	int i = 0;

	init_list(&head); //已经有一个链表的头部 head

	//head
	for (i = 0; i < num; i++) {
		new_node = make_node(i + 10);
		insert_node_to_head(new_node,head);		

	}

	print_list(head);
	

	return 0;
}
