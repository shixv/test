#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct teacher 
{
	int id;
	struct teacher *next;
};

void freenode(struct teacher *p)
{
	while(p!=NULL)
	{
		free(p);
		p=p->next;
	}
	printf("already free\n");
}
void test1()
{
	struct teacher t1,t2,t3,t4,t5;
	struct teacher *p;

	t1.id=1;
	t2.id=2;
	t3.id=3;
	t4.id=4;
	t5.id=5;
	
	t1.next=&t2;
	t2.next=&t3;
	t3.next=&t4;
	t4.next=&t5;
	t5.next=NULL;

	for(p=&t1;p!=NULL;p=p->next){
		printf("id:%d\n",p->id);
	}

}
void test2()
{
	struct teacher *new_node=NULL;
	struct teacher *head=NULL;
	struct teacher *last_node=NULL;
	struct teacher *p=NULL;
	int id=0;
	printf("input id:");
	scanf("%d",&id);
	while(id!=-1){
		new_node=(struct teacher *)malloc(sizeof(struct teacher));
		if(new_node==NULL){
			return;
		}
		memset(new_node,0,sizeof(struct teacher));
		new_node->id=id;
		new_node->next=NULL;
		if(head==NULL){
			head=new_node;
		}
		else{
			last_node->next=new_node;
		}
		last_node=new_node;
		printf("input id:");
		scanf("%d",&id);
	}

	for(p=head;p!=NULL;p=p->next){
		printf("id=%d\n",p->id);
	}
	freenode(head);
}

int main(void)
{
	test1();
	test2();
	return 0;
}
