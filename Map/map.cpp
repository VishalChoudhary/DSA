#include<iostream>
using namespace std;
#include <map>

int main(){
    map<int,string> m;
    
    m[1]="vishal";
    m[2]="shiver";
    m[13]="bablu";

    m.insert({5,"bheem"});

    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"finding : "<<m.count(13);

    auto it=m.find(5);

    for(auto i=it;i!=m.end();i++) {
        cout<<(*i).first<<endl;
    }



}