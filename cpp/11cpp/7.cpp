#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
void my_strcpy(char *dst, char *src)
{
	if (dst == NULL) {
		throw 1; //1 代表目的地址有问题
	}
	if (src == NULL) {
		throw 2; //2 代表 源地址有问题
	}
	if (*src == 'a') {
		throw 3; //3 代表拷贝的内容非法
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
		throw "目的地址有问题"; //1 代表目的地址有问题
	}
	if (src == NULL) {
		throw  "源地址有问题"; //2 代表 源地址有问题
	}
	if (*src == 'a') {
		throw "拷贝的内容非法"; //3 代表拷贝的内容非法
	}
	while (*src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
}
//定义三种异常类
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
		cout << "BadContextType()::print() :: 内存出现问题的异常 "<<endl;
	}
};
void my_strcpy3(char *dst, char *src)
{
	if (dst == NULL) {
		throw BadDstAddrType(); //1 代表目的地址有问题
	}
	if (src == NULL) {
		throw  BadSrcAddrType(); //2 代表 源地址有问题
	}
	if (*src == 'a') {
		throw  BadContextType(); //3 代表拷贝的内容非法
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
	//如果有捕获引用的 catch 就不能够同时写 捕获普通类型catch
	//catch (BadContextType e)
	//{
	//	cout << "捕获到了BadContextType 类型的异常" << endl;
	//	e.print();
	//}
	//如果通过指针来捕获异常的话， 在抛出的话不能够抛出一个匿名的在栈上开辟的临时对象
	catch (BadContextType *e) // BadContextType e = 匿名对象 //会调用e的拷贝构造函数
	{
		cout << "捕获到了BadContextType* 类型的异常" << endl;
		e->print();
		delete e;
	}
	catch (BadContextType &e) //如果说 用一个&e 去接收一个局部在栈上开辟的异常对象， 编译器不会立刻释放这个对象
	{
		cout << "捕获到了BadContextType& 类型的异常" << endl;
		e.print();
	}
	catch (BadSrcAddrType e)
	{
		cout << "捕获到了BadSrcAddrType 类型的异常" << endl;
	}
	catch (BadDstAddrType e)
	{
		cout << "捕获到了BadDstAddrType 类型的异常" << endl;
	}
	return 0;
}
#if 0
int my_strcpy(char *dst, char *src)
{
	if (dst == NULL) {
		return 1; //1 代表目的地址有问题
	}
	if (src == NULL) {
		return 2; //2 代表 源地址有问题
	}
	if (*src == 'a') {
		return 3; //3 代表拷贝的内容非法
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
			cout << "目的地址有问题" << endl;
			break;
		case 2:
			cout << "原的地址有问题" << endl;
			break;
		case 3:
			cout << "内容有问题" << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}
#endif