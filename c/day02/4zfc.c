#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//C������û���ַ������ͣ� ��һ���ַ�����+\0��ʾ�ַ�����

// 0   '0'  NULL  0x0000000 , \0

int main(void)
{
	char str1[] = "abcd"; //char[5]
	char *str2 = "abcd";
	char str3[] = { 'a', 'b', 'c', 'd' }; //char [4]
	char str4[128] = { 'a', 'b', 'c' };//char[128] //����û�г�ʼ����Ĭ�϶���  0 ===>\0
	int a = 10;
	unsigned int i = 0;

	//128:  'a' 'b' 'c' \0 0000000

	sizeof(str1); //���������ʹ�С   5
	strlen(str1); //���ַ������ַ��ĸ�����������\0  4

	printf("sizeof(str1) :%d\n", sizeof(str1));
	printf("strlen(str1) :%d\n", strlen(str1));
	printf("sizeof(str3):%d\n", sizeof(str3));

	printf("sizeof(str4): %d\n", sizeof(str4));//128
	printf("strlen(str4):%d\n", strlen(str4)); //3


	for (i = 0; i < strlen(str1); i++)
	{
		printf("%c\n", str1[i]);
		//str1[i]
		//printf("%c\n", *(str1 + i));
	}

	char *p = NULL;

	for (p = str1; *p != '\0'; p++)
	{
		printf("%c\n", *p);
	}

#if 0
	for (; *str1 != '\0'; str1++)
	{
		printf("%c\n", *str1);
	}
#endif


	//ָ���������������
	// 1 ��������һ��������ָ�룬����Զָ�������Ԫ�صĵ�ַ��
	//	  ָ���ǿ��Ըı�ġ�
	//2  ͨ�������±��ֱ������ Ҫ��ͨ��ָ���ӵ��������ٶ�Ҫ�졣
	//3  Ϊʲô�����������޸��أ�
	//   ֮���� �����������ܹ��޸ģ� ������Ϊһ�����鶼����ջ�Ͽ��ٿռ�ġ�
			//ջ�Ŀռ䶼���ɲ���ϵͳ���л��պ͹���ģ����������������ƫ�ƺ��޸�
		  //����ϵͳ���޷��ҵ�֮ǰ�� �Ѿ����ٵ������ռ���׵�ַ��

	// 4 һ���������ջ�Ͽ����ڴ�������飬�ڶ��Ͽ����ڴ����ָ�롣




	return 0;
}
