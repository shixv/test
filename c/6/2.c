#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct teacher
{
	int id; //数据域
	struct teacher *next; //指针域
};

//静态链表
void test1()
{
	struct teacher t1, t2, t3, t4, t5;
	struct teacher *p;
	
	//静态链表 每一个节点在一开始就给我们创建好了
	t1.id = 1;
	t2.id = 2;
	t3.id = 3;
	t4.id = 4;
	t5.id = 5;

	t1.next = &t2;//t1->t2
	t2.next = &t3;//t1->t2->t3
	t3.next = &t4;//t1->t2->t3->t4
	t4.next = &t5;//t1->t2->t3->t4->t5
	t5.next = NULL;//t1->t2->t3->t4->t5->NULL
							                                     

	for (p = &t1; p != NULL; p = p->next) {
		printf("id:%d\n", p->id);
	}
}

//动态链表
void test2()
{
	struct teacher *new_node = NULL;//新创建的一个链表节点指针
	struct teacher *head = NULL;//始终指向链表头结点的  指针
	struct teacher *last_node = NULL; //始终指向链表的最后一个节点 的 指针
	struct teacher *p = NULL;
	int id = 0;

	printf("请输入一个老师的id:");
	scanf("%d", &id);
	while (id != -1) {
		//创建一个id对象的老师节点
		new_node = (struct teacher *)malloc(sizeof(struct teacher));
		if (new_node == NULL) {
			return;
		}
		memset(new_node, 0, sizeof(struct teacher));
		new_node->id = id;
		new_node->next = NULL;

		//将老师节点插入到 链表中
		if (head == NULL) {
			//链表为空
			head = new_node;
		}
		else {
			//链表不为空
			//此时的last_node 就是执行的上一次的new_node 也就是当前链表的最后一个节点
			last_node->next = new_node;
		}


		last_node = new_node;

		//再次输入一次
		printf("请输入一个老师的id:");
		scanf("%d", &id);
	}


	//遍历一个链表
	for (p = head; p != NULL; p = p->next){
		printf("id = %d\n", p->id);
	}

	//销毁链表
}

int main(void)
{
	//test1();
	test2();

	return 0;

