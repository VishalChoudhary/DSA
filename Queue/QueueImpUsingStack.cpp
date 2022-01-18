#include<iostream>
using namespace std;
#define N 10
int top1=-1,top2=-1;
int count=0;
int s1[N],s2[2];

void push1(int data){
	if(top1==N-1)
	cout<<"Overflow Condition"<<endl;
	else{
		top1++;
		s1[top1]=data;
	}
}

void enqueue(int x){
	push1(x);
	count++;
}

void push2(int data){
	if(top2==N-1)
	cout<<"Overflow Condition"<<endl;
	else{
		top2++;
		s2[top2]=data;
	}
}

int pop1(){
	return s1[top1--];
}

int pop2(){
	return s2[top2--];
}

void dequeue(){
	int i,a,b;
	for(int i=0;i<count;i++){
		a=pop1();
		push2(a);
	}
	b=pop2();
	count--;
	for(int i=0;i<count;i++){
		a=pop2();
		push1(a);
	}
}

void display(){
	cout<<"Elements in the Queue: ";
	for(int i=0;i<=top1;i++){
		cout<<s1[i]<<"  ";
	}
}

int main(){
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	enqueue(6);
	enqueue(7);
	dequeue();
	dequeue();
	display();
}
