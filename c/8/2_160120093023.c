#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *next;
};
int main(void)
{
	return 0;
}

struct node *previous(struct node *p,struct node *head)
{
	while(head->next!=NULL)
	{
		if(head->next==p)
			return head;
		head=head->next;
	}
	return NULL;
}
void exchange(struct node *p1,struct node *p2,struct node *head)
{
	struct node *pp1=previous(p1,head);
	struct node *pp2=previous(p2,head);
	struct node *tmp=NULL;
	tmp=pp2->next;
	pp2->next=pp1->next;
	pp1->next=tmp;

	tmp=p1->next;
	p2->next=p1->next;
	p1->next=tmp;
}
