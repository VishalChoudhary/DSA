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
void insert_beg(){
	struct node *newnode=0;
	newnode=(struct node*)malloc(sizeof(struct node));
	cout<<"\nEnter the elements at the begining of the Linked List: ";
	cin>>newnode->data;
	newnode->next=0;
	newnode->next=head;
	head=newnode;
}
void insert_end(){
	struct node *newnode=0, *temp=0;
	newnode=(struct node*)malloc(sizeof(struct node));
	cout<<"\nEnter the elements at the end of the Linked List: ";
	cin>>newnode->data;
	newnode->next=0;
	temp=head;
	while(temp->next!=0){
		temp=temp->next;
	}
	temp->next=newnode;
	temp=newnode;
}
void insert_pos(){
	int i=1,pos=0;
	cout<<"Enter the position: ";
	cin>>pos;
	struct node *newnode=0, *temp=0;
	newnode=(struct node*)malloc(sizeof(struct node));
	cout<<"\nEnter the elements at the given position: ";
	cin>>newnode->data;
	newnode->next=0;
	temp=head;
	while(i<pos){
		temp=temp->next;
		i++;
	}
	newnode->next=temp->next;
	temp->next=newnode;	
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
	int choice=1;
	while(choice){
		int x;
	    cout<<"\nEnter your choice: \n1.Insert at begining of the linked list \n2.Insert the end of the linked list\n3.Insert at the given position\n\n";
	    cin>>x;
	    switch(x){
		    case 1:
		    insert_beg();
	        display();
	        break;
	        case 2:
	        insert_end();
	        display();
	        break;
	        case 3:
	        insert_pos();
	        display();
	        break;
            default:cout<<"Invalid Option";
	    }
	    cout<<"\n\nContniue? 0 or 1: ";
		cin>>choice;
	}
}
