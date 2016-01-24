//_Complex _Bool _Imaginary
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>

int main(int argc,char *argv[])
{
	char n[]="abcde";
	char m[10]="abcde";
	printf("%d,%d\n",strlen(n),sizeof(n));
	printf("%d,%d\n",strlen("abcde"),sizeof("abcde"));
//	printf("%d,%d\n",strlen(argv[1]),sizeof(argv[1]));
	printf("%d,%d\n",strlen(m),sizeof(m));
	printf("%d,%d\n",INT_MIN,INT_MAX);
	printf("%llu\n",ULLONG_MAX);
	printf("%.38f\n",FLT_EPSILON);
	printf("%2.2f\n",3.248);
	return 0;
}
 	
