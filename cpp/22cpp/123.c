#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SeqStack.h"
//���������
typedef struct _BiNode{
	char data;
	struct BiNode* lchild;
	struct BiNode* rchild;
}BiNode;
//�ݹ����
void Recursion(BiNode* root){
	if (root == NULL){
		return;
	}
	printf("%c",root->data); //�������
	//����������
	Recursion(root->lchild);
	//printf("%c", root->data); //�������
	//����������
	Recursion(root->rchild);
	//printf("%c", root->data); //�������
}
//���ķǵݹ��������
void NonRecursion(BiNode* root){
	BiNode* pChild = root;
	//����ջ
	SeqStack* stack = Init_SeqStack();
	while (Length_SeqStack(stack) > 0 || pChild){
		while (pChild){
			printf("%c",pChild->data);
			//��ջ
			Push_SeqStack(stack,pChild);
			//����������
			pChild = pChild->lchild;
		}
		//��ջ�е�������
		if (Length_SeqStack(stack) > 0){
			//��ջ�е���ջ��Ԫ�أ�����ջ��Ԫ���õ�������
			BiNode* node = (BiNode*)Top_SeqStack(stack);
			Pop_SeqStack(stack);
			pChild = node->rchild;
		}
	}
}
void test01(){
	//�������
	BiNode node1 = { 'A', NULL, NULL };
	BiNode node2 = { 'B', NULL, NULL };
	BiNode node3 = { 'C', NULL, NULL };
	BiNode node4 = { 'D', NULL, NULL };
	BiNode node5 = { 'E', NULL, NULL };
	BiNode node6 = { 'F', NULL, NULL };
	BiNode node7 = { 'G', NULL, NULL };
	BiNode node8 = { 'H', NULL, NULL };
	//��������ϵ
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;
	Recursion(&node1);
	printf("\n");
	printf("�������ķǵݹ����:\n");
	NonRecursion(&node1);
}
int main(){
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
