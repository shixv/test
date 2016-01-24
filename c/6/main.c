#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "no_head_list.h"

int main(void)
{
	int num = 10;
	int i = 0;
	struct node*head; //是无头链表的头节点指针。
	struct node *new_node = NULL;

	init_list(&head);


	for (i = 0; i < num; i++) {
		new_node = make_node(i + 10);
		//将new_node 插入到head中
		insert_node_to_end(new_node, &head);
	}

	//遍历所有的链表
	print_list(head);
	


	return 0;
}
