#ifndef hasheadlisth
#define hasheadlisth

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void init_list(struct node **head_p);

struct node *make_node(int data);

void free_node(struct node *node);

int insert_node_to_end(struct node *new_node,struct node *head);

#endif
