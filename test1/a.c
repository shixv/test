#include <stdio.h>
#include <string.h>

//#pragma warning(disable:4996)

struct student//建立一个结构体，名字叫student
{
	char name[20];//姓名
	unsigned int age;
	unsigned char sex;//0男，1女
	int score;//成绩
};//这个分号是必须的

#define MAN 0
#define WOMAN 1

int main01()
{
	struct student s;//定义了一个结构体变量，名字叫s,s在栈里面，还是哪里？
	//strcpy(s.name, "张三");
	//s.age = 30;
	//s.sex = MAN;
	printf("请输入姓名:");
	scanf("%s", s.name);
	printf("请输入年龄:");
	scanf("%u", &s.age);
	unsigned int a = 0;
	printf("请输入性别（0：男，1：女）:");
	scanf("%u", &a);
	s.sex = a;//自动的把int转化为char
	if (s.sex == MAN)
		printf("%s, %d, 男\n", s.name, s.age);

	if (s.sex == WOMAN)
		printf("%s, %d, 女\n", s.name, s.age);
	return 0;

}

int main02()
{
	//struct student s = { "刘德华", 50, MAN };//定义一个结构体变量，同时初始化成员
	//struct student s = { "李登辉" };//只初始化第一个成员，后面的成员置0
	//struct student s = { 0 };//把所有成员都设置为0
	struct student s = {.sex = WOMAN, .age = 30, .name = "张惠妹"};
	if (s.sex == MAN)
		printf("%s, %d, 男\n", s.name, s.age);

	if (s.sex == WOMAN)
		printf("%s, %d, 女\n", s.name, s.age);
	return 0;

}


struct A
{
	short a1;
	char a2;
	char a3;
	char a4;
	char a5;
	char a6;
};

struct B
{
	int a1;
	char a2;
	int a3;
	char a4;
};

struct C
{
	char a1;
	short a2;
	char a3;
	int a4;
};

struct D
{
	char a1[10];//不会按照a1 的大小对齐，所以数组按照数组每个成员的类型大小对齐
	int a2;
};

struct E
{
	unsigned char a1 : 2;//a1只有2个bit
};

struct F
{
	char a1 : 3;//只有3个bit
	int a2 : 2;
	//int a3 : 10;//错误的，因为char最大是8个bit
};

struct G
{
	char a1;
	int a2;
	char a3;
	int a4;
	char a5;
	int a6;
	char a7;
};

struct G1
{
	char a1;
	char a3;
	char a5;
	char a7;
	int a2;
	int a4;
	int a6;

};

struct I
{
	char a1 : 2;
	int a2 : 2;
	char a3 : 2;
	int a4 : 2;
};

struct I1
{
	char a1 : 2;
	char a2 : 2;
	char a3 : 2;
	char a4 : 2;
};

int main03()
{
	struct E a = { 0 };
	printf("%u\n", sizeof(a));
	a.a1 = 5;
	printf("%u\n", a.a1);
	struct F b;
	b.a1 = 5;
	printf("%d\n", b.a1);
	printf("%u\n", sizeof(b));
	return 0;
}

struct man
{
	struct student st;
	int classes;
};

struct A1
{
	int a1;
	char a2;
};

struct A2
{
	struct A1 a1;//成员是另外一个结构体
	//a1不会融合a2，因为a1是一个单独的变量
	char a2;
};

int main04()
{
	printf("%u\n", sizeof(struct A2));
	return 0;
	//struct student s[10] = { 0 };//定义了一个结构体数组,有10个成员
	struct student s[5] = { {"刘德华",30,0}, {"张学友",40,0}, {"张惠妹",30,1}, 
		{"郭富城",60,0}, {"陈冠希",30,0} };

	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%s, %d, %d\n", s[i].name, s[i].age, s[i].sex);
	}
	return 0;
}

int main05()
{
	struct student s1 = { "陈冠希", 30, 0 };
	struct student s2 = {"苍老师", 20, 1};
	struct student tmp = s1;
	s1 = s2;
	s2 = tmp;
	//s2 = s1;//结构体变量赋值,结构体变量的赋值其实就是结构体变量之间的内存拷贝
	//结构体变量赋值的前提是，两个变量一定是同一种类型
	//memcpy(&s2, &s1, sizeof(s1));
	//strcpy(s2.name, s1.name);
	//s2.age = s1.age;
	//s2.sex = s1.sex;
	printf("%s, %d, %d\n", s1.name, s1.age, s1.sex);
	printf("%s, %d, %d\n", s2.name, s2.age, s2.sex);
	return 0;

}

int main()
{
	struct student st[5] = { { "刘德华", 30, 0 , 80}, { "张学友", 40, 0, 90 }, { "张惠妹", 30, 1, 30 },
		{ "郭富城", 60, 0 , 90}, { "陈冠希", 30, 0, 100 } };


	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 1; j < 5 - i; j++)
		{
			if (st[j].age < st[j - 1].age)
			{
				struct student tmp = st[j];
				st[j] = st[j - 1];
				st[j - 1] = tmp;
			}
		}
	}
	for (i = 0; i < 5; i++)
	{
		printf("%s, %d, %d, %d\n", st[i].name, st[i].age, st[i].sex, st[i].score);
	}
	return 0;
}
