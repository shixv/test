#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "no_head_list.h"

int main(void)
{
	int num = 10;
	int i = 0;
	struct node*head; //����ͷ�����ͷ�ڵ�ָ�롣
	struct node *new_node = NULL;

	init_list(&head);


	for (i = 0; i < num; i++) {
		new_node = make_node(i + 10);
		//��new_node ���뵽head��
		insert_node_to_end(new_node, &head);
	}

	//�������е�����
	print_list(head);
	


	return 0;
}
