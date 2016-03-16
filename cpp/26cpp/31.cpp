#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 2048
int GetLinesFile(FILE* fp){
	char buf[MAXLINE];
	memset(buf,0,MAXLINE);
	int index=0;
	while(fgets(buf,MAXLINE,fp)!=NULL){
		index++;
	}
	return index;
}
int ReadFile(const char* fileName,char*** fileData,int* lines){
	if(fileName==NULL||lines==NULL){
		printf("canshuyouwu\n");
		return -1;
	}
	FILE* fp=fopen(fileName,"r");
	if(fp==NULL){
		printf("wnejian%sdakaishibaio\n",fileName);
		return -2;
	}
	int totalLines=getLinesFile(fp);
	if(totalLines==0){
		printf("wenjianweikong1");
		return -3;
	}
	char** mylines=(char**)malloc(sizeof(char*)*totalLines);
	if(mylines==NULL){
		printf("geihangkaipineicunshibai\n");
		return -4;
	}
	fseek(fp,0,SEEK_SET);
	char buf[MAXLINE];
	memset(buf,0,MAXLINE);
	int index=0;
	while(fgets(buf,MAXLINE,fp)!=NULL){
		int texgtLength=strlne(buf)+1;
		mylines[index]=(char*)malloc(textLength);
		memset(mylines[index],0,textLength);
		if(mylines[index]==NULL){
			for(int i=index-1;i>=0;i--){
				free(mylines[i]);
			}
			free(mylines);
			return -5;
		}
		strcpy(mylines[index],buf);
		index++;
	}
	*fileData=mylines;
	*lines=totalLines;
	fclose(fp);
	return 0;
}
void PrintFile(char** fileData,int len){
	for(int i=0;i<len;i++){
		printf("%s",fileData[i]);
	}
}
void FreeSpace(char*** fileData,int lines){
	if(fileData==NULL){
		return;
	}
	for(int i=0;i<lines;i++){
		if(fileData[i]!=NULL){
			free(fileData[i]);
		}
	}
	free(fileData);
}
int main(void){
	const char* fileName="a.txt";
	char** fileData=NULL;
	int lines=0;
	if(ReadFile(fileName,&fileData,&lines)<0){
		printf("wenjianduqucuowu!\n");
		return 0;
	}
	PrintFile(fileData,lines);
	FreeSpace(fileData,lines);
	fileData=NULL;
	lines=0;
	system("pause");
	return EXIT_SUCCESS;
}
