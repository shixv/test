#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct _teacher
{
	int id;
	char name[64];
}teacher_t;



struct {
	int id;
	char name[64];
} t1, t2 ; //�����������һ���ṹ�����ͣ��޷����к������Ρ�

struct teacher
{
	int id;
	char name[64];
};

struct teacher t5 = { 5, "teacher5" };


void print_teacher(struct teacher  t) //t = main::t11
{
	printf("id = %d\n", t.id);
	printf("name = %s\n", t.name);
}

void init_teacher(teacher_t *t)
{
	t->id = 6;
	strcpy(t->name, "123");
}



void copy_teacher(struct teacher to, struct teacher from)
{
	to = from; //���Ǿֲ������� ���ܸı亯����ߵ�ֵ
}

void copy_teacher2(struct teacher *to, struct teacher *from)
{
	*to = *from;
}




int main(void)
{
	teacher_t t3 = {6, "laowang"};
	struct teacher t4 = { 7, "Teacher7" };

	teacher_t t6 = { 0 };

	init_teacher(&t6);

	print_teacher(t4);


	printf("------\n");

	struct teacher t10 = { 1, "zhang3" };
	struct teacher t11 = { 0 };

	t11 = t10;

	//�ṹ���ǿ���ֱ�Ӹ�ֵ�ġ�

	//copy_teacher(t11, t10);

	copy_teacher2(&t11, &t10);

	print_teacher(t11);


	return 0;
}