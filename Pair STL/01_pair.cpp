#include<bits/stdc++.h>
using namespace std;

int main(){
    pair<int,string>p;          //declaration of pair
    p=make_pair(1,"abc");       //1st way of input pair
    //p={2,"cd"};                 2nd way of input pair
    cout<<p.first<<" "<<p.second<<endl;

    //passing p value in reference
    pair<int,string> &p1=p;
    p1.first=3;
    cout<<p.first<<endl;

    //pair of array
    pair<int,int> p_array[3];
    int a[]={1,2,3};
    int b[]={4,5,6};
    p_array[0]={1,4};
    p_array[1]={2,5};
    p_array[2]={3,6};
    swap(p_array[0],p_array[2]);
    for(int i=0;i<3;i++){
        cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
    }

    return 0;
}
