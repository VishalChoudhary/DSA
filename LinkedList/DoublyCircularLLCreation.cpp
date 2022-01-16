#include<iostream>
using namespace std;
#include<malloc.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head,*tail;
void createDCLL(){
	head=tail=0;
	struct node *newnode=0;
	int choice=1;
	while(choice){
		newnode=(struct node *)malloc(sizeof(struct node));
	    cout<<"\nEnter the data: ";
    	cin>>newnode->data;
    	newnode->next=0;
    	newnode->prev=0;
    	if(head==0){
    		head=tail=newnode;
    		head->next=head;
    		head->prev=head;
    	}
    	else{
    		tail->next=newnode;
    		newnode->prev=tail;
    		newnode->next=head;
		    head->prev=newnode;
		    tail=newnode;
    	}
    	cout<<"Continue: 1(yes) or 0(no): ";
    	cin>>choice;
	}
}
void display(){
	struct node *temp=0;
	temp=head;
	cout<<"\n\nElements in the doubly circular linked list: ";
	while(temp!=tail){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<temp->data;
}
int main(){
	createDCLL();
	display();
}
