#include <iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
};
class Link{
	public:
	Node* head;
	public:
	Link(){
		Node* h=head=new Node;
		h->data=1;
		h->next=NULL;
		for(int i=2;i<11;i++){
			h=h->next=new Node;
			h->data=i;
			h->next=NULL;
		}
		h=head;
		while(h!=NULL){
			cout<<h->data<<endl;
			h=h->next;
		}
		cout<<"while"<<endl;

	}
	Node* findn(int n){
		int temp=0;
		Node* h=head;
		while(h!=NULL){h=h->next;temp++;}
		h=head;
		for(int i=0;i<temp-n;i++){
			h=h->next;
		}
		return h;
	}
};
int main(void)
{
	Link l;
	cout<<l.findn(2)->data<<endl;
	return 0;
}
