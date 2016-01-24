#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct teacher
{
	int id;
	char name[64];
};

//开辟struct teacher内存
void create_teacher(struct teacher **tpp, int num)
{
	struct teacher *p = NULL;

	p = (struct teacher *)malloc(sizeof(struct teacher) * num);
	if (p == NULL) {
		return;
	}
	memset(p, 0, sizeof(struct teacher) *num);

	*tpp = p;
}

//打印老师的接口
void print_teachers(struct teacher *tp, int num)
{
	int i = 0;

	for (i = 0; i < num; i++) {
		printf("id = %d\n", tp[i].id);
		printf("name = %s\n", tp[i].name);
		printf(" ====== \n");
	}
}

void free_teacher(struct teacher **tpp)
{
	struct teacher *tp = *tpp;

	if (tpp == NULL) {
		return;
	}

	if (tp != NULL) {
		free(tp);
		*tpp = NULL;
	}

	return;
}


int main(void)
{
	struct teacher *tp = NULL;
	int i = 0;

	create_teacher(&tp,2); //在堆上开辟了两个teacher的内存
	for (i = 0; i < 2; i++) {
		printf("enter %d's id: \n", i);
		scanf("%d", &tp[i].id);

		printf("enter %d's name\n", i);
		scanf("%s", tp[i].name);
	}

	print_teachers(tp, 2);


	free_teacher(&tp);


	return 0;
}
