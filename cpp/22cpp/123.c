#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SeqStack.h"
//二叉树结点
typedef struct _BiNode{
	char data;
	struct BiNode* lchild;
	struct BiNode* rchild;
}BiNode;
//递归遍历
void Recursion(BiNode* root){
	if (root == NULL){
		return;
	}
	printf("%c",root->data); //先序遍历
	//遍历左子树
	Recursion(root->lchild);
	//printf("%c", root->data); //中序遍历
	//遍历右子树
	Recursion(root->rchild);
	//printf("%c", root->data); //后序遍历
}
//树的非递归先序遍历
void NonRecursion(BiNode* root){
	BiNode* pChild = root;
	//创建栈
	SeqStack* stack = Init_SeqStack();
	while (Length_SeqStack(stack) > 0 || pChild){
		while (pChild){
			printf("%c",pChild->data);
			//入栈
			Push_SeqStack(stack,pChild);
			//继续向左找
			pChild = pChild->lchild;
		}
		//从栈中弹出数据
		if (Length_SeqStack(stack) > 0){
			//从栈中弹出栈顶元素，根据栈顶元素拿到右子树
			BiNode* node = (BiNode*)Top_SeqStack(stack);
			Pop_SeqStack(stack);
			pChild = node->rchild;
		}
	}
}
void test01(){
	//创建结点
	BiNode node1 = { 'A', NULL, NULL };
	BiNode node2 = { 'B', NULL, NULL };
	BiNode node3 = { 'C', NULL, NULL };
	BiNode node4 = { 'D', NULL, NULL };
	BiNode node5 = { 'E', NULL, NULL };
	BiNode node6 = { 'F', NULL, NULL };
	BiNode node7 = { 'G', NULL, NULL };
	BiNode node8 = { 'H', NULL, NULL };
	//建立结点关系
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;
	Recursion(&node1);
	printf("\n");
	printf("二叉树的非递归遍历:\n");
	NonRecursion(&node1);
}
int main(){
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
