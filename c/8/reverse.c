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

int reverse(struct node *head)
{
	struct node *p=NULL;
	struct node *p_prev=NULL;
	struct node *p_next=NULL;

	p_prev=head;
	p=p_prev->next;
	while(p!=NULL)
	{
		p_next=p->next;
		p->next=p_prev;
		p_prev=p;
		p=p_next;
	}
	head->next->next=NULL;
	head->next=p_prev;
	return 0;
}

