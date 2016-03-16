#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLINE 2048
//ͳ���ļ�����
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
		printf("����Ĳ�������!\n");
		return -1;
	}
	//���ļ�
	FILE* fp = fopen(fileName,"r");
	if (fp == NULL){
		printf("�ļ�%s��ʧ��!\n",fileName);
		return -2;
	}
	//����ļ�������
	int totalLines =  GetLinesFile(fp);
	if (totalLines == 0){
		printf("�ļ�Ϊ��!");
		return -3;
	}
	//���п����ڴ�
	char** mylines = (char**)malloc(sizeof(char*)*totalLines);
	if (mylines == NULL){
		printf("���п����ڴ�ʧ��!\n");
		return -4;
	}
	//���ļ�ָ�����õ�ͷ��
	fseek(fp,0,SEEK_SET);
	//���ļ�
	char buf[MAXLINE];
	memset(buf,0,MAXLINE);
	int index = 0;
	while (fgets(buf, MAXLINE,fp) != NULL){
		//��ǰ�еĳ���
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
	//��Ӹ�ֵ
	*fileData = mylines;
	*lines = totalLines;
	fclose(fp);
	return 0;
}
//��ӡ�ļ�����
void PrintFile(char** fileData,int len){
	for (int i = 0; i < len;i++){
		printf("%s", fileData[i]);
	}
}
//�ͷſռ���ڴ�
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
	//�ļ���
	const char* fileName = "a.txt";
	//ָ��
	char** fileData = NULL;
	//�ļ�������
	int lines = 0;
	if (ReadFile(fileName, &fileData, &lines) < 0){
		printf("�ļ���ȡ����!\n");
		return 0;
	}
	//��ӡ�ļ�����
	PrintFile(fileData, lines);
	//�ͷ��Լ������ڴ�
	FreeSpace(fileData, lines);
	fileData = NULL;
	lines = 0;
	system("pause");
	return EXIT_SUCCESS;
}
