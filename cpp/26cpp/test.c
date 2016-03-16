#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"
typedef struct _Player
{
	char name[64];
	int age;
	double salary;
}Player;
void PrintLinkNode(void* data)
{
	Player* p = (Player*)data;
	printf("Name:%s Age:%d Salary:%f \n", p->name, p->age, p->salary);
}
void test()
{
	LinkList* list = Init_LinkList();
	Player p1 = { "aa", 18, 4000 };
	Player p2 = { "bb", 22, 14000 };
	Player p3 = { "cc", 28, 20000 };
	Player p4 = { "dd", 32, 40000 };
	Insert_LinkList(list, 0, (void*)&p1);
	Insert_LinkList(list, 0, (void*)&p2);
	Insert_LinkList(list, 0, (void*)&p3);
	Insert_LinkList(list, 0, (void*)&p4);
	Print_LinkList(list, PrintLinkNode);
}
int main()
{
	test();
	return 0;
}