#include <stdio.h>
#include <stdlib.h>

/*找到带头结点的链表的中间节点并删除。
该带头节点有n个数据节点，一个头结点。
数据节点编号从 1 2 。。。n,中间节点的编号选择为(n+1)/2
例如:3个或者4个节点都选择2号节点*/
struct node
{
	int data;
	struct node *next;
};

void deletemiddle(struct node *st);

int main(void)
{
	printf("success!!!!!");
	return 0;
}

void deletemiddle(struct node *st)
{
	int count=0;
	struct node *tmp=st;
	while(tmp!=NULL)
	{
		tmp=tmp->next;
		count++;
	}
	for(int i=0;i<count/2;i++)
		st=st->next;
	tmp=st->next;
	st->next=st->next->next;
	free(tmp);
}
