#include<iostream>
using namespace std;
#include<malloc.h>

struct node {
  int data;
  struct node * next;
  struct node * prev;
};
struct node * head = 0, * tail = 0;
void create() {
  struct node * newnode = 0;
  newnode = (struct node * ) malloc(sizeof(struct node));
  cout << "Enter the data: ";
  cin >> newnode -> data;
  newnode -> next = 0;
  newnode -> prev = 0;
  if (head == 0) {
    head = tail = newnode;
  } else {
    tail -> next = newnode;
    newnode -> prev = tail;
    tail = newnode;
  }
}

void del_beg(){
	struct node *temp=0;
	if(head==0)
	cout<<"List is empty";
	else{
		temp=head;
		head=head->next;
		head->prev=0;
		free(temp);
	}
}

void del_end(){
	struct node *temp=0;
	if(tail==0){
		cout<<"List is empty";
	}
	else{
		temp=tail;
		tail->prev->next=0;
		tail=tail->prev;
		free(temp);
	}
}

void del_pos(){
	struct node *temp=0;
	int i=1,pos=0;
	cout<<"\nEnter the position: ";
	cin>>pos;
	temp=head;
	while(i<pos){
		temp=temp->next;
		i++;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	free(temp);
}

void display() {
  struct node * temp = 0;
  temp = head;
  cout << "\n\nElements in the Doubly Linked List: ";
  while (temp != 0) {
    cout << temp -> data << "  ";
    temp = temp -> next;
  }
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
