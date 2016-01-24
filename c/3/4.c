#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define NAME_LEN (64)

//�ṹ��Ƕ��һ��ָ��
struct teacher
{
	int id;
	char *name;
};

void  create_teachers(struct teacher **tpp, int num)
{
	struct teacher *tp = NULL;
	int i = 0;

	//�����ǿ��� ��ʦ�ṹ��Ŀռ�
	tp = (struct teacher *)malloc(sizeof(struct teacher) * num);
	if (tp == NULL) {
		return;
	}
	memset(tp, 0, sizeof(struct teacher)*num);


	//������Ϊÿ����ʦ���ٴ��name�Ŀռ�
	for (i = 0; i < num; i++) {
		tp[i].name = (char*)malloc(sizeof(char)*NAME_LEN);
		if (tp[i].name == NULL) {
			return;
		}
		memset(tp[i].name, 0, sizeof(char)*NAME_LEN);
	}

	*tpp = tp;
}
void free_teachers(struct teacher *tpp,int num)
{
	for(int i=0;i<num;i++){
		free(tpp[i].name);
	}
	free(tpp);
}

void sort_teachers(struct teacher *tp, int num)
{
	int i = 0;
	int j = 0;

	struct teacher temp;

	for (i = 0; i < num; i++) {
		for (j = i; j < num; j++) {
			if (tp[i].id > tp[j].id) {
				temp = tp[i];
				tp[i] = tp[j];
				tp[j] = temp;
			}
		}
	}
}

void print_teacher(struct teacher *tp, int num)
{
	int i = 0;
	printf("====== \n");
	for (i = 0; i < num; i++) {
		printf("id = %d\n", tp[i].id);
		printf("name = %s\n", tp[i].name);
		printf("====== \n");
	}
}


int main(void)
{
	struct teacher *tp = NULL;
	int num = 2;
	int i = 0;

	//��tp��ʦ���鿪�ٿռ�
	create_teachers(&tp, num);
	for (i = 0; i < num; i++) {
		printf("enter %d's  id:\n", i);
		scanf("%d", &tp[i].id);
		printf("enter %d's name:\n", i);
		scanf("%s", tp[i].name);
	}


	sort_teachers(tp, num);


	print_teacher(tp, num);


	return 0;
}
