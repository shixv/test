#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILENAM "prime.dat"

int isPrime(int *array,int n)
{
	if(n<2)
		return 0;
	int i=0;
	while((array[i]!=0)&&(array[i]*array[i]<=n))
	{
		if(n%array[i]==0)
			return 0;
		i++;
	}
	return 1;
}
int *CreatePrimeArray(int count)
{
	if(count<1)
		return NULL;
	int *array=(int *)malloc(sizeof(int)*count);
	array[0]=2;
	memset(array+1,0,sizeof(int)*(count-1));
	int i=1,j=3;
	while(i<count)
	{
		if(isPrime(array,j))
			array[i++]=j;
		j++;
	}
	return array;
}
int *readfile(char *filename,int *count)
{
	FILE *fp=fopen(filename,"r");
	*count=0;
	int n;
	while(fread(&n,sizeof(int),1,fp)!=0)(*count)++;
	fseek(fp,0,SEEK_SET);
	int *array=(int *)malloc(sizeof(int)*(*count));
	fread(array,sizeof(int),*count,fp);
	fclose(fp);
	return array;
}
int *AttendPrimeArray(int *array,int count,int attendcount)
{
	if(attendcount<1)
		return array;
	array=(int *)realloc(array,(count+attendcount)*sizeof(int));
	memset(array+count,0,attendcount);
	int i=count;
	int j=array[count-1]+1;
	while(i<count+attendcount)
	{
		if(isPrime(array,j))
			array[i++]=j;
		j++;
	}
	return array;
}

void writefile(char *filename,int *array,int count)
{
	FILE *fp=fopen(filename,"w");
	fwrite(array,sizeof(int),count,fp);
	free(array);
	fclose(fp);
}
int main(int argc,char *argv[])
{
	int *array=NULL;
	int count=0;
	FILE *fp=NULL;
	if((fp=fopen(FILENAM,"r"))==NULL)
	{
		array=CreatePrimeArray(atoi(argv[1]));
		writefile(FILENAM,array,atoi(argv[1]));	
	}
	else
	{
		fclose(fp);
		array=readfile(FILENAM,&count);
		array=AttendPrimeArray(array,count,atoi(argv[1]));
		writefile(FILENAM,array,count+atoi(argv[1]));
	}
	return 0;
}
