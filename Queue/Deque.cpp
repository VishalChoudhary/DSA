#include<iostream>
using namespace std;
#define N 10
int r=-1,f=-1;
int deque[N];

void enqueuefront(int x){
	if(f==0 && r==N-1 || f==(r+1))
	cout<<"Deque is full"<<endl;
	else if(f==-1 && r==-1){
		f=r=0;
		deque[f]=x;
	}
	else if(f==0){
		f=N-1;
		deque[f]=x;		
	}
	else{
		f--;
		deque[f]=x;
	}
}

void enqueuerear(int x){
	if(f==0 && r==N-1 || f==(r+1))
	cout<<"Deque is full"<<endl;
	else if(f==-1 && r==-1){
		f=r=0;
		deque[r]=x;
	}
	else if(r==(N-1)){
		r=0;
		deque[r]=x;
	}
	else{
		r++;
		deque[r]=x;
	}
}

void deququefront(){
	if(r==-1 && f==-1)
	cout<<"Deque is empty"<<endl;
	else if(r==f){
		r=f=-1;
	}
	else if(f==N-1){
		f=0;
	}
	else{
		f++;
	}
}

void deququerear(){
	if(r==-1 && f==-1)
	cout<<"Deque is empty"<<endl;
	else if(r==f){
		r=f=-1;
	}
	else if(r==0){
		r=N-1;
	}
	else{
		r--;
	}
}

void display(){
	int i=f;
	cout<<"\n\nElements in the double ended queue: ";
	while(i!=r){
		cout<<deque[i]<<"  ";
		i=(i+1)%N;
	}
	cout<<deque[r];
}


int main(){
	enqueuefront(2);
	enqueuefront(5);
	enqueuerear(-1);
	enqueuerear(0);
	enqueuefront(7);
	deququefront();
	deququerear();
	display();
}
