#include<bits/stdc++.h>
using namespace std;

int main(){

    //initializing vector of pair
    vector<pair<int,int>> vec={
      {1,2},{3,4},{5,6}  
    };
    //pushing element in vector in pair
    vec.push_back(make_pair(7,8));
    vec.emplace_back(9,10);
    for(int i=0;i<vec.size();i++){
        cout<<"("<<vec[i].first<<","<<vec[i].second<<")"<<endl;
    }
    return 0;
}