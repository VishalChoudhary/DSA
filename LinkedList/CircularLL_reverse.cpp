#include<iostream>
using namespace std;
#include<malloc.h>
struct node {
	int data;
	struct node *next;
};
struct node *tail=0;
void create(){
	struct node *newnode=0;
	newnode=(struct node *)malloc(sizeof(struct node));
	cout<<"Enter the data: ";
	cin>>newnode->data;
	newnode->next=0;
	if(tail==0){
		tail=newnode;
		tail->next=newnode;
	}
	else{
		newnode->next=tail->next;
		tail->next=newnode;
		tail=newnode;
	}
}

void reverse(){
	struct node *currnode,*prevnode,*nextnode;
	currnode=tail->next;
	nextnode=currnode->next;
	if(tail==0){
		cout<<"list empty";
	}
	else{
		while(currnode!=tail){
			prevnode=currnode;
			currnode=nextnode;
			nextnode=currnode->next;
			currnode->next=prevnode;
		}
		nextnode->next=tail;
		tail=nextnode;
	}
}

void display(){
	struct node *temp=0;
	temp=tail->next;
	cout<<"\n\nElements in the circular linked list: ";
	while(temp->next!=tail->next){
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
	cout<<temp->data;
}

int main(){
	for(int i=0;i<5;i++){
		create();
	}
	reverse();
	display();
}
