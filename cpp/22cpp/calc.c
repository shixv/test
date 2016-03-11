#include "stack.h"
#include <stdio.h>
#include <ctype.h>
int convert(char a){
	if(a=='+')return 0;
	if(a=='-')return 1;
	if(a=='*')return 2;
	if(a=='/')return 3;
	if(a=='(')return 4;
	return 5;
}
int prioritycompare(char a,char b)//a->top b->push
{
	if(a=='\n')return 1;
	static int arr[5][4]={
		{0,0,1,1},
		{0,0,1,1},
		{0,0,0,0},
		{0,0,0,0},
		{1,1,1,1}
	};
	int x=convert(a);
	int y=convert(b);
	if(x==5||y==5)return -1;
	return arr[x][y];
}
void switchoperator(Stack* temp,char ch){
	int a,b;
	a=top(temp);
	pop(temp);
	b=top(temp);
	pop(temp);
	switch(ch){
		case '+':
			push(temp,b+a);
			break;
		case '-':
			push(temp,b-a);
			break;
		case '*':
			push(temp,b*a);
			break;
		case '/':
			push(temp,b/a);
			break;
	}
}
int main(int argc,char* argv[])
{
	Stack* temp=initStack();
	Queue* postfix=initQueue();
	push(temp,'\n');
	for(int i=0;argv[1][i]!='\0';i++){
		if(isdigit(argv[1][i])){
			enque(postfix,argv[1][i]);
			if(!isdigit(argv[1][i+1]))
				enque(postfix,' ');
			continue;
		}
		if(argv[1][i]=='('){push(temp,'(');continue;}
		if(argv[1][i]==')'){
			while(top(temp)!='('){
				enque(postfix,top(temp));
				pop(temp);
			}
			pop(temp);
			continue;
		}
		if(prioritycompare(top(temp),argv[1][i])==-1)continue;
		if(prioritycompare(top(temp),argv[1][i])){
			push(temp,argv[1][i]);
			continue;
		}
		while(prioritycompare(top(temp),argv[1][i])==0){
			enque(postfix,top(temp));
			pop(temp);
		}
		push(temp,argv[1][i]);
	}
	while(temp->length!=0){
		enque(postfix,top(temp));
		pop(temp);
	}
	freeStack(temp);
	temp=initStack();
	char ch;
	int preflag=1;
	int curflag=0;
	while((ch=head(postfix))!='\n'){
		curflag=!isdigit(ch);
		if(!curflag){
			if(preflag){
				push(temp,ch-'0');
			}else{
				int sum=top(temp);
				pop(temp);
				sum=sum*10+ch-'0';
				push(temp,sum);
			}
			deque(postfix);
			preflag=curflag;
			continue;		
		}
		if(ch==' '){deque(postfix);preflag=curflag;continue;}
		switchoperator(temp,ch);
		deque(postfix);
		preflag=curflag;
	}
	printf("%d\n",top(temp));
	freeStack(temp);
	freeQueue(postfix);
	return 0;
}
