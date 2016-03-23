#include "test.h"
#include <string>
using namespace std;
void test1(int* a,int len)
{
	for(int i=0;i<len/2;i++)
	{
		Swap(a,i,len-i-1);
	}
}
int main(int argc,char* argv[])
{
	testsort(test1,stoi(argv[1]));
	return 0;
}
