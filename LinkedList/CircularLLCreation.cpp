#include<iostream>
using namespace std;
#include<malloc.h>
struct node {
	int data;
	struct node *next;
};
struct node *head=0,*tail=0;
void create(){
	struct node *newnode=0;
	int choice=1;
	while(choice){
	newnode=(struct node *)malloc(sizeof(struct node));
	cout<<"Enter the data: ";
	cin>>newnode->data;
	newnode->next=0;
	if(head==0){
		head=tail=newnode;
	}
	else{
		tail->next=newnode;
		tail=newnode;
	}
	tail->next=head;
	cout<<"Continue: 1(yes) or 0(no): ";
	cin>>choice;
  }
}
void display(){
	struct node *temp=0;
	temp=head;
	cout<<"\n\nElements in the circular linked list: ";
	while(temp->next!=head){
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
	cout<<temp->data;
}
int main(){
	create();
	display();
}
