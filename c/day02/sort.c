/*
   排序算法演示   
   written by 石旭 in 2016.1.9 2:20   
   以下排序算法都来源于书本和网络
   Quicksort有错误 
   有其他算法请随意添加，函数声明格式为void yourSort(ElementType *,int)
   */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
choice:
NULL,Selectsort,Shellsort,Insertionsort,Heapsort,Mergesort,Quicksort,Bubblesort,Cocktailsort
Qsortstd,=yourSort=...
*/
#define _SELECT Qsortstd
/*      show source array       */
//#define SHOWSRC
/*      show sorted array       */
//#define SHOWARR
#define _FILENAM "arr.dat"
#define ARRSIZE 1000000
#define ElementType int


#define LeftChild(i) (2*(i)+1)
#define Cutoff (3)

void Swape(ElementType *,ElementType *);   //交换两元素


//add your code here


clock_t T;
void Insertionsort(ElementType *,int);
int compare(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
void Qsortstd(ElementType *a,int n)
{
	qsort(a,n,sizeof(ElementType),compare);
}

void Cocktailsort(ElementType *a,int n)
{
	int i,left=0,right=n-1;
	while(left<right)
	{
		for(i=left;i<right;i++)
			if(a[i]>a[i+1])
				Swape(&a[i],&a[i+1]);
		right--;
		for(i=right;i>left;i--)
			if(a[i-1]>a[i])
				Swape(&a[i-1],&a[i]);
		left++;
	}
}
void Selectsort(ElementType *a,int n)
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
			if(a[min]>a[j])
				min=j;
		if(min!=i)
			Swape(&a[min],&a[i]);
	}
}

void Bubblesort(ElementType *a,int n)
{
	int i,j;
	for(j=0;j<n-1;j++)
		for(i=0;i<n-1-j;i++)
		{
			if(a[i]>a[i+1])
				Swape(&a[i],&a[i+1]);
		}
}

ElementType Median3(ElementType *a,int left,int right)
{
	int center=(left+right)/2;
	if(a[left]>a[center])
		Swape(&a[left],&a[center]);
	if(a[left]>a[right])
		Swape(&a[left],&a[right]);
	if(a[center]>a[right])
		Swape(&a[center],&a[right]);
	Swape(&a[center],&a[right-1]);
	return a[right-1];
}

void Qsort(ElementType *a,int left,int right)
{
	int i,j;
	ElementType pivot;
	if(left+Cutoff<=right)
	{
		pivot=Median3(a,left,right);
		i=left;j=right-1;
		for(;;)
		{
			while(a[++i]<pivot);
			while(a[--j]>pivot);
			if(i<j)
				Swape(&a[i],&a[j]);
			else
				break;
		}
		Swape(&a[i],&a[right-1]);
		Qsort(a,left,i-1);
		Qsort(a,i+1,right);
	}
	else
		Insertionsort(a+left,right-left+1);
}

void Quicksort(ElementType *A,int n)
{
	Qsort(A,0,n-1);
}

void Merge(ElementType *A,ElementType *TmpArray,int Lpos,int Rpos,int RightEnd)
{
	int i,LeftEnd,NumElements,TmpPos;
	LeftEnd=Rpos-1;
	TmpPos=Lpos;
	NumElements=RightEnd-Lpos+1;
	while(Lpos<=LeftEnd&&Rpos<=RightEnd)
		if(A[Lpos]<=A[Rpos])
			TmpArray[TmpPos++]=A[Lpos++];
		else
			TmpArray[TmpPos++]=A[Rpos++];
	while(Lpos<=LeftEnd)
		TmpArray[TmpPos++]=A[Lpos++];
	while(Rpos<=RightEnd)
		TmpArray[TmpPos++]=A[Rpos++];
	for(i=0;i<NumElements;i++,RightEnd--)
		A[RightEnd]=TmpArray[RightEnd];
}

