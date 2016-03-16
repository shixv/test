#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLINE 2048
//统计文件行数
int GetLinesFile(FILE* fp){
	char buf[MAXLINE];
	memset(buf, 0, MAXLINE);
	int index = 0;
	while (fgets(buf, MAXLINE,fp) != NULL){
		index++;
	}
	return index;
}
int ReadFile(const char* fileName, char*** fileData,int* lines){
	if (fileName == NULL || lines == NULL){
		printf("穿入的参数有误!\n");
		return -1;
	}
	//打开文件
	FILE* fp = fopen(fileName,"r");
	if (fp == NULL){
		printf("文件%s打开失败!\n",fileName);
		return -2;
	}
	//获得文件的行数
	int totalLines =  GetLinesFile(fp);
	if (totalLines == 0){
		printf("文件为空!");
		return -3;
	}
	//给行开辟内存
	char** mylines = (char**)malloc(sizeof(char*)*totalLines);
	if (mylines == NULL){
		printf("给行开辟内存失败!\n");
		return -4;
	}
	//把文件指针设置到头部
	fseek(fp,0,SEEK_SET);
	//读文件
	char buf[MAXLINE];
	memset(buf,0,MAXLINE);
	int index = 0;
	while (fgets(buf, MAXLINE,fp) != NULL){
		//当前行的长度
		int textLength = strlen(buf) + 1;
		mylines[index] = (char*)malloc(textLength);
		memset(mylines[index], 0, textLength);
		if (mylines[index] == NULL){
			for (int i = index - 1; i >= 0; i--){
				free(mylines[i]);
			}
			free(mylines);
			return -5;
		}
		strcpy(mylines[index],buf);
		index++;
	}
	//间接赋值
	*fileData = mylines;
	*lines = totalLines;
	fclose(fp);
	return 0;
}
//打印文件内容
void PrintFile(char** fileData,int len){
	for (int i = 0; i < len;i++){
		printf("%s", fileData[i]);
	}
}
//释放空间的内存
void FreeSpace(char** fileData, int lines){
	if (fileData == NULL){
		return;
	}
	for (int i = 0; i < lines;i ++){
		if (fileData[i] != NULL){
			free(fileData[i]);
		}
	}
	free(fileData);
}
int main(){
	//文件名
	const char* fileName = "a.txt";
	//指针
	char** fileData = NULL;
	//文件的行数
	int lines = 0;
	if (ReadFile(fileName, &fileData, &lines) < 0){
		printf("文件读取错误!\n");
		return 0;
	}
	//打印文件内容
	PrintFile(fileData, lines);
	//释放自己开辟内存
	FreeSpace(fileData, lines);
	fileData = NULL;
	lines = 0;
	system("pause");
	return EXIT_SUCCESS;
}
