#include <stdio.h>
typedef int(*Caculator)(int, int);
int MyCaculator(int a,int b,Caculator caculator){
	return caculator(a,b);
}
int Plus(int a,int b){
	return a+b+100;
}
int multiplies(int a,int b){
	return a*b;
}
int main(void)
{
	int ret=MyCaculator(10,20,Plus);
	printf("ret:%d\n",ret);
	ret=MyCaculator(10,20,multiplies);
	printf("ret:%d\n",ret);
	return 0;
}
