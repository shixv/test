#define _CRT_SECURE_NO_WARNINGS
#include"SeqStack.h"
//�Զ�������
typedef struct _Player{
	char name[128];
	int age;
}Player;
void test01(){
	//����ջ
	SeqStack* stack = Init_SeqStack();
	//��������
	Player p1 = { "aaa", 10 };
	Player p2 = { "bbb", 20 };
	Player p3 = { "ccc", 30 };
	//������ջ
	Push_SeqStack(stack, (void*)&p1);
	Push_SeqStack(stack, (void*)&p2);
	Push_SeqStack(stack, (void*)&p3);
	//��ӡ
	while (Length_SeqStack(stack) > 0){
		Player* p = (Player*)Top_SeqStack(stack);
		Pop_SeqStack(stack);
		printf("Name:%s Age:%d\n",p->name,p->age);
	}
	//����
	Destroy_SeqStack(&stack);
}
int main(){
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
