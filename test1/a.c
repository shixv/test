#include <stdio.h>
#include <string.h>

//#pragma warning(disable:4996)

struct student//����һ���ṹ�壬���ֽ�student
{
	char name[20];//����
	unsigned int age;
	unsigned char sex;//0�У�1Ů
	int score;//�ɼ�
};//����ֺ��Ǳ����

#define MAN 0
#define WOMAN 1

int main01()
{
	struct student s;//������һ���ṹ����������ֽ�s,s��ջ���棬�������
	//strcpy(s.name, "����");
	//s.age = 30;
	//s.sex = MAN;
	printf("����������:");
	scanf("%s", s.name);
	printf("����������:");
	scanf("%u", &s.age);
	unsigned int a = 0;
	printf("�������Ա�0���У�1��Ů��:");
	scanf("%u", &a);
	s.sex = a;//�Զ��İ�intת��Ϊchar
	if (s.sex == MAN)
		printf("%s, %d, ��\n", s.name, s.age);

	if (s.sex == WOMAN)
		printf("%s, %d, Ů\n", s.name, s.age);
	return 0;

}

int main02()
{
	//struct student s = { "���»�", 50, MAN };//����һ���ṹ�������ͬʱ��ʼ����Ա
	//struct student s = { "��ǻ�" };//ֻ��ʼ����һ����Ա������ĳ�Ա��0
	//struct student s = { 0 };//�����г�Ա������Ϊ0
	struct student s = {.sex = WOMAN, .age = 30, .name = "�Ż���"};
	if (s.sex == MAN)
		printf("%s, %d, ��\n", s.name, s.age);

	if (s.sex == WOMAN)
		printf("%s, %d, Ů\n", s.name, s.age);
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
	char a1[10];//���ᰴ��a1 �Ĵ�С���룬�������鰴������ÿ����Ա�����ʹ�С����
	int a2;
};

struct E
{
	unsigned char a1 : 2;//a1ֻ��2��bit
};

struct F
{
	char a1 : 3;//ֻ��3��bit
	int a2 : 2;
	//int a3 : 10;//����ģ���Ϊchar�����8��bit
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
	struct A1 a1;//��Ա������һ���ṹ��
	//a1�����ں�a2����Ϊa1��һ�������ı���
	char a2;
};

int main04()
{
	printf("%u\n", sizeof(struct A2));
	return 0;
	//struct student s[10] = { 0 };//������һ���ṹ������,��10����Ա
	struct student s[5] = { {"���»�",30,0}, {"��ѧ��",40,0}, {"�Ż���",30,1}, 
		{"������",60,0}, {"�¹�ϣ",30,0} };

	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%s, %d, %d\n", s[i].name, s[i].age, s[i].sex);
	}
	return 0;
}

int main05()
{
	struct student s1 = { "�¹�ϣ", 30, 0 };
	struct student s2 = {"����ʦ", 20, 1};
	struct student tmp = s1;
	s1 = s2;
	s2 = tmp;
	//s2 = s1;//�ṹ�������ֵ,�ṹ������ĸ�ֵ��ʵ���ǽṹ�����֮����ڴ濽��
	//�ṹ�������ֵ��ǰ���ǣ���������һ����ͬһ������
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
	struct student st[5] = { { "���»�", 30, 0 , 80}, { "��ѧ��", 40, 0, 90 }, { "�Ż���", 30, 1, 30 },
		{ "������", 60, 0 , 90}, { "�¹�ϣ", 30, 0, 100 } };


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
