#include"SeqStack.h"
//��ʼ��
SeqStack* Init_SeqStack(){
	SeqStack* stack = (SeqStack*)malloc(sizeof(SeqStack));
	if (stack == NULL){
		return NULL;
	}
	for (int i = 0; i < MAXSIZE;i++){
		stack->data[i] = NULL;
	}
	stack->length = 0;
	return stack;
}
//��ջ
void Push_SeqStack(SeqStack* stack, void* data){
	if (stack == NULL || data == NULL){
		return;
	}
	if (stack->length == MAXSIZE){
		return;
	}
	stack->data[stack->length] = data;
	stack->length++;
}
//��ջ
void Pop_SeqStack(SeqStack* stack){
	if (stack == NULL){
		return;
	}
	stack->data[stack->length - 1] = NULL;
	stack->length--;
}
//���ջ��Ԫ��
void* Top_SeqStack(SeqStack* stack){
	if (stack == NULL){
		return NULL;
	}
	return stack->data[stack->length - 1];
}
//���ջ��С
int Length_SeqStack(SeqStack* stack){
	if (stack == NULL){
		return -1;
	}
	return stack->length;
}
//���ջ
void Clear_SeqStack(SeqStack* stack){
	if (stack == NULL){
		return;
	}
	while (Length_SeqStack(stack) > 0){
		Pop_SeqStack(stack);
	}
}
//����ջ
void Destroy_SeqStack(SeqStack** stack){
	if (stack == NULL){
		return;
	}
	free(*stack);
	*stack = NULL;
}
