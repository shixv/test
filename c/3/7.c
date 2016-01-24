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

//����һ����ʦ����
void create_teachers(struct teacher **tpp, int num)
{
	struct teacher *tp = NULL;
	int i = 0;

	tp = (struct teacher *)malloc(sizeof(struct teacher)*num);
	if (tp == NULL) {
		return;
	}
	memset(tp, 0, sizeof(struct teacher) *num);

	//����ʦ��name���ٿռ�
	for (i = 0; i < num; i++) {
		tp[i].name = (char*)malloc(NAME_LEN);
		memset(tp[i].name, 0, NAME_LEN);
	}

	*tpp = tp;
	return;
}

//��һ����ʦ ����ѧ������Ϣ
void create_student(struct teacher *tp)
{
	int  i = 0;

	if (tp == NULL) {
		return;
	}

	//���ٴ��ѧ�������ַ����׵�ַ�� ָ������
	tp->student_name = (char**)malloc(sizeof(char*)* tp->student_num);
	if (tp->student_name == NULL) {
		return;
	}
	memset(tp->student_name, 0, sizeof(char *)*tp->student_num);

	for (i = 0; i < tp->student_num; i++) {
		//����һ��ѧ��
		tp->student_name[i] = (char*)malloc(sizeof(char)* NAME_LEN);
		memset(tp->student_name[i], 0, sizeof(char)*NAME_LEN);
	}
	
}

void print_teacher(struct teacher *tp, int num)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < num; i++) {
		//����һ����ʦ
		printf(" ===== \n");
		printf("id : %d\n", tp[i].id);
		printf("name : %s\n", tp[i].name);
		printf("stu_num: %d\n", tp[i].student_num);
		for (j = 0; j < tp[i].student_num; j++) {
			//����һ��ѧ��
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

	//������ʦ����Ŀռ�
	create_teachers(&tp, tp_num);

	//����ʦ��ֵ
	for (i = 0; i < tp_num; i++) {
		//��һ����ʦ���и�ֵ
		printf("enter tp[%d]'s id:\n", i);
		scanf("%d", &tp[i].id);
		printf("enter tp[%d]'s name:\n", i);
		scanf("%s", tp[i].name);
		printf("enter tp[%d]'s std_num:\n", i);
		scanf("%d", &tp[i].student_num);

		create_student(&tp[i]); //��һ����ʦ����ѧ�������Ŀռ�
		//��Ҫ��ÿһ��ѧ����ֵ
		for (j = 0; j < tp[i].student_num; j++) {
			//����һ��ѧ��
			printf("enter tp[%d]->std[%d]'s name: ", i, j);
			scanf("%s", tp[i].student_name[j]);
		}
	}


	print_teacher(tp, tp_num);

	//������ʦ��id����

	//��ӡ��ʦ����


	return 0;
}
