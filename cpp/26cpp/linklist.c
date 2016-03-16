#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
	int data;
	struct _Node* next;
}Node;
typedef struct _List{
	Node* head;
	int len;
}List;

List* Initlist(){
	List* temp=(List*)malloc(sizeof(List));
	temp->head=(Node*)malloc(sizeof(Node));
	temp->len=0;
	return temp;
}
void Destroylist(List* l){
	while(l->head!=NULL){
		Node* temp=l->head;
		l->head=l->head->next;
		free(temp);
	}
	free(l);
}
void Insert(List* l,int pos,int data){
	if(l==NULL)
		return;
	if(pos>l->len)return;
	Node* temp=l->head;
	for(int i=0;i<pos;i++){
		temp=temp->next;
	}
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->data=data;
	newnode->next=temp->next;
	temp->next=newnode;
	l->len++;
}
void Remove(List* l,int pos){
	if(l==NULL||l->len==0)
		return;
	if(pos>l->len)return;
	Node* temp=l->head;
	for(int i=0;i<pos;i++){
		temp=temp->next;
	}
	Node* temp1=temp->next;
	temp->next=temp->next->next;
	free(temp1);
	l->len--;
}
void printlist(List* l){
	Node* temp=l->head->next;
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
}
int main(void){
	List* l=Initlist();
	Insert(l,0,1);
	Insert(l,0,2);
	Insert(l,0,3);
	Insert(l,0,4);
	Insert(l,0,5);
	Insert(l,0,6);
	Insert(l,0,7);
	printlist(l);
	printf("\n");
	Remove(l,1);
	printlist(l);
	Destroylist(l);
	return 0;
}
