#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct teacher
{
	int id;
	char name[64];
	int age;
};

int main(void)
{
	struct teacher t1 = { 0 };
	struct teacher *tp = &t1;

	int id_offsize = 0;
	int name_offsize = 0;
	int age_offsize = 0;



	id_offsize = (int)&(((struct teacher *)0)->id);
	name_offsize = (int)&(((struct teacher *)0)->name);
	age_offsize = (int)&(((struct teacher*)0)->age);

	printf("id_offsize : %d\n", id_offsize);
	printf("name_offsize : %d\n", name_offsize);
	printf("age_offsize : %d\n", age_offsize);


	
	age_offsize = (int)&(tp->age) - (int)tp;

	printf("age_offsize : %d\n", age_offsize);

	

	return 0;
}
