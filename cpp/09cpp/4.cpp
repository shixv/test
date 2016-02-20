#include <iostream>
#include <cstdlib>
using namespace std;
typedef int(ARRAY_INT_10)[10];
int main(void)
{
	int array[10];
	ARRAY_INT_10 array2;
	ARRAY_INT_10 *array_p=(int (*)[10])malloc(sizeof(int)*10);
	for(int i=0;i<10;i++)
	{
		(*array_p)[i]=i+10;
	}
	return 0;
}
