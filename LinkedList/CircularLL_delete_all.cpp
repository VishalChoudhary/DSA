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
}

void del_beg(){
	struct node *temp=0;
	temp=head;
	if(head==0){
		cout<<"list is empty";
	}
	else if(temp==tail){
		head=tail=0;
		free(temp);
	}
	else{
		temp=head;
	    head=head->next;
    	tail->next=head;
    	free(temp);
	}
}

void del_end(){
	struct node *temp=0,*prev=0;
	temp=head;
	if(head==0){
		cout<<"list is empty";
	}
	else if(temp==tail){
		head=tail=0;
		free(temp);
		cout<<"successfully terminated";
	}
	while(temp->next!=tail->next){
		prev=temp;
		temp=temp->next;
	}
	prev->next=tail->next;
	tail=prev;
	free(temp);
}

void del_pos(){
	struct node *temp=0,*nextnode=0;
	int i=1,pos=0;
	cout<<"\nEnter the position: ";
	cin>>pos;
	temp=head;
	if(pos<0)
	cout<<"list is empty";
	else if(pos==1)
	del_beg();
	else{
		while(i<pos-1){
			temp=temp->next;
			i++;
		}
		nextnode=temp->next;
		temp->next=nextnode->next;
		free(nextnode);
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
	for(int i=0;i<5;i++){
		create();
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
