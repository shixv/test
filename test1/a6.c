#include <stdio.h>

struct student
{
	char name[20];
	int age;
};
int delete(void)
{
	FILE *p=fopen("b.dat","r");
	if(!p)
		return 0;
	long int curset;
	printf("please int put name:\n");
	char name[20];
	scanf("%s",name);
	int flag=1;
	struct student st={
		0
	};
	int rc;
	while(1)
	{
		rc=fread(&st,sizeof(struct student),1,p);
		if(rc==0)
			break;
		if(strcmp(name,st.name)==0)
		{
			flag=0;
			curset=ftell(p);
			break;
		}
		else
		{
			continue;
		}
	}
	if(flag)
	{
		printf("no name\n");
		return 0;
	}
	fclose(p);
//	printf("%ld\n",curset);
//	return 0;
	p=fopen("b.dat","a+");
	if(!p)
		return 0;
	long int i=0L;
	while(i<(long int)sizeof(struct student))
	{
		fseek(p,curset+i,SEEK_SET);
		rc=fread(&st,sizeof(struct student),1,p);
		if(rc==0)
			break;
		fseek(p,curset-(long int)sizeof(struct student)+i,SEEK_SET);
		fwrite(&st,sizeof(struct student),1,p);
		i++;
	}
	fclose(p);
	return 0;
}
int input()
{
	FILE *p = fopen("b.dat", "ab");
	if (!p)
		return 0;
	while(1)
	{
		struct student st = { 0 };
		printf("please input name:");
		scanf("%s", st.name);
		printf("please input age:");
		scanf("%d", &st.age);
		if (st.age < 0)
			break;
		fwrite(&st, sizeof(struct student), 1, p);
	}
	fclose(p);
	return 0;
}

int select()
{
	FILE *p = fopen("b.dat", "rb");
	if (!p)
		return 0;
	printf("please input name: \n");
	char name[20];
	scanf("%s",name);
	int flag=1;
	while(1)
	{
		struct student st = { 0 };
		int rc = fread(&st, sizeof(struct student), 1, p);
		if (rc == 0)//到了最后，什么也读不出来了，所以返回值是0
			break;
		if(strcmp(name,st.name)==0)
		{
			printf("name = %s,age = %d\n",st.name,st.age);
			flag=0;
			break;
		}
		else
		{
			continue;
		}
	}
	if(flag)
	{
		printf("no name\n");
	}

	fclose(p);
	return 0;
}

int main(int argc, char **args)
{
	if (argc < 2)
		return 0;

	if (args[1][0] == '0')
		input();
	if (args[1][0] == '1')
		select();
	if(args[1][0]=='2')
		delete();
	return 0;
}
