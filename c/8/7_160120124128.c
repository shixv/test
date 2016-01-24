#define TY 2009
#define Max(a,b) ((a)>(b)?(a):(b))
#define Swap(a,b) \
	do{\
		a^=b;\
		b^=a;\
		a^=b;\
	}while(0)
#define Pow(x) (x)*(x)
#define Psqr(x) printf("The square of "#x" is %d \n",((x)*(x)))
#define S(x) x##123
#define VS(x,...) hehe(x,__VA_ARGS__)
#define DEBUG(format,...) \
	do{ \
	printf("[DEBUG][%s,%d][%s,%s]"format"\n",__FUNCTION__,__LINE__,__DATE__,__TIME__,##__VA_ARGS__);\
	}while(0)
//#define LOG(format,...) \
	do{ \
		printf("[LOG][%s,%d]


void printself(char *s)
{
	printf("%s\n",s);
	printf("%s\n",__func__);
}
int main(void)
{
//	int x=TY;
//	Max(123,345);
//	int y=2;
//	Swap(x,y);
//	Pow(x);
//	printf("%d\n",Pow(++x));
//	Psqr(12);
//	S(fg);
//	VS(12,23,12,123,124,325);
//	__DATE__;
//	__LINE__;
	printf("%s\n",__func__);
	printf("%d\n",__LINE__);
	printf("%s\n",__FILE__);
	printself(__func__);
	printf("%d\n",__STDC__);
	DEBUG();
	return 0;
}
