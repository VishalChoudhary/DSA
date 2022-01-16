#include<iostream>
using namespace std;
#include<malloc.h>
int main(){
	struct node{
		int data;
		struct node *next;
	};	
	struct node *temp=0,*newnode=0,*head=0;
	int choice=1;
	while(choice){
		newnode=(struct node *)malloc(sizeof(struct node ));
		cout<<"Enter the data: ";
		cin>>newnode->data;
		newnode->next=0;
		if(head==0){
			head=temp=newnode;
		}
		else{
			temp->next=newnode;
			temp=newnode;
		}
		cout<<"Contniue? 0 or 1: ";
		cin>>choice;
	}
	temp=head;
	cout<<"\nElements in the linked list: ";
	while(temp!=0){
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
}
