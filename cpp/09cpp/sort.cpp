#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
template<typename Element>
int compare(const void  *a,const void *b)
{
	return (int)(*(Element *)a-*(Element *)b);
}
template<typename Element>
void mysort(Element *arr,int n)
{
	qsort(arr,n,sizeof(Element),compare<Element>);
}
int main(int argc,char *argv[])
{
	mysort(argv[1],strlen(argv[1]));
	for(unsigned int i=0;i<strlen(argv[1]);i++)
	{
		cout<<argv[1][i];
	}
	cout<<endl;
	return 0;
}
