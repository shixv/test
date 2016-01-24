#include "no_head_list.h"


//初始化一个链表
void init_list(struct node **head_p)
{
	*head_p = NULL;
	printf("初始化的链表\n");
}


//创建一个新节点的 接口
struct node *make_node(int data)
{
	struct node *new_node = NULL;

	//开辟了一个节点的空间
	new_node = (struct node *)malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("malloc new_node :%d error\n", data);
		return NULL;
	}
	memset(new_node, 0, sizeof(struct node));


	new_node->data = data;
	new_node->next = NULL;


	return new_node;
}

//释放一个节点的接口
void free_node(struct node *node)
{
	if (node != NULL) {
		free(node);
	}
}

//从尾部插入一个新节点 到head中
int insert_node_to_end(struct node *new_node, struct node **head_p)
{
	struct node *head = NULL;
	struct node *last_node = NULL;

	if (new_node == NULL || head_p == NULL) {
		printf("(new_node == NULL || head_p == NULL)\n");
		return -1;
	}

	head = *head_p;

	if (head == NULL) {
		//当head为空
		//让head指针直接指向新节点
		head = new_node;

	}
	else {
		//当head不为空
		//找到最后一个节点的指针。
		for (last_node = head; last_node->next != NULL; last_node = last_node->next) {

		}
		//让最后一个节点的next 等于new_node
		last_node->next = new_node;
	}

	*head_p = head;

	return 0;
}



//遍历一个链表
void print_list(struct node *head)
{
	struct node *p = NULL;

	for (p = head; p != NULL; p = p->next) {
		printf("%d\n", p->data);
	}
}
