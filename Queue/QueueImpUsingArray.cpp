#include<iostream>
#define N 10
using namespace std;
int front=-1;
int rear=-1;
int queue[N];

void enqueue(int x){
	if(rear==N-1)
	cout<<"Overflow"<<endl;
	else if(rear==-1 && front==-1){
		rear=front=0;
		queue[rear]=x;
	}
	else{
		rear++;
		queue[rear]=x;
	}
}

void dequeue(){
	if(rear==-1 && front==1){
		cout<<"Underflow"<<endl;
	}
	else if(front==rear){
		front=rear=-1;
	}
	else{
		front++;
	}
}

void peek(){
	if(rear==-1 && front==1){
		cout<<"Underflow"<<endl;
	}
	else{
		cout<<"Peek Element in the Queue: "<<queue[front]<<endl;;
	}
}

void display(){
	if(rear==-1 && front==1){
		cout<<"Queue is empty"<<endl;
	}
	else{
		cout<<"Elements in the Queue: ";
		for(int i=front;i<rear+1;i++){
			cout<<queue[i]<<"  ";
		}
		cout<<endl;
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
