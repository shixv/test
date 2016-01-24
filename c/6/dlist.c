#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

void init_list(struct node **head_p,struct node **tail_p)
{
	struct node *head;
	struct node *tail;

	if(head_p==NULL||tail_p==NULL)
		return;
	head=(struct node *)malloc(sizeof(struct node));
	head->data=0;
	head->prev=NULL;
	


}

