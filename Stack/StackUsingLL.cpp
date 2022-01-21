#include<iostream>
#include<malloc.h>
using namespace std;
struct node{
	int data;
	struct node *next;
};
struct node *top=0;
void push(int x){
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=top;
	top=newnode;
}
void pop(){
	struct node *temp;
	temp=top;
	if(top==0){
		cout<<"Stack Underflow"<<endl;
	}
	else{
		cout<<"\nDeleted item from the stack is: "<<top->data<<endl;
	    top=top->next;
    	free(temp);
	}
}
void peek(){
	if(top==0){
		cout<<"Stack Underflow"<<endl;
	}
	else{
		cout<<"\nElement at the top of the stack: "<<top->data<<endl;
	}
}
void display(){
	struct node *temp;
	temp=top;
	if(top==0){
		cout<<"Stack Underflow"<<endl;
	}
	else{
		cout<<"Elements in the Stack: ";
		while(temp!=0){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
}
int main(){
	push(4);
	push(8);
	push(1);
	push(6);
	push(3);
	display();
	peek();
	pop();
	display();
}
