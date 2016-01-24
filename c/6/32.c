#include "no_head_list.h"

void init_list(struct node **head_p)
{
	*head_p=NULL;
	printf("init node\n");
}

struct node *make_node(int data)
{
	struct node *new_node=NULL;
	new_node=(struct node *)malloc(sizeof(struct node));
	if(new_node==NULL){
		printf("malloc new_node :%d error\n",data);
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
int insert_node_to_end(struct node *new_node,struct node **head_p)
{
	struct node *head=NULL;
	struct node *last_node=NULL;
	if(new_node==NULL||head_p==NULL){
		printf("(new_node==NULL||head_p==NULL)\n");
		return -1;
	}
	head=*head_p;
	if(head==NULL){
		head=new_node;
	}
	else{
		for(last_node=head;last_node->next!=NULL;last_node=last_node->next){
	}
		last_node->next=new_node;
	}
	*head_p=head;
	return 0;
}

void print_list(struct node *head)
{
	struct node *p=NULL;
	for(p=head;p!=NULL;p=p->next){
		printf("%d\n",p->data);
	}
}
