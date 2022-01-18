#include<iostream>
using namespace std;
#define N 10
int queue[N];
int front=-1;
int rear=-1;

void enqueue(int x){
	if(rear==-1 && front==-1){
		rear=front=0;
		queue[rear]=x;
	}
	else if((rear+1)%N==front){
		cout<<"Queue is full"<<endl;
	}
	else{
		rear=(rear+1)%N;
		queue[rear]=x;
	}
}

void dequeue(){
	if(rear==-1 && front==-1){
		cout<<"Queue is empty"<<endl;
	}
	else if(rear==front){
		rear=front=-1;
	}
	else{
		front=(front+1)%N;
	}
}

void peek(){
	if(rear==-1 && front==-1){
		cout<<"Queue is empty"<<endl;
	}
	cout<<"\nPeek element in the Queue: "<<queue[front];
}

void display(){
	if(rear==-1 && front==-1){
		cout<<"Queue is empty"<<endl;
	}
	else{
		int i=front;
		cout<<"\nElements in the Queue: ";
		while(i!=rear){
			cout<<queue[i]<<"  ";
			i=(i+1)%N;
		}
		cout<<queue[rear];
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