void MSort(ElementType A[],ElementType *TmpArray,int Left,int Right)
{
	int Center;
	if(Left<Right)
	{
		Center=(Left+Right)/2;
		MSort(A,TmpArray,Left,Center);
		MSort(A,TmpArray,Center+1,Right);
		Merge(A,TmpArray,Left,Center+1,Right);
	}
}

void Mergesort(ElementType *A,int n)
{
	ElementType *TmpArray;
	TmpArray=malloc(n*sizeof(ElementType));
	MSort(A,TmpArray,0,n-1);
	free(TmpArray);
}

void Perdown(ElementType *A,int i,int n)
{
	int Child;
	ElementType Tmp;
	for(Tmp=A[i];LeftChild(i)<n;i=Child)
	{
		Child=LeftChild(i);
		if(Child!=n-1&&A[Child+1]>A[Child])
			Child++;
		if(Tmp<A[Child])
			A[i]=A[Child];
		else
			break;
	}
	A[i]=Tmp;
}

void Swape(ElementType *a,ElementType *b)
{
	*a^=*b;
	*b^=*a;
	*a^=*b;
}

void Heapsort(ElementType *A,int n)
{
	int i;
	for(i=n/2;i>=0;i--)
		Perdown(A,i,n);
	for(i=n-1;i>0;i--)
	{
		Swape(&A[0],&A[i]);
		Perdown(A,0,i);
	}
}

void Insertionsort(ElementType *A,int n)
{
	int j,P;
	ElementType Tmp;
	for(P=1;P<n;P++)
	{
		Tmp=A[P];
		for(j=P;j>0&&A[j-1]>Tmp;j--)
			A[j]=A[j-1];
		A[j]=Tmp;
	}
}

void Shellsort(ElementType A[],int N)
{
	int i,j,Increment;
	ElementType Tmp;

	for(Increment=N/2;Increment>0;Increment/=2)
		for(i=Increment;i<N;i++)
		{
			Tmp=A[i];
			for(j=i;j>=Increment;j-=Increment)
				if(Tmp<A[j-Increment])
					A[j]=A[j-Increment];
				else
					break;
			A[j]=Tmp;
		}
}


void initrandafile(int n)
{
	FILE *p=fopen(_FILENAM,"w");
	srand((unsigned int)time(0));
	ElementType randn;
	for(int i=0;i<n;i++)
	{
		randn=(ElementType)(rand()%ARRSIZE);
		fwrite(&randn,sizeof(ElementType),1,p);
	}
	fclose(p);
}

ElementType *readrandafile(int n)
{
	ElementType *arr=malloc(sizeof(ElementType)*n);
	FILE *p=fopen(_FILENAM,"r");
	for(int i=0;i<n;i++)
	{
		fread(arr+i,sizeof(ElementType),1,p);
	}
	fclose(p);
	return arr;
}

void writerandafile(ElementType *A,int n)
{
	FILE *p=fopen(_FILENAM,"w");
	for(int i=0;i<n;i++)
	{
		fwrite(A+i,sizeof(ElementType),1,p);
	}
	free(A);
	fclose(p);
}

void printrandafile(int n)
{
	FILE *p=fopen(_FILENAM,"r");
	ElementType m;
	for(int i=0;i<n;i++)
	{
		if(i%10==0)
			printf("\n");
		fread(&m,sizeof(ElementType),1,p);
		printf("%d\t",m);
	}
	printf("\n--------------------------\n");
	fclose(p);
}

clock_t tick(void (*p)(ElementType*,int),ElementType *A)
{
	clock_t start,end;
	start=clock();
	if(p==NULL)
		return 0L;
	(*p)(A,ARRSIZE);
	end=clock();
	return end-start;
}

int main(void)
{
	initrandafile(ARRSIZE);
#ifdef SHOWSRC
	printrandafile(ARRSIZE);
#endif
	ElementType *arr=readrandafile(ARRSIZE); 
	T=tick(_SELECT,arr);
	writerandafile(arr,ARRSIZE);             
#ifdef SHOWARR
	printrandafile(ARRSIZE);               
#endif
	printf("The time is %ld\n",T);	         
	return 0;
}
