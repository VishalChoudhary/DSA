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
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	cout<<"Enter the data: ";
	cin>>newnode->data;
	newnode->next=newnode->prev=0;
	if(head==0){
		head=tail=newnode;
		head->prev=head;
		head->next=head;
	}
	else{
		tail->next=newnode;
		newnode->prev=tail;
		newnode->next=head;
		head->prev=newnode;
		tail=newnode;
	}
}
void del_beg(){
	struct node *temp=0;
	temp=head;
	if(head==0)
	cout<<"list is empty";
	else if(head->next==head){
		head=tail=0;
		free(temp);
	}
	else{
		head=head->next;
		head->prev=tail;
		tail->next=head;
		free(temp);
	}
}
void del_end(){
	struct node *temp=0;
	temp=tail;
	if(head==0)
	cout<<"list is empty";
	else if(head->next==head){
		head=tail=0;
		free(temp);
	}
	else{
		tail=tail->prev;
		tail->next=head;
		head->prev=tail;
		free(temp);
	}
}
void del_pos(){
	struct node *temp=0;
	int i=1,pos=0;
	cout<<"\nEnter the position: ";
	cin>>pos;
	temp=head;
	if(pos<0)
	cout<<"list is empty";
	else if(pos==1)
	del_beg();
	else{
		while(i<pos){
			temp=temp->next;
			i++;
		}
		temp->next->prev=temp->prev;
		temp->prev->next=temp->next;
		if(temp->next==head){
			tail=temp->prev;
			free(temp);
		}	
		else
		free(temp);
	}
}
void display(){
	struct node *temp=0;
	temp=head;
	cout<<"elements: ";
	while(temp!=tail){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<temp->data;
}
int main(){
	for(int i=0;i<5;i++){
		createDCLL();
	}
	int x;
	cout<<"\nEnter your choice: \n1.Delete from begining of the linked list \n2.Delete from the end of the linked list\n3.Delete from the given position\n\n";
	cin>>x;
	switch(x){
		case 1:
		del_beg();
	    display();
	    break;
	    case 2:
	    del_end();
	    display();
	    break;
	    case 3:
	    del_pos();
	    display();
	    break;
        default:cout<<"Invalid Option";
	}
}
