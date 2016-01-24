#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *next;
};


void deletenode(struct node **head,int data)
struct node *searchnode(struct node *head,int data)
struct node *previousnode(struct node *head,struct node *p);
void inserthead(struct node **head,struct node *insert);
int main(void)
{

	return 0;
}

void inserthead(struct node **head,struct node *insert)
{
	if(*head!=NULL){
		insert->next=*head;
		*head=insert;
	}
	else
	{
		*head=insert;
	}
}

struct node *previousnode(struct node *head,struct node *p)
{
	while(head!=NULL)
	{
		if(head->next==p)
			return head;
	}
	return NULL;
}
struct node *searchnode(struct node *head,int data)
{
	while(head!=NULL)
	{
		if(head->data==data)
			return head;
	}
	return NULL;
}
void deletenode(struct node **head,int data)
{
	struct node *p=searchnode(*head,data);
	if(p==NULL)
		return;
	if(p==*head)
	{
		*head=p->next;
		free(p);
		return;
	}
	if(p->next==NULL)
	{
		p=previousnode(*head,p);
		free(p->next);
		p->next=NULL;
	}
	p=previousnode(*head,p);
	free(p->next);
	p->next=p->next->next;
}

