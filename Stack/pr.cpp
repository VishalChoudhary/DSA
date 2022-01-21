#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cout<<"Enter the size: ";
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<"Enter the k-th element: ";
	cin>>k;
	sort(v.begin(),v.end());
	cout<<"Elements: ";
	for(int i=0;i<n;i++){
		cout<<v[i]<<"  ";
	}
	cout<<"\nk-th largest element: "<<v[k-1];
	return 0;
}
