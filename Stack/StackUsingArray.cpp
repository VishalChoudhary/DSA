#include<iostream>
using namespace std;
#define N 5
int stack[N];
int top=-1;
void push(){
	int x;
	cout<<"Enter the element: ";
	cin>>x;
	if(top==(N-1)){
		cout<<"\nStack overflow";
	}
	else{
		top++;
		stack[top]=x;
	}
}
void pop(){
	int item;
	if(top==-1){
		cout<<"\nStack Underflow";
	}
	else{
		item=stack[top];
		top--;
		cout<<"\nDeleted item from the stack is: "<<item<<endl;
	}
}
void peek(){
	if(top==-1){
		cout<<"Stack Underflow";
	}
	else{
		cout<<"\nElement at the top of the stack: "<<stack[top]<<endl;
	}
}
void display(){
	int i;
	cout<<"\nElements in the stack: ";
	for(i=top;i>=0;i--){
		cout<<stack[i]<<"  ";
	}
}
int main(){
	for(int i=0;i<5;i++){
		push();
	}
	pop();
	peek();
	display();
}
