#include<iostream>
#include<malloc.h>
using namespace std;
struct node{
	int data;
	struct node *next;
}*front=0,*rear=0;

void enqueue(int x){
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=0;
	if(front==0 && rear==0){
		front=rear=newnode;
	}
	else{
		rear->next=newnode;
		rear=newnode;
	}
}

void dequeue(){
	if(front==0 && rear==0){
		cout<<"\nQueue is empty"<<endl;
	}
	else{
		struct node *temp=0;
		temp=front;
		front=front->next;
		free(temp);
	}
}

void peek(){
	if(front==0 && rear==0){
		cout<<"Queue is empty"<<endl;
	}
	else{
		cout<<"\nPeek Element in the Queue: "<<front->data;
	}
}

void display(){
	if(front==0 && rear==0){
		cout<<"Queue is empty"<<endl;
	}
	else{
		struct node *temp=0;
		temp=front;
		cout<<"\nElements in the Queue: ";
		while(temp!=0){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
}

int main(){
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	enqueue(6);
	enqueue(7);
	peek();
	dequeue();
	dequeue();
	display();
	peek();
}
