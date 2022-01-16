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
void reverse(){
	struct node *currnode,*nextnode;
	currnode=head;
	while(currnode!=0){
		nextnode=currnode->next;
		currnode->next=currnode->prev;
		currnode->prev=nextnode;
		currnode=nextnode;		
	}
	currnode=head;
	head=tail;
	tail=currnode;
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
	reverse();
	display();
}
