#include "has_head_list.h"

void init_list(struct node **head_p)
{
	struct node *head=NULL;
	head=(struct node *)malloc(sizeof(struct node));
	if(head==NULL){
		printf("malloc head error\n");
		return NULL;
	}
	head->data=0;
	head->next=NULL;
	*head_p=head;
}

struct node *make_node(int data)
{
	struct node *new_node=NULL;
	new_node=(struct node *)malloc(sizeof(struct node));
	if(new_node==NULL){
		printf("malloc new_node %d error\n",data);
		return NULL;
	}
	memset(new_node,0,sizeof(struct node));
	new_node->data=data;
	new_node->next=NULL;
	return new_node;
}

void free_node(struct node *node)
{
	if(node!=NULL){
		free(node);
	}
}
