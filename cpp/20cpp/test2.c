#define _CRT_SECURE_NO_WARNINGS
#include"CircleLinkList.h"


//��������
typedef struct _Player{
	CircleLinkNode node;
	int age;
	int num;
}Player;

//��ӡ�ص�����
void PrintNode(CircleLinkNode* data){
	Player* p = (Player*)data;
	printf("Age:%d Num:%d\n",p->age,p->num);
}

void test01(){

	//��������
	CircleLinkList* clist = Init_CircleLinkList();
	//��������
	Player p1;
	p1.age = 10;
	p1.num = 1;

	Player p2;
	p2.age = 20;
	p2.num = 2;

	Player p3;
	p3.age = 30;
	p3.num = 3;
	//����������
	Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p1);
	Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p2);
	Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p3);
	//��ӡ
	Print_CircleLinkList(clist, PrintNode);
	//ɾ�� ����λ��ɾ��
	//RemoveByPos_CircleLinkList(clist,1);
	RemoveByValue_CircleLinkList(clist, (CircleLinkNode*)&p3);
	//��ӡ
	Print_CircleLinkList(clist, PrintNode);
	//��������
	Destroy_CircleLinkList(clist);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}