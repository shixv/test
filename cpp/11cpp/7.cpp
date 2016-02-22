#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
void my_strcpy(char *dst, char *src)
{
	if (dst == NULL) {
		throw 1; //1 ����Ŀ�ĵ�ַ������
	}
	if (src == NULL) {
		throw 2; //2 ���� Դ��ַ������
	}
	if (*src == 'a') {
		throw 3; //3 �����������ݷǷ�
	}
	while (*src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
}
void my_strcpy2(char *dst, char *src)
{
	if (dst == NULL) {
		throw "Ŀ�ĵ�ַ������"; //1 ����Ŀ�ĵ�ַ������
	}
	if (src == NULL) {
		throw  "Դ��ַ������"; //2 ���� Դ��ַ������
	}
	if (*src == 'a') {
		throw "���������ݷǷ�"; //3 �����������ݷǷ�
	}
	while (*src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
}
//���������쳣��
class BadDstAddrType {
};
class BadSrcAddrType
{
};
class BadContextType
{
public:
	BadContextType()
	{
		cout << "BadContextType().." << endl;
	}
	BadContextType(const BadContextType &e)
	{
		cout << "BadContextType(const BadContextType &e).." << endl;
	}
	~BadContextType()
	{
		cout << "~BadContextType()..." << endl;
	}
	void print()
	{
		cout << "BadContextType()::print() :: �ڴ����������쳣 "<<endl;
	}
};
void my_strcpy3(char *dst, char *src)
{
	if (dst == NULL) {
		throw BadDstAddrType(); //1 ����Ŀ�ĵ�ַ������
	}
	if (src == NULL) {
		throw  BadSrcAddrType(); //2 ���� Դ��ַ������
	}
	if (*src == 'a') {
		throw  BadContextType(); //3 �����������ݷǷ�
	}
	while (*src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
}
int main(void)
{
	char buf1[] = "a234567";
	char buf2[128] = { 0 };
	try {
		my_strcpy3(buf2, buf1);
	}
	//����в������õ� catch �Ͳ��ܹ�ͬʱд ������ͨ����catch
	//catch (BadContextType e)
	//{
	//	cout << "������BadContextType ���͵��쳣" << endl;
	//	e.print();
	//}
	//���ͨ��ָ���������쳣�Ļ��� ���׳��Ļ����ܹ��׳�һ����������ջ�Ͽ��ٵ���ʱ����
	catch (BadContextType *e) // BadContextType e = �������� //�����e�Ŀ������캯��
	{
		cout << "������BadContextType* ���͵��쳣" << endl;
		e->print();
		delete e;
	}
	catch (BadContextType &e) //���˵ ��һ��&e ȥ����һ���ֲ���ջ�Ͽ��ٵ��쳣���� ���������������ͷ��������
	{
		cout << "������BadContextType& ���͵��쳣" << endl;
		e.print();
	}
	catch (BadSrcAddrType e)
	{
		cout << "������BadSrcAddrType ���͵��쳣" << endl;
	}
	catch (BadDstAddrType e)
	{
		cout << "������BadDstAddrType ���͵��쳣" << endl;
	}
	return 0;
}
#if 0
int my_strcpy(char *dst, char *src)
{
	if (dst == NULL) {
		return 1; //1 ����Ŀ�ĵ�ַ������
	}
	if (src == NULL) {
		return 2; //2 ���� Դ��ַ������
	}
	if (*src == 'a') {
		return 3; //3 �����������ݷǷ�
	}
	while (*src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return 0;
}
int main(void)
{
	char buf1[] = "a234567";
	char buf2[128] = { 0 };
	int ret = 0;
	ret = my_strcpy(buf2, buf1);
	if (ret != 0)
	{
		switch (ret)
		{
		case 1:
			cout << "Ŀ�ĵ�ַ������" << endl;
			break;
		case 2:
			cout << "ԭ�ĵ�ַ������" << endl;
			break;
		case 3:
			cout << "����������" << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}
#endif