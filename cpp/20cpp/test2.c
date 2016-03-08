#define _CRT_SECURE_NO_WARNINGS
#include"CircleLinkList.h"


//定义数据
typedef struct _Player{
	CircleLinkNode node;
	int age;
	int num;
}Player;

//打印回调函数
void PrintNode(CircleLinkNode* data){
	Player* p = (Player*)data;
	printf("Age:%d Num:%d\n",p->age,p->num);
}

void test01(){

	//创建链表
	CircleLinkList* clist = Init_CircleLinkList();
	//创建数据
	Player p1;
	p1.age = 10;
	p1.num = 1;

	Player p2;
	p2.age = 20;
	p2.num = 2;

	Player p3;
	p3.age = 30;
	p3.num = 3;
	//插入链表中
	Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p1);
	Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p2);
	Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p3);
	//打印
	Print_CircleLinkList(clist, PrintNode);
	//删除 根据位置删除
	//RemoveByPos_CircleLinkList(clist,1);
	RemoveByValue_CircleLinkList(clist, (CircleLinkNode*)&p3);
	//打印
	Print_CircleLinkList(clist, PrintNode);
	//销毁链表
	Destroy_CircleLinkList(clist);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}