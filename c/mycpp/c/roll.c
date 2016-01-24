#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

unsigned long rollem(unsigned long dice);
int main(int argc,char *argv[])
{
/*	unsigned long n,i,d,m,j;
	srand((unsigned long)time(0));
	switch(argc){
		case 1:{n=10lu;d=6lu;m=1lu;break;}
		case 2:{n=(unsigned long)atoi(argv[1]);m=1lu;d=6lu;break;}
		case 3:{n=(unsigned long)atoi(argv[1]);m=(unsigned long)atoi(argv[2]);d=6lu;break;}
		default:{n=(unsigned long)atoi(argv[1]);m=(unsigned long)atoi(argv[2]);d=(unsigned long)atoi(argv[3]);break;}
	}*/
	int i,j,k;
	unsigned long c = 1lu;
	unsigned long m = 1lu;
	unsigned long d = 6lu;
	unsigned long s;
	s = (unsigned long)time(0);
	
	if(argc==1){printf("掷骰子程序用法：[选项][数字]\n               -c 掷的次数\n               -m 骰子个数\n               -d 骰子面数\n               -s 指定随机数种子\n");printf("默认数是c=1,m=1,d=6\n\n");}
	int opt;
	while((opt=getopt(argc,argv,"c:m:d:s:"))!=-1){
		switch(opt){
			case 'c':c=(unsigned long)atoi(optarg);break;
			case 'm':m=(unsigned long)atoi(optarg);break;
			case 'd':d=(unsigned long)atoi(optarg);break;
			case 's':s=(unsigned long)atoi(optarg);break;
			default:return 0;
//			case '?':fprintf(stderr,"未知参数: %c\n",optopt);return 1;
//			case ':':fprintf(stderr,"参数需要变量.\n");return 1;
		}
	}
/*	for(k=1;k<argc;k++)
	{
		if(*argv[k]=='-')
		{
			switch(argv[k][1])
			{
				case 'c':{if(k!=(argc-1))c=(unsigned long)atoi(argv[k+1]);continue;}
				case 'm':{if(k!=(argc-1))m=(unsigned long)atoi(argv[k+1]);continue;}
				case 'd':{if(k!=(argc-1))d=(unsigned long)atoi(argv[k+1]);continue;}
				case 's':{if(k!=(argc-1))s=(unsigned long)atoi(argv[k+1]);continue;}
				default:continue;
			}
		}
	}
*/	
	printf("你一共掷了%lu次%lu个%lu面骰子，结果如下：\n",c,m,d);
	srand(s);
	for(i=1;i<=c;i++)
	{
		printf("[");
		for(j=1;j<=m;j++)
		{
			printf("%lu,",rollem(d));
		}
		printf("\b]\n");
	}
	putchar('\n');
	return 0;
}
unsigned long rollem(unsigned long dice)
{
	return (unsigned long)rand()%(unsigned long)dice+1lu;
}
	
