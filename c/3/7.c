#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LEN (64)

struct teacher
{
	int id;
	char *name;
	char **student_name;
	int student_num;
};

//开辟一个老师数组
void create_teachers(struct teacher **tpp, int num)
{
	struct teacher *tp = NULL;
	int i = 0;

	tp = (struct teacher *)malloc(sizeof(struct teacher)*num);
	if (tp == NULL) {
		return;
	}
	memset(tp, 0, sizeof(struct teacher) *num);

	//给老师的name开辟空间
	for (i = 0; i < num; i++) {
		tp[i].name = (char*)malloc(NAME_LEN);
		memset(tp[i].name, 0, NAME_LEN);
	}

	*tpp = tp;
	return;
}

//给一个老师 开辟学生的信息
void create_student(struct teacher *tp)
{
	int  i = 0;

	if (tp == NULL) {
		return;
	}

	//开辟存放学生姓名字符串首地址的 指针数组
	tp->student_name = (char**)malloc(sizeof(char*)* tp->student_num);
	if (tp->student_name == NULL) {
		return;
	}
	memset(tp->student_name, 0, sizeof(char *)*tp->student_num);

	for (i = 0; i < tp->student_num; i++) {
		//代表一个学生
		tp->student_name[i] = (char*)malloc(sizeof(char)* NAME_LEN);
		memset(tp->student_name[i], 0, sizeof(char)*NAME_LEN);
	}
	
}

void print_teacher(struct teacher *tp, int num)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < num; i++) {
		//代表一个老师
		printf(" ===== \n");
		printf("id : %d\n", tp[i].id);
		printf("name : %s\n", tp[i].name);
		printf("stu_num: %d\n", tp[i].student_num);
		for (j = 0; j < tp[i].student_num; j++) {
			//代表一个学生
			printf("stu[%d]: %s\n", j, tp[i].student_name[j]);
		}
	}
}

int main(void)
{
	struct teacher *tp = NULL;
	int i = 0;
	int j = 0;
	int tp_num = 2;

	//开辟老师数组的空间
	create_teachers(&tp, tp_num);

	//给老师赋值
	for (i = 0; i < tp_num; i++) {
		//给一个老师进行赋值
		printf("enter tp[%d]'s id:\n", i);
		scanf("%d", &tp[i].id);
		printf("enter tp[%d]'s name:\n", i);
		scanf("%s", tp[i].name);
		printf("enter tp[%d]'s std_num:\n", i);
		scanf("%d", &tp[i].student_num);

		create_student(&tp[i]); //给一个老师开辟学生姓名的空间
		//需要给每一个学生赋值
		for (j = 0; j < tp[i].student_num; j++) {
			//代表一个学生
			printf("enter tp[%d]->std[%d]'s name: ", i, j);
			scanf("%s", tp[i].student_name[j]);
		}
	}


	print_teacher(tp, tp_num);

	//根据老师的id排序

	//打印老师数组


	return 0;
}
