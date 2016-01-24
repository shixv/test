#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct student
{
	char name[20];
	int age;
};

int input()
{
	FILE *p = fopen("b.dat", "ab");
	if (!p)
		return 0;
	while(1)
	{
		struct student st = { 0 };
		printf("please input name:");
		scanf("%s", st.name);
		printf("please input age:");
		scanf("%d", &st.age);
		if (st.age < 0)
			break;
		fwrite(&st, sizeof(struct student), 1, p);
	}
	fclose(p);
	return 0;
}

int myselect()
{
	FILE *p = fopen("b.dat", "rb");
	if (!p)
		return 0;
	char a[100] = { 0 };
	printf("please input name:");
	scanf("%s", a);    
	int status = 0;//0代表没找到，1代表找到了
	while(1)
	{
		struct student st = { 0 };
		int rc = fread(&st, sizeof(struct student), 1, p);
		if (rc == 0)//到了最后，什么也读不出来了，所以返回值是0
			break;
		if (strcmp(a, st.name) == 0)//找到了符合条件的姓名
		{
			status = 1;
			printf("name = %s, age = %d\n", st.name, st.age);
		}
	}
	if (status == 0)
		printf("not found\n");
	fclose(p);
	return 0;
}

int mydelete();

int main(int argc, char **args)
{
	if (argc < 2)
		return 0;

	if (args[1][0] == '0')
		input();
	if (args[1][0] == '1')
		myselect();
	if (args[1][0] == '2')
		mydelete();
	return 0;
}

int mydelete()
{
	FILE *p = fopen("b.dat", "rb");
	if (!p)
		return 0;

	fseek(p, 0, SEEK_END);
	long len = ftell(p);//得到文件大小
	fseek(p, 0, SEEK_SET);//因为要读文件，所以要把文件指针移动到开始    
	unsigned char *p1 = (unsigned char *)malloc(len);
	fread(p1, sizeof(char), len, p);//这样可以一次把所有内容读入内存
	fclose(p);//这个时候文件所有的内容都已经在堆里面，所以文件就没必要打开了
	struct student *p2 = (struct student *)p1;

	char a[100] = { 0 };
	printf("please input name:");
	scanf("%s", a);
	p = fopen("b.dat", "wb");
	if (!p)
		return 0;
	int i;
	for(i = 0; i < (len / sizeof(struct student)); i++)
	{
		if (strcmp(p2[i].name, a))//如果name和a不相同，才写入文件
			fwrite(&p2[i], sizeof(struct student), 1, p);
		else
		{
			printf("input age: ");
			scanf("%d",&p2[i].age);
			fwrite(&p2[i],sizeof(struct student),1,p);
		}
	}
	fclose(p);
	free(p1);
	return 0;
}
