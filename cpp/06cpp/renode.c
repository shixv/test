#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void initnodetable(struct node **s,int n)
{
	*s=(struct node *)malloc(sizeof(struct node));
	(*s)->data=0;
	struct node *temp=*s;
	for(int i=1;i<n;i++)
	{
		temp->next=(struct node *)malloc(sizeof(struct node));
		temp=temp->next;
		temp->data=i;
		temp->next=NULL;
	}
}
struct node *renode(struct node *s,int rn)
{
	if(s==NULL)
		return NULL;
	int n=0;
	struct node *temp=s;
	while(temp!=NULL)
	{
		temp=temp->next;
		n++;
	}
	if(n<rn)
		return NULL;
	temp=s;
	for(int i=0;i<n-rn;i++)
		temp=temp->next;
	return temp;
}

int main(void)
{
	struct node *sn=NULL;
	initnodetable(&sn,10);
	struct node *temp=sn;
	for(int i=0;i<10;i++)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	struct node *ret=renode(sn,5);
	if(ret==NULL)
		printf("NULL\n");
	else
		printf("%d\n",ret->data);
	return 0;
}
