#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct teacher
{
	int id; //������
	struct teacher *next; //ָ����
};

//��̬����
void test1()
{
	struct teacher t1, t2, t3, t4, t5;
	struct teacher *p;
	
	//��̬���� ÿһ���ڵ���һ��ʼ�͸����Ǵ�������
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

//��̬����
void test2()
{
	struct teacher *new_node = NULL;//�´�����һ������ڵ�ָ��
	struct teacher *head = NULL;//ʼ��ָ������ͷ����  ָ��
	struct teacher *last_node = NULL; //ʼ��ָ����������һ���ڵ� �� ָ��
	struct teacher *p = NULL;
	int id = 0;

	printf("������һ����ʦ��id:");
	scanf("%d", &id);
	while (id != -1) {
		//����һ��id�������ʦ�ڵ�
		new_node = (struct teacher *)malloc(sizeof(struct teacher));
		if (new_node == NULL) {
			return;
		}
		memset(new_node, 0, sizeof(struct teacher));
		new_node->id = id;
		new_node->next = NULL;

		//����ʦ�ڵ���뵽 ������
		if (head == NULL) {
			//����Ϊ��
			head = new_node;
		}
		else {
			//����Ϊ��
			//��ʱ��last_node ����ִ�е���һ�ε�new_node Ҳ���ǵ�ǰ��������һ���ڵ�
			last_node->next = new_node;
		}


		last_node = new_node;

		//�ٴ�����һ��
		printf("������һ����ʦ��id:");
		scanf("%d", &id);
	}


	//����һ������
	for (p = head; p != NULL; p = p->next){
		printf("id = %d\n", p->id);
	}

	//��������
}

int main(void)
{
	//test1();
	test2();

	return 0;

