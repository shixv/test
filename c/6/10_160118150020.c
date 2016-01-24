#include <stdio.h>
#include <stdlib.h>

void insertnodetotail(struct node *head,struct node *new)
{
	while(head->next!=NULL)
	{
		head=head->next;
	}
	head->next=new;
	new->next=NULL;
}
