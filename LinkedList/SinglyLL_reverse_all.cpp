#include<iostream>
#include<malloc.h>
using namespace std;
struct node{
	int data;
	struct node *next;
};
struct node *head=0,*ptr=0;
void insert(){
	struct node *newnode=0;
	newnode=(struct node*)malloc(sizeof(struct node));
	cout<<"Enter the elements: ";
	cin>>newnode->data;
	newnode->next=0;
	if(head==0){
		head=ptr=newnode;
	}
	else{
		ptr->next=newnode;
		ptr=newnode;
	}
}

void reverse(){
	struct node *nextnode,*currnode,*prevnode=0;
	nextnode=currnode=head;
	while(nextnode!=0){
		nextnode=nextnode->next;
		currnode->next=prevnode;
		prevnode=currnode;
		currnode=nextnode;
	}
	head=prevnode;
}

void display(){
	struct node *temp=0;
	temp=head;
	cout<<"\nElements in the Linked List: ";
	while(temp!=0){
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
}
int main(){
	for(int i=0;i<5;i++){
		insert();
	}
	reverse();
	display();
}
