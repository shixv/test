#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "has_head_list.h"

int main(void)
{
	struct node *head=NULL;
	struct node *new_node=NULL;
	int num=10;
	int i=0;

	init_list(&head);
	for(i=0;i<num;i++){
		new_node=make_node(i+10);
	}
	return 0;
}
