#include <iostream>
#include <cstdlib>

using namespace std;

void test1()
{
	int *p=(int *)malloc(sizeof(int)*10);
	for(int i=0;i<10;i++)
		p[i]=i;
	for(int i=0;i<10;i++)
		cout<<p[i]<<endl;
	free(p);
}
void test2()
{
	int *p=new int[10];
	for(int i=0;i<10;i++)
		p[i]=i;
	for(int i=0;i<10;i++)
		cout<<p[i]<<endl;
	delete[] p;
}

int main(void)
{
	test1();
	test2();
	return 0;
}
