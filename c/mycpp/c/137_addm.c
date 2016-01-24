#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
	if(argc<4)return 0;
	switch(*argv[2])
	{
	case '+' : printf("%d\n",atoi(argv[1])+atoi(argv[3]));break;
	case '-' : printf("%d\n",atoi(argv[1])-atoi(argv[3]));break;
	case '*' : printf("%d\n",atoi(argv[1])*atoi(argv[3]));break;
	case '/' : printf("%d\n",atoi(argv[1])/atoi(argv[3]));break;
	default : break;
	}
	return 0;
}
