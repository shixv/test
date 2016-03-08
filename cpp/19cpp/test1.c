#include "linklist.h"
#include <stdio.h>
typedef struct _Player{
	char name[128];
	int age;
	double salary;
}Player;
void PrintListNode(void* data){
	Player* p=(Player*)data;
	printf("name:%s age: %d Salary: %f \n",p->name,p->age,p->salary);
}
void test01(){
	LinkList* list=Init_LinkList();
	Player p1={"aaa",10,2};
	Player p2={"bbb",20,3};
	Player p3={"ccc",30,4};
	Player p4={"ddd",40,5};

	Insert_LinkList(list,0,&p1);
	Insert_LinkList(list,0,&p2);
	Insert_LinkList(list,0,&p3);
	Insert_LinkList(list,0,&p4);


	Print_LinkList(list,PrintListNode);
	Remove_LinkList(list,2);
	Print_LinkList(list,PrintListNode);
	Destroy_LinkList(list);
}
int main(void)
{
	test01();
	return 0;
}
