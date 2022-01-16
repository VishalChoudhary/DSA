#include<iostream>
using namespace std;
#include<malloc.h>
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

void del_beg(){
	struct node *temp;
	temp=head;
	head=head->next;
	free(temp);
}

void del_end(){
	struct node *temp=0,*prevnode=0;
	temp=head;
	while(temp->next!=0){
		prevnode=temp;
		temp=temp->next;
	}
	if(head==temp){
		free(temp);
	}
	else{
	prevnode->next=0;
	free(temp);
    }
}

void del_pos(){
	struct node *temp=0,*prevnode=0;
	int i=1,pos=0;
	cout<<"\nEnter the position: ";
	cin>>pos;
	temp=head;
	while(i<pos){
		prevnode=temp;
		temp=temp->next;
		i++;
	}
	prevnode->next=temp->next;
	temp->next=0;
	free(temp);
}

void display(){
	struct node *temp=0;
	temp=head;
	cout<<"\n\nElements in the Linked List: ";
	while(temp!=0){
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
}

int main(){
	for(int i=0;i<5;i++){
		insert();
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
