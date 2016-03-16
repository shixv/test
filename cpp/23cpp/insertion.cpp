#include "test.h"
using namespace std;
template <typename Comparable>
void insertionSort(vector<Comparable>& a)
{
	int j;
	for(unsigned int p=1;p<a.size();p++)
	{
		Comparable tmp=a[p];
		for(j=p;j>0&&tmp<a[j-1];j--)
			a[j]=a[j-1];
		a[j]=tmp;
	}
}
void insertionSort1(int* a,int count)
{
	int j;
	for(int p=1;p<count;p++)
	{
		int tmp=a[p];
		for(j=p;j>0&&tmp<a[j-1];j--)
			a[j]=a[j-1];
		a[j]=tmp;
	}
}
int main(int argc,char* argv[])
{
	testsort(insertionSort1,1000);
	return 0;
}
