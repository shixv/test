#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//通过一个函数 向得到一个文件的长度
void get_file_len(int file_len)
{
	//通过计算，文件的长度就是30

	file_len = 30;
}

//如果不通过指针，向把子函数内部的数据传出来 只能够通过返回值
int get_file_len2(void)
{
	int file_len = 30;

	return file_len;
}// main::file_len = get_file_len2::file_len;


//如果说向用一个子函数改变外界函数的 变量， 如果外界函数的变量是0级指针。 就需要1级指针的形参
																	//如果需要被修改的外界变量是1级指针，就需要2级指
