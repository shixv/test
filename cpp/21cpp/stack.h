#include <stdlib.h>
typedef struct _Node{
	int data;
	struct _Node* next;
}Node;
typedef struct _Stack{
	int length;
	Node* top;
}Stack;
Stack* initStack(void){
	Stack* s=(Stack*)malloc(sizeof(Stack));
	s->length=0;
	return s;
}
void pop(Stack* s){
	if(s->length<=0)return;
	Node* temp=s->top;
	s->top=s->top->next;
	--(s->length);
	free(temp);
}
int top(Stack* s){
	if(s->length<=0)return 0;
	return s->top->data;
}
void push(Stack* s,int data){
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=data;temp->next=s->top;s->top=temp;
	s->length++;
}
void freeStack(Stack* s){
	if(s==NULL)return;
	if(s->top==NULL){free(s);return;}
	while(s->length>0)pop(s);
	free(s);
}


typedef struct _Queue{
	int length;
	Node* head;
	Node* rear;
}Queue;
Queue* initQueue(void){
	Queue* q=(Queue*)malloc(sizeof(Queue));
	q->length=0;
	q->head=q->rear=NULL;
	return q;
}
void enque(Queue* q,int data){
	Node* temp=(Node*)malloc(sizeof(Node));
	temp->data=data;
	temp->next=NULL;
	if(q->length==0){
		q->rear=temp;
		q->head=q->rear;	
	}
	q->rear->next=temp;
	q->rear=temp;
	q->length++;
}
int head(Queue* q){
	if(q->length==0)return 0;
	return q->head->data;
}
void deque(Queue* q){
	if(q->length==0)return;
	if(q->length==1){
		free(q->head);
		q->head=q->rear=NULL;
		q->length--;
		return;
	}
	Node* temp=q->head;
	q->head=q->head->next;
	free(temp);
	q->length--;
}
void freeQueue(Queue* q){
	while(q->length!=0){
		deque(q);
	}
	free(q);
}
