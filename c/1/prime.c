//生成素数序列并保存，int类型最大素数不超过2^32-1,只写了几个函数，main函数实在不会写了，脑子烧坏了
//isPrime系列函数借鉴了网上大神的博文
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define FILENAM "prime.dat"

int isPrime1(int n)          //最简单
{ 							   //
	if(n<2) 				   //		
		return 0;
	for(int i=2;i<n;++i)
		if(n%i==0)
			return 0;
	return 1;
}
/*
_Bool isPrime2(int n)          //过滤掉偶数，速度提高一倍
{
	if(n<(INT)2)
		return false;
	if(n==(INT)2)
		return true;
	if(n%(INT)2==(INT)0)
		return false;

	for(int i=(INT)3;i<n;i+=(INT)2)
		if(n%i==(INT)0)
			return false;
	return true;
}
*/
/*如果n不是素数，则n有满足1<d<=sqrt(n)的一个因子d.
int isPrime3(INT n)
{
	if(n<(INT)2)
		return 0;
	if(n==(INT)2)
		return 1;
	if(n%(INT)2==(INT)0)
		return 0;
	INT foo=(INT)sqrt(n);
	for(INT i=(INT)3;i<=foo;i+=(INT)2)
		if(n%i==(INT)0)
			return 0;
	return 1;
}*/

//如果n不是素数，则n有满足1<d<=sqrt(n)的一个素数因子d。
int isPrime4(int *array,int n)
{
	if(n<2)
		return 0;
	for(int i=0;array[i]*array[i]<=n;i++)
		if(n%array[i]==0)
			return 0;
	return 1;
}
int *InitPrimeArray(int start,int n)//初始化一个从start开始大小为n的素数序列并返回
{
	if(start<1||n<1)
		return NULL;
	int *arr=(int *)malloc(sizeof(int)*n);
	int i=0;int j=start;
	while(i<n)
	{
		if(isPrime1(j))
			arr[i++]=j;
		j++;
	}
	return arr;
}

void PrintPrimeArray(int *arr,int n)//打印传入的arr指向的素数序列，打印n个
{
	if(arr==NULL||n<1)
		return;
	for(int i=0;i<n;i++)
	{
		if(i%10==0)
			printf("\n");
		printf("%10d",arr[i]);
	}
	free(arr);
	printf("\n");
	printf("total number is %d\n",n);
}
void InitPrimeFile(int n,char *filename)//生成包含从2开始的n个素数名为filename的文件
{
	if(n<1||filename==NULL)
		return;
	FILE *p=fopen(filename,"w");
	int *arr=InitPrimeArray(1,n);
	for(int i=0;i<n;i++)
		fwrite(arr+i,sizeof(int),1,p);
	free(arr);
	fclose(p);
}
int *ReadPrimeFile(int start,int end,char *filename)//读取名为filename的文件，从第start个到第end
{ 													//个，并返回指向包含此素数序列的指针。					
	if(end<start||filename==NULL||start<1||end<2)
		return NULL;
	int *arr=(int *)malloc(sizeof(int)*(end-start+1));
	FILE *p=fopen(filename,"r");
	fseek(p,sizeof(int)*(start-1),SEEK_SET);
	for(int i=0;start<=end;i++,start++)
	{
		fread(arr+i,sizeof(int),1,p);
	}
	fclose(p);
	return arr;
}
int getEndPrime(char *filename)//得到名为filename的文件的最后一个素数
{
	if(filename==NULL)
		return 0;
	FILE *p=fopen(filename,"r");
	fseek(p,-4,SEEK_END);
	int i=0;
	fread(&i,sizeof(int),1,p);
	fclose(p);
	return i;
}
int getPrimeCount(char *filename)//得到名为filename的文件记录的素数个数
{
	if(filename==NULL)
		return 0;
	FILE *p=fopen(filename,"r");
	int fn=1;
	int n;
	int i=0;
	while(fn)
	{
		fn=fread(&n,sizeof(int),1,p);
		i++;
	}
	fclose(p);
	return i-1;
}
int *AttendPrimeArray(int start,int n)//生成start之后的n个素数并返回指向该数组的指针
{ 									  //由AttendPrimeFile调用	
	if(start<1||n<1)
		return NULL;
	int *arr=(int *)malloc(sizeof(int)*n);
	int *src=ReadPrimeFile(1,getPrimeCount(FILENAM),FILENAM);
	int i=0;int j=start;
	while(i<n)
	{
		if(isPrime4(src,j))
			arr[i++]=j;
		j++;
	}
	return arr;
}

