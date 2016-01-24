#include "has_head_list.h"


//��ʼ������
void init_list(struct node **head_p)
{
	//��Ҫ��������һ��ͷ�ڵ�
	struct node *head = NULL;

	head = (struct node *)malloc(sizeof(struct node));
	if (head == NULL) {
		printf("malloc head error\n");
		return;
	}

	head->data = 0; //������
	head->next = NULL;

	*head_p = head;
}

//����һ������Ľڵ�
struct node *make_node(int data)
{
	struct node *new_node = NULL;

	new_node = (struct node*)malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("malloc new_node %d error\n", data);
		return NULL;
	}
	memset(new_node, 0, sizeof(struct node));

	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

//����һ���ڵ�
void free_node(struct node *node)
{
	if (node != NULL) {
		free(node);
	}
}
void inset_node_to_end(struct node *new_node,struct node *head)
{
	if(new_node==NULL||head==NULL)
		return;
	struct node *last_node=NULL;
	for(last_node=head;last_node->next!=NULL;last_node=last_node->next);
	last_node->next=new_node;
	new_node->next=NULL;
}
void print_list(struct node *head)
{
	head=head->next;
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}
void insert_node_to_head(struct node *new_node,struct node *head)
{
	new_node=head->next->next;
	head->next=new_node;
}
void free_node(struct **head)
{
	struct node *p=*head;
	while((*head)->next!=NULL)
	{
		p=*head;
		*head=(*head)->next;
		free(p);
	}
	free(*head);
	*head=NULL;
}
