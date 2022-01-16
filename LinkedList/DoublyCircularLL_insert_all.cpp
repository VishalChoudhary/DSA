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

void insert_beg(){
	struct node *newnode=0;
	newnode=(struct node *)malloc(sizeof(struct node));
	cout<<"\nEnter the data: ";
	newnode->next=newnode->prev=0;
    cin>>newnode->data;
    newnode->next=head;
    newnode->prev=tail;
    head->prev=newnode;
    tail->next=newnode;
    head=newnode;
}

void insert_end(){
	struct node *newnode=0;
	newnode=(struct node *)malloc(sizeof(struct node));
	cout<<"\nEnter the data: ";
	newnode->next=newnode->prev=0;
    cin>>newnode->data;
    tail->next=newnode;
    newnode->prev=tail;
    newnode->next=head;
    head->prev=newnode;
    tail=newnode;
}

void insert_pos(){
  struct node *newnode=0, *temp=0;
  int i=1,pos=0;
  cout<<"Enter the position: ";
  cin>>pos;
  if(pos<0)
    cout << "Invalid posistion";
  else if (pos==1) {
    insert_beg();
  } else{
    newnode=(struct node * )malloc(sizeof(struct node));
    cout<<"\nEnter the elements at the given position: ";
    cin>>newnode->data;
    newnode->next=0;
    temp=head;
    while (i<pos-1) {
      temp=temp->next;
      i++;
    }
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next=newnode;
    temp->next->prev=newnode;
    temp=newnode;
  }
}

void display(){
	struct node *temp=0;
	temp=head;
	cout<<"\n\nElements in the circular linked list: ";
	while(temp!=tail){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<temp->data;
}

int main() {
  for(int i=0;i<5;i++){
    createDCLL();
  }
  int x;
  cout << "\nEnter your choice: \n1.Insert at begining of the Doubly linked list \n2.Insert the end of the Doubly linked list\n3.Insert at the given position\n\n";
  cin >> x;
  switch (x){
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
    default:
        cout << "Invalid Option";
  }
}