void AttendPrimeFile(int n,char *filename)//在名为filename的文件之后追加n个素数
{
	if(n<1||filename==NULL)
		return;
	int *arr=AttendPrimeArray(getEndPrime(filename),n);
	FILE *p=fopen(filename,"a");
	for(int i=0;i<n;i++)
		fwrite(arr+i,sizeof(int),1,p);
	free(arr);
	fclose(p);
}


int getSinglePrime(int n,char *filename)//得到filename文件中第n个素数
{
	if(n<1||filename==NULL)
		return 0;
	FILE *p=fopen(filename,"r");
	fseek(p,sizeof(int)*(n-1),SEEK_SET);
	int i;
	fread(&i,sizeof(int),1,p);
	fclose(p);
	return i;
}
int SearchSinglePrime(int P,char *filename)//搜素filename文件中P的位置，失败返回0
{
	if(P<1||filename==NULL)
		return 0;
	int count=getPrimeCount(filename);
	int *arr=ReadPrimeFile(1,count,filename);
	for(int i=0;i<count;i++)
	{
		if(arr[i]==P)
			return i+1;
		if(arr[i]>P)
			return i;
	}
	free(arr);
	return 0;
}
int FindNextPrime(int P,char *filename)//返回整数P的下一个素数，失败返回0
{
	if(P<1||filename==NULL)
		return 0;
	int pos;
	if((pos=SearchSinglePrime(P,filename))!=0)
		return getSinglePrime(pos+1,filename);
	return 0;
}
int SearchPrimeFile(int Pstart,int Pend,char *filename,int **arr)
{//在filename文件中搜寻整数范围Pstart-Pend之间的素数，使*arr指向包含该序列的空间，并返回素数个数
	if(Pstart>=Pend||Pstart<1||Pend<2||filename==NULL)
		return 0;
	FILE *p=fopen(filename,"r");
	int i=1;
	int fp=0,bp=0;
	int n=0;
	while(i)
	{
		i=fread(&n,sizeof(int),1,p);
		if(n<=Pstart)
		{
			fp++;
			bp++;
		}
		if(n>Pstart&&n<=Pend)
			bp++;
	}
	fclose(p);
	*arr=ReadPrimeFile(fp+1,bp,filename);
	return bp-fp;
}
int isPrime(int P,char *filename)//在filename中搜寻是否包含P，失败返回0
{
	if(P<1||filename==NULL)
		return 0;
	if(P!=getSinglePrime(SearchSinglePrime(P,filename),filename))
		return 0;
	return 1;
}

int main(int argc,char *argv[])
{
//	int opt;
//	int *array=NULL;
//-i [N] 初始化;-a 追加;-c n,N 从第n-第N的素数;-C n-N从n到N范围的素数;-p 是否为素；-P 第几个素数；
//-n 返回第n个素数
//	while((opt=getopt(argc,argv,"i:a:c:C:p:P:n:")))
//	{
//		switch(opt){
//			case 'i':
//				InitPrimeFile(atoi(optarg),FILENAM);
//				break;
//		}
//	}
	int *array=NULL;
//	InitPrimeFile(1000,FILENAM);
	AttendPrimeFile(6000,FILENAM);
	array=ReadPrimeFile(1,100,FILENAM);
	PrintPrimeArray(array,100);
//	int n=SearchPrimeFile(4000,4100,FILENAM,&array);
//	PrintPrimeArray(array,n);
//	printf("%d\n",n);
	printf("EndPrime=%d\n",getEndPrime(FILENAM));
	printf("Total number is : %d\n",getPrimeCount(FILENAM));
//	printf("The number is %d\n",SearchSinglePrime(97,FILENAM));
//	printf("The next prime %d\n",FindNextPrime(112,FILENAM));
//	printf("It is Prime %d\n",isPrime(113,FILENAM));
	return 0;
}
