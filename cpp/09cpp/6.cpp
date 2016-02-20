#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
//有一个锦娘的方法
typedef void(TIPS)(void); //将锦囊的函数类型 抽象出来。
//顶一个锦囊struct  数据类型、
struct tip
{
	char from[64];//该锦囊是谁写的
	char to[64];//该锦囊写给谁的
	//锦囊的具体内容
	TIPS *tp; //相当于 抽象类的纯虚函数
};
//有一个 打开锦囊的 架构函数
void open_tips(struct tip * tip_p)
{
	cout << "打开了锦囊" << endl;
	cout << "此锦囊是由 " << tip_p->from << " 写给  " << tip_p->to <<"的。" << endl;
	cout << "内容是" << endl;
	tip_p->tp();
}
//三个锦囊  诸葛亮实现的三个锦囊
void tips_1(void)
{
	cout << "一到东吴拜会乔国老" << endl;
}
void tips_2(void)
{
	cout << "说 曹操大军压境， 全刘备回去" << endl;
}
void tips_3(void)
{
	cout << "求救 孙尚香" << endl;
}
void tips_4(void)
{
	cout<<"What the fuck!"<<endl;
}
//创建锦囊的函数
struct tip * create_tip(const char *from, const char *to, TIPS *fp)
{
	struct tip * my_tip= (struct tip *)malloc(sizeof(struct tip));
	if (my_tip == NULL) {
		return NULL;
	}
	strcpy(my_tip->from, from );
	strcpy(my_tip->to, to);
	//如果给一个结构体的一个函数指针赋值，  又叫做，注册一个回调函数
	my_tip->tp = fp;
	return my_tip;
}
void destory_tip(struct tip* tip_p)
{
	if (tip_p != NULL) {
		free(tip_p);
	}
}
int main(void)
{
	//诸葛亮创建3个锦囊
	struct tip *tip1 = create_tip("孔明", "子龙", tips_1);
	struct tip *tip2 = create_tip("孔明", "子龙", tips_2);
	struct tip *tip3 = create_tip("孔明", "子龙", tips_3);
	//赵云开始开锦囊
	cout << "刚来到东吴， 打开第一个锦囊" << endl;
	open_tips(tip1);
	cout << " -------" << endl;
	cout << "刘备乐不思蜀， 打开第二个锦囊" << endl;
	open_tips(tip2);
	cout << "------" << endl;
	cout << "孙权追杀刘备， 打不过了， 打开第三个锦囊" << endl;
	open_tips(tip3);
	destory_tip(tip1);
	destory_tip(tip2);
	destory_tip(tip3);
	struct tip *tip4 = create_tip("sihyuan","zilong",tips_4);
	cout<<"da kai di si ge jin nang"<<endl;
	open_tips(tip4);
	destory_tip(tip4);
	return 0;
}
