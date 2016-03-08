#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"LinkList.h"


//自定义数据
typedef struct _Player{
	char name[128];
	int age;
	double salary;
}Player;

//打印回调
void PrintListNode(void* data){
	Player* p = (Player*)data;
	printf("Name:%s Age:%d Salary:%f \n",p->name,p->age,p->salary);
}

void test01(){

	//初始化创建一个链表
	LinkList* list = Init_LinkList();
	//创建数据
	Player p1 = { "aaa", 10, 2 };
	Player p2 = { "bbb", 20, 3 };
	Player p3 = { "ccc", 30, 4 };
	Player p4 = { "ddd", 40, 5 };
	//插入数据
	Insert_LinkList(list, 100, &p1);
	Insert_LinkList(list, 200, &p2);
	Insert_LinkList(list, 300, &p3);
	Insert_LinkList(list, 5000, &p4);
	//打印
	Print_LinkList(list, PrintListNode);
	//删除
	Remove_LinkList(list,2);
	//打印
	Print_LinkList(list, PrintListNode);
	//销毁
	Destroy_LinkList(list);

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}