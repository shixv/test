int MaxSubSequenceSum1(const int A[],int N)  //最大子序列算法一
{
	int ThisSum,MaxSum,i,j,k;

	MaxSum = 0;
	for(i=0;i<N;i++)
		for(j=i;j<N;j++)
		{
			ThisSum=0;
			for(k=i;k<=j;k++)
				ThisSum+=A[k];
			if(ThisSum>MaxSum)
				MaxSum=ThisSum;
		}
	return MaxSum;
}


int MaxSubSequenceSum2(const int A[],int N)
{
	int ThisSum,MaxSum,i,j;

	MaxSum=0;
	for(i=0;i<N;i++)
	{
		ThisSum=0;
		for(j=i;j<N;j++)
		{
			ThisSum+=A[j];
			if(ThisSum>MaxSum)
				MaxSum=ThisSum;
		}
	}
	return MaxSum;
}


int MaxSubSequenceSum3(const int A[],int N)   //递归实现
{
	return MaxSubSum(A,0,N-1);
}
static int MaxSubSum(const int A[],int left,int right)
{
	int MaxLeftSum,MaxRightSum;
	int MaxLeftBorderSum,MaxRightBorderSum;
	int LeftBorderSum,RightBorderSum;
	int Center,i;
	if(Left==Right)
		if(A[Left]>0)
			return A[Left];
		else
			return 0;
	Center=(Left+Right)/2;
	MaxLeftSum=MaxSubSum(A,Left,Center);
	MaxRightSum=MaxSubSum(A,Center+1,Right);

	MaxLeftBorderSum=0;LeftBorderSum=0;
	for(i=Center;i>=left;i--)
	{
		LeftBorderSum+=A[i];
		if(LeftBorderSum>MaxLeftBorderSum)
			MaxLeftBorderSum=LeftBorderSum;
	}
	MaxRightBorderSum=0;RightBorderSum=0;
	for(i=Center+1;i<=Right;i++)
	{
		RightBorderSum+=A[i];
		if(RightBorderSum>MaxRightBorderSum)
			MaxRightBorderSum=RightBorderSum;
	}
	return Max3(MaxRightSum,MaxLeftSum,MaxLeftBorderSum+MaxRightBorderSum);
}
int Max3(int a,int b,int c)
{
	return ((a>b)?a:b)>c?((a>b)?a:b):c;
}


int MaxSubSequnceSum4(const int A[],int N)
{
	int ThisSum,MaxSum,j;

	ThisSum=MaxSum=0;
	for(j=0;j<N;j++)
	{
		ThisSum+=A[j];
		if(ThisSum>MaxSum)
			MaxSum=ThisSum;
		else if(ThisSum<0)
			ThisSum=0;
	}
	return MaxSum;
}

int BinarySearch(const ElementType A[],ElementType X,int N)
{
	int Low,Mid,High;

	Low=0;High=N-1;
	while(Low<=High)
	{
		Mid=(Low+High)/2;
		if(A[Mid]<X)
			Low=Mid+1;
		else if(A[Mid]>X)
			High=Mid-1;
		else
			return Mid;
	}
	return NotFound;
}

unsigned int Gcd(unsigned int M,unsigned int N)
{
	unsigned int Rem;
	while(N>0)
	{
		Rem=M%N;
		M=N;
		N=Rem;
	}
	return 0;
}

long int Pow(long int X,unsigned int N)
{
	if(N==0)
		return 1;
	if(N==1)
		return X;
	if(IsEven(N))
		return Pow(X*X,N/2);
	else
		return Pow(X*X,N/2)*X;
}


