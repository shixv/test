#include <stdio.h>

typedef struct
{
	int id;
	char name[64];
}teacher;

void cp_teacher(teacher *to,teacher *from)
{
	*to=*from;
}
int main(void)
{
	teacher t1={
		12,
		"shixv"
	};
	teacher t2={
		0
	};
	cp_teacher(&t2,&t1);
	printf("%d,%s\n",t2.id,t2.name);
	return 0;
}
