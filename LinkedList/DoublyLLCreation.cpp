#include<iostream>
using namespace std;
#include<malloc.h>
struct node {
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=0;
void create(){
	struct node *newnode=0,*temp=0;
	int choice=1;
	while(choice){
	newnode=(struct node *)malloc(sizeof(struct node));
	cout<<"Enter the data: ";
	cin>>newnode->data;
	newnode->next=0;
	newnode->prev=0;
	if(head==0){
		head=temp=newnode;
	}
	else{
		temp->next=newnode;
		newnode->prev=temp;
		temp=newnode;
	}
	cout<<"Continue: 1(yes) or 0(no): ";
	cin>>choice;
  }
}
void display(){
	struct node *temp=0;
	temp=head;
	cout<<"\n\nElements in the diubly linked list: ";
	while(temp!=0){
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
}
int main(){
	create();
	display();
	return 0;
}
